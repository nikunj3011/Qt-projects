#ifndef MainWindow_H
#define MainWindow_H

#include <Model/card.h>
#include <Model/deck.h>
#include <QMainWindow>
#include <vector>
#include <memory>
#include <QPushButton>
#include "Model/game.h"
#include <QLabel>


namespace Ui {
class MainWindow;
}

class CardButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onCardClick();

    void onNewGameClick();

//methods
private:

    void drawView();
//members
private:
    Ui::MainWindow *ui;

    std::unique_ptr<Deck> deck;

    QLabel* scoreLabel;

    std::vector<CardButton*> cardDisplayBtns;

    Game *game;


};

#endif // MainWindow_H
