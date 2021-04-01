#include "Model/mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QProcess>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    start=1;
}

void MainWindow::on_restart_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

char MainWindow::checkwin()
{
    win = '\0';
    for(int i=0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1]==board[i][2] && board[i][1] != '\0')
        {
            win = board[i][1];
            break;
        }
        if(board[0][i] == board[1][i] && board[1][i]==board[2][i] && board[1][i] != '\0')
        {
            win = board[1][i];
            break;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1]==board[2][2] && board[1][1] != '\0')
        win = board[1][1];
    if(board[0][2] == board[1][1] && board[1][1]==board[2][0] && board[1][1] != '\0')
        win = board[1][1];
    return win;
}

int MainWindow::cpmove(char player1, char player2)
{

    int bms = -99;
    int ro = -99;
    int cl = -99;
    int scor = 0;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (board[r][c] == '\0')
            {
                board[r][c] = player1;
                scor = -(chmv(player2, player1));
                board[r][c] = '\0';
                if (scor >= bms)
                {
                    bms = scor;
                    ro = r;
                    cl = c;
                }
            }
        }
    }
    return (10*ro + cl);
}

int MainWindow::chmv(char player1, char player2)
{

    int bms = -99;
    int scor = 0;

    if (checkwin() == player1)
        return 1000;

    else if (checkwin() == player2)
        return -1000;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (board[r][c] == '\0')
            {
                board[r][c] = player1;
                scor = -(chmv(player2, player1));
                board[r][c] = '\0';
                if (scor >= bms)
                    bms = scor;
            }
        }
    }

    if (bms == -9999 || bms == 0)
        return 0;

    else if (bms < 0)
        return bms + 1;

    else if (bms > 0)
        return bms - 1;
}



void MainWindow:: Move()
{
    win = '\0';
    for(int i=0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1]==board[i][2] && board[i][1] != '\0')
        {
            win = board[i][1];
            break;
        }
        if(board[0][i] == board[1][i] && board[1][i]==board[2][i] && board[1][i] != '\0')
        {
            win = board[1][i];
            break;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1]==board[2][2] && board[1][1] != '\0')
        win = board[1][1];
    if(board[0][2] == board[1][1] && board[1][1]==board[2][0] && board[1][1] != '\0')
        win = board[1][1];

    if(win=='X')
    {
        start=0;
        ui->won->setText("You Won");
        //winners[cont++]=players[1];
        return;
    }
    if(win=='O')
    {
        start=0;
        ui->won->setText("PC Wins");
        return;
    }
    chanc++;
    if(chanc == 9)
    {
        ui->won->setText("Game draw");
        chanc=0;
        start=0;

        return;
    }



    if(player==1)
        player=2;
    else
        player=1;

    if(player == 2)
    {
        int mv = cpmove('O' , 'X');
        int ro = mv / 10;
        int cl = mv % 10;
        board[ro][cl] = 'O';
        switch(mv)
        {
            case 00:
                ui->btn1->setText("O");
                break;
            case 01:
                ui->btn2->setText("O");
                break;
            case 02:
                ui->btn3->setText("O");
                break;
            case 10:
                ui->btn4->setText("O");
                break;
            case 11:
                ui->btn5->setText("O");
                break;
            case 12:
                ui->btn6->setText("O");
                break;
            case 20:
                ui->btn7->setText("O");
                break;
            case 21:
                ui->btn8->setText("O");
                break;
            case 22:
                ui->btn9->setText("O");
                break;
        }
       // player=1;
        Move();

    }
}

void MainWindow::on_btn1_clicked()
{
    if(ui->btn1->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->btn1->setText("X");
            board[0][0] = 'X';
            Move();
        }
        else
        {
            ui->btn1->setText("O");
            board[0][0] = 'O';
            Move();
        }
    }
}

void MainWindow::on_btn2_clicked()
{
    if(ui->btn2->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->btn2->setText("X");
            board[0][1] = 'X';
            Move();
        }
        else
        {
            ui->btn2->setText("O");
            board[0][1] = 'O';
            Move();
        }
    }
}

void MainWindow::on_btn3_clicked()
{
    if(ui->btn3->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->btn3->setText("X");
            board[0][2] = 'X';
            Move();
        }
        else
        {
            ui->btn3->setText("O");
            board[0][2] = 'O';
            Move();
        }
    }
}

void MainWindow::on_btn4_clicked()
{
    if(ui->btn4->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->btn4->setText("X");
            board[1][0] = 'X';
            Move();
        }
        else
        {
            ui->btn4->setText("O");
            board[1][0] = 'O';
            Move();
        }
    }
}

void MainWindow::on_btn5_clicked()
{
    if(ui->btn5->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->btn5->setText("X");
            board[1][1] = 'X';
            Move();
        }
        else
        {
            ui->btn5->setText("O");
            board[1][1] = 'O';
            Move();
        }
    }
}

void MainWindow::on_btn6_clicked()
{
    if(ui->btn6->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->btn6->setText("X");
            board[1][2] = 'X';
            Move();
        }
        else
        {
            ui->btn6->setText("O");
            board[1][2] = 'O';
            Move();
        }
    }
}

void MainWindow::on_btn7_clicked()
{
    if(ui->btn7->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->btn7->setText("X");
            board[2][0] = 'X';
            Move();
        }
        else
        {
            ui->btn7->setText("O");
            board[2][0] = 'O';
            Move();
        }
    }
}

void MainWindow::on_btn8_clicked()
{
    if(ui->btn8->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->btn8->setText("X");
            board[2][1] = 'X';
            Move();
        }
        else
        {
            ui->btn8->setText("O");
            board[2][1] = 'O';
            Move();
        }
    }
}

void MainWindow::on_btn9_clicked()
{
    if(ui->btn9->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->btn9->setText("X");
            board[2][2] = 'X';
            Move();
        }
        else
        {
            ui->btn9->setText("O");
            board[2][2] = 'O';
            Move();
        }
    }
}
