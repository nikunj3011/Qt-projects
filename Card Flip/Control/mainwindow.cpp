//Nikunj Rathod
#include "Control/mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QFont>
#include <View/cardbutton.h>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(0));
    ui->setupUi(this);

    deck = std::unique_ptr<Deck>(new Deck);
    deck->shuffle();


    game = new Game();

    //vertical layout
    auto vlmain = new QVBoxLayout(ui->centralwidget);

    //horizontal layout
    auto cardsLayout = new QGridLayout();
    vlmain->addLayout(cardsLayout);

    auto shuffleLayout = new QHBoxLayout();
    vlmain->addLayout(shuffleLayout);

    QFont font;
    font.setPixelSize(40);

    //create buttons
    for(int i=0;i<32;i++)
    {
        auto* btn = new CardButton(i);

        game->setCardAtN(deck->drawCard());
        btn->setFont(font);
        btn->setMinimumSize(QSize(128,192));
        btn->setMaximumSize(QSize(128,192));
        btn->setText("");
        btn->setStyleSheet("border-image:url(:/Media/Media/cardback.png)");

        cardsLayout->addWidget(btn,i%4,i/4);
        connect(btn, &CardButton::clicked, this, &MainWindow::onCardClick);
        cardDisplayBtns.push_back(btn);

    }

    ui->centralwidget->setStyleSheet(QStringLiteral("background-color:green"));

    // shuffle
   auto* newGameButton = new QPushButton();
   shuffleLayout->addWidget(newGameButton);
   newGameButton->setText("Shuffle");
   newGameButton->setMinimumSize(QSize(150,20));
   newGameButton->setMaximumSize(QSize(150,20));
   newGameButton->setStyleSheet(QStringLiteral("background-color:white"));

    connect(newGameButton, &QPushButton::clicked, this, &MainWindow::onNewGameClick);

    scoreLabel = new QLabel();
    shuffleLayout->addWidget(scoreLabel);
    scoreLabel->setMaximumWidth(150);
    scoreLabel->setText("SCORE:  0");
    scoreLabel->setStyleSheet(QStringLiteral("color:white"));

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCardClick(){

    CardButton* btn = dynamic_cast<CardButton*>(sender());

    game->selectCardN(btn->getIndex());

    scoreLabel->setText("SCORE:  " + QString::number(game->getScore()));

    drawView();
}


void MainWindow::onNewGameClick(){


    deck = std::unique_ptr<Deck>(new Deck);
    deck->shuffle();
    game = new Game();

    for (int i = 0 ; i<32;i++){

        game->setCardAtN(deck->drawCard());
    }

    scoreLabel->setText("SCORE:  0");
    drawView();

}

void MainWindow::drawView(){


    for(auto c : cardDisplayBtns)
    {
        CardPtr card = game->getCardN(c->getIndex());

        if(card->isMatched())
        {
            if(card->getColor()== CardColor::Red){
               c->setStyleSheet("border-image:url(:/Media/Media/cardfrontGray.png); "
                                             "color: red;");
            }
            else{
               c->setStyleSheet("border-image:url(:/Media/Media/cardfrontGray.png); "
                                             "color: black;");
            }

            c->setText(QString::fromStdString(card->toString()));

        }else
        {
            if(card->isFlipped())
            {
                if(card->getColor()== CardColor::Red){
                   c->setStyleSheet("border-image:url(:/Media/Media/cardfront.png); "
                                                 "color: red;");
                }
                else{
                   c->setStyleSheet("border-image:url(:/Media/Media/cardfront.png); "
                                                 "color: black;");
                }

                c->setText(QString::fromStdString(card->toString()));

            }
            else
            {
                c->setStyleSheet("border-image:url(:/Media/Media/cardback.png);");
                c->setText("");

            }
        }
    }
}
