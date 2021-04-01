//Nikunj Rathod
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include"Model/Card.h"
#include"Model/Deck.h"
#include"Model/Game.h"
#include"Model/Hand.h"
#include"Model/VideoPoker.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    ui->setupUi(this);

    deck = std::unique_ptr<Deck>(new Deck);
    deck->shuffle();
    game = new Game();
    auto vlmain = new QVBoxLayout(ui->centralwidget);

    //horizontal layout
    auto cardsLayout = new QGridLayout();
    vlmain->addLayout(cardsLayout);

    auto shuffleLayout = new QHBoxLayout();
    vlmain->addLayout(shuffleLayout);

    QFont font;
    font.setPixelSize(40);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Draw_clicked()
{


}
