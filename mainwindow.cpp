#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include "handler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc = new myScene;
    this->ui->graphicsView->setScene(sc);
    connect(this->ui->btn_start,SIGNAL(clicked(bool)),sc,SLOT(startGame()));
    connect(this->ui->btn_pause,SIGNAL(clicked(bool)),sc,SLOT(pauseGame()));
    connect(this->ui->btn_stop,SIGNAL(clicked(bool)),sc,SLOT(stopGame()));
    this->score = 0;
    handler *hand = handler::getInstance();
    connect(hand,SIGNAL(beatMouse()),this,SLOT(UpdateScore()));
}

MainWindow::~MainWindow()
{
    delete sc;
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this,"Are you sure exit the game!","The window will be close!","Yes","No");
    if(ret == 1)
    {
        event->ignore();
    }
}

void MainWindow::UpdateScore()
{
    this->score += 10;
    this->ui->lcdNumber->display(this->score);
}
