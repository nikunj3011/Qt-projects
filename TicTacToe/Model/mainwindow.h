#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int start=0;
    char board[3][3]={'\0'};
    char win = '\0';
    int player=1;
    int chanc=0;

private slots:
    void Move();

    char checkwin();

    int cpmove(char player1, char player2);

    int chmv(char player1, char player2);

    void on_start_clicked();

    void on_restart_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
