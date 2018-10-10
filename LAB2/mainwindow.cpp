#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"stopwatch.h"
#include<QString>
#include<QApplication>
#include<QListWidget>
#include<QListWidgetItem>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("LAB2");
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
    stopwatch *stop_watch = new stopwatch;
    stopwatch_vector.push_back(stop_watch);
    QListWidgetItem *st_w = new QListWidgetItem("Timer № " + QString::number(++count_stopwatches));
    ui->stopwatch_list->addItem(st_w);
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

void MainWindow::on_delete_stopwatch_button_clicked()
{
   int a = ui->stopwatch_list->currentRow();
   delete ui->stopwatch_list->currentItem();//delete element from list
   stopwatch*w = stopwatch_vector[a];
   delete w;//delete window
   QVector<stopwatch*>::Iterator it = stopwatch_vector.begin();//delete element from vector
   it = it+a;
   stopwatch_vector.erase(it);
   count_stopwatches--;
   //QModelIndex i = ui->stopwatch_list->currentIndex();
   //int a = i.row();
   qDebug()<<a;

}
