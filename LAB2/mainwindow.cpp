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
    QListWidgetItem *st_w = new QListWidgetItem("Stopwatch №" + QString::number(++count_stopwatches));
    ui->stopwatch_list->addItem(st_w);
    stop_watch->show();

}

void MainWindow::on_open_alarm_button_clicked()
{
    a_clock = new alarm_clock;
    alarm_clock_vector.push_back(a_clock);
    QListWidgetItem *clock = new QListWidgetItem("Alarm Clock №" + QString::number(++count_stopwatches));
    ui->alarm_list->addItem(clock);
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
   int current = ui->stopwatch_list->currentRow();
   delete ui->stopwatch_list->currentItem();//delete element from list
   stopwatch*w = stopwatch_vector[current];
   delete w;//delete window
   QVector<stopwatch*>::Iterator it = stopwatch_vector.begin();//delete element from vector
   it = it+current;
   stopwatch_vector.erase(it);
   count_stopwatches--;
   //QModelIndex i = ui->stopwatch_list->currentIndex();//other variant of taking index of element in list
   //int a = i.row();
    for(int i = 0; i < count_stopwatches;i++)//changing names of stopwatches
    {
        int number = i;
        ui->stopwatch_list->item(i)->setText("Stopwatch №" + QString::number(++number));
    }

}

void MainWindow::on_show_stopwatch_button_clicked()
{
    int current = ui->stopwatch_list->currentRow();
    stopwatch*window = stopwatch_vector[current];
    if(!window->isVisible())
    {
        window->setVisible(true);
    }
}

void MainWindow::on_delete_alarm_button_clicked()
{
    int current = ui->alarm_list->currentRow();
    delete ui->alarm_list->currentItem();//delete element from list
    alarm_clock*w = alarm_clock_vector[current];
    delete w;//delete window
    QVector<alarm_clock*>::Iterator it = alarm_clock_vector.begin();//delete element from vector
    it = it+current;
    alarm_clock_vector.erase(it);
    count_alarm_clocks--;
    //QModelIndex i = ui->stopwatch_list->currentIndex();//other variant of taking index of element in list
    //int a = i.row();
     for(int i = 0; i < count_alarm_clocks;i++)//changing names of stopwatches
     {
         int number = i;
         ui->alarm_list->item(i)->setText("Stopwatch №" + QString::number(++number));
     }
}

void MainWindow::on_show_alarm_button_clicked()
{
    int current = ui->alarm_list->currentRow();
    alarm_clock*window = alarm_clock_vector[current];
    if(!window->isVisible())
    {
        window->setVisible(true);
    }
}
