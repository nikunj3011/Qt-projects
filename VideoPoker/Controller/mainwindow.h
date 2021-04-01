#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"Model/Card.h"
#include"Model/Deck.h"
#include"Model/Game.h"
#include"Model/Hand.h"
#include"Model/VideoPoker.h"
#include <QLabel>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Draw_clicked();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<Deck> deck;

    QLabel* scoreLabel;

    Game *game;
};
#endif // MAINWINDOW_H
