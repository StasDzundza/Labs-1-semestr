#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"stopwatch.h"
#include<QString>
#include<QApplication>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    current_date = QDate::currentDate();
    ui->date_text->setText(current_date.toString("dd/MM/yy"));//set current date on main window
    connect(&current_time,SIGNAL(timeout()),this,SLOT(change_time()));
    current_time.start(1000);//every second we chande time on main window
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_time()
{

    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if(time.second()%2 == 0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui->time_text->setText(time_text);

}
void MainWindow::on_open_stopwatch_button_clicked()
{
    stop_watch = new stopwatch;
    stop_watch->show();

}

void MainWindow::on_open_alarm_button_clicked()
{
    a_clock = new alarm_clock;
    a_clock->show();
}

void MainWindow::on_open_timer_button_clicked()
{
    Timer = new timer_widget;
    Timer->show();
}

void MainWindow::on_exit_button_clicked()
{
    QApplication::quit();
}
