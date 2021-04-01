#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../Model/hangmanclass.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <map>
#include <QMessageBox>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _imageFor({ {Picture::ONE, "border-image:url(:/route/Media/images/gallows0.png)"}, // all the pictures and URLS
    {Picture::TWO, "border-image:url(:/route/Media/images/gallows1.png)"},
    {Picture::THREE, "border-image:url(:/route/Media/images/gallows2.png)"},
    {Picture::FOUR, "border-image:url(:/route/Media/images/gallows3.png)"},
    {Picture::FIVE, "border-image:url(:/route/Media/images/gallows4.png)"},
    {Picture::SIX, "border-image:url(:/route/Media/images/gallows5.png)"},
    {Picture::SEVEN,"border-image:url(:/route/Media/images/gallows6.png)"}})

{
    ui->setupUi(this);
    _game = std::unique_ptr<hangmanClass>(new hangmanClass());

    auto vlMain = new QVBoxLayout(ui->centralWidget);
    auto hlTop = new QHBoxLayout();
    auto glLetters = new QGridLayout();
    auto hlPhrase = new QHBoxLayout();
    auto hlNewBtn = new QHBoxLayout();

    lblPicture = new QLabel();
    lblPicture->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    lblPicture->setMaximumSize(300,400);
    lblPicture->setMinimumSize(300,400);

    for(char c= 'a'; c <= 'z'; ++c)
    {
        auto btn = new QPushButton();
        btn->setMaximumSize(25,25);
        btn->setMaximumSize(25,25);
        btn->setText(QString(c));

        int idx = c - 'a';

        glLetters->addWidget(btn, idx / 6, idx % 6);

        connect(btn, &QPushButton::clicked, this, &MainWindow::onLetterClicked);
        letters.push_back(btn);
    }

    hlTop->addWidget(lblPicture);

    QSpacerItem *spacer = new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Fixed);
    hlTop->addSpacerItem(spacer);

    hlTop->addLayout(glLetters);

    vlMain->addLayout(hlTop);

    QSpacerItem *spacer1 = new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Fixed);

    lblPhrase = new QLabel;
    lblPhrase->setMaximumSize(400,25);
    lblPhrase->setMinimumSize(400,25);
    lblPhrase->setFrameStyle(QFrame::NoFrame);

    hlPhrase->addWidget(lblPhrase);
    hlPhrase->addSpacerItem(spacer1);

    vlMain->addLayout(hlPhrase);

    QSpacerItem *spacer2 = new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Fixed);

    auto btnNewPhrase= new QPushButton();
    btnNewPhrase->setMaximumSize(100,25);
    btnNewPhrase->setMaximumSize(100,25);
    btnNewPhrase->setText(QString("New Phrase"));


    hlNewBtn->addSpacerItem(spacer2);
    hlNewBtn->addWidget(btnNewPhrase);

    connect(btnNewPhrase, &QPushButton::clicked, this, &MainWindow::onNewPhraseClicked);

    vlMain->addLayout(hlNewBtn);

    _game->loadPhrases();
    _game->shufflePhrases();

    QString dashWord = QString::fromStdString(_game->newPhrase());

    lblPhrase->setText(dashWord);

    draw();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw()
{
    QString dashWord = QString::fromStdString(_game->showHiddenPhrase());

    lblPhrase->setText(dashWord);

    lblPicture->setStyleSheet(_imageFor.at(_game->showGallows()));

    // redraw letters
     for (auto btn : letters)
     {
         QString letter = btn->text();
         std::string guess = letter.toLocal8Bit().constData();
         if(_game->letterGuessed(guess))
         {
             btn->setEnabled(false);
         }
         else
            btn->setEnabled(true);
     }
     static bool windowHasBeenShown = false;
     if(_game->won() && !windowHasBeenShown)
     {
         windowHasBeenShown = true;
         lblPicture->setStyleSheet("background-image: url(:/route/Media/images/gallowsWon.png);"
                                   "background-repeat:no repeat;");
     }
     if(!_game->won())
     {
         windowHasBeenShown = false;
     }

     if(_game->lost())
     {
         QString word = QString::fromStdString(_game->showPhrase());

         lblPhrase->setText(word);
         lblPicture->setStyleSheet("background-image: url(:/route/Media/images/gallowsLost.png);"
                                    "background-repeat:no repeat;");
     }
}

void MainWindow::onLetterClicked()
{
    QPushButton* btn = dynamic_cast<QPushButton*>(sender());
    btn->setEnabled(false);

    QString letter = btn->text();
    std::string guess = letter.toLocal8Bit().constData();
    _game->processGuess(guess);
    draw();
}

void MainWindow::onNewPhraseClicked()
{
    _game->initGame();
    _game->shufflePhrases();
    _game->newPhrase();
    draw();
}


