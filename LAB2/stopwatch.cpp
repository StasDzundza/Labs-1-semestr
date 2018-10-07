#include "stopwatch.h"
#include "ui_stopwatch.h"

stopwatch::stopwatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stopwatch)
{
    ui->setupUi(this);
    running = false;
    timer.setInterval(20);
    connect(&timer,SIGNAL(timeout()),this,SLOT(onTimer()));
}

stopwatch::~stopwatch()
{
    delete ui;
}

void stopwatch::onTimer()
{
    int ms = time_left.msecsSinceStartOfDay() + QTime::currentTime().msecsSinceStartOfDay() - last_start.msecsSinceStartOfDay();
    ui->time_text->setText(QTime::fromMSecsSinceStartOfDay(ms).toString("mm:ss:zzz"));
}

void stopwatch::on_start_stop_clicked()
{
    if(timer.isActive())
    {
        timer.stop();
        time_left = QTime::fromMSecsSinceStartOfDay(time_left.msecsSinceStartOfDay()+QTime::currentTime().msecsSinceStartOfDay()- last_start.msecsSinceStartOfDay());
        ui->start_stop->setText("Start");
        ui->time_text->setStyleSheet("color:black");
    }
    else
    {
        last_start = QTime::currentTime();
        timer.start();
        ui->start_stop->setText("Stop");
        ui->time_text->setStyleSheet("color:red");
    }
}

void stopwatch::on_Reset_clicked()
{
    timer.stop();
    ui->start_stop->setText("Start");
    ui->time_text->setText("00:00:000");
    ui->time_text->setStyleSheet("color:black");
    time_left = QTime::fromMSecsSinceStartOfDay(0);
}
void stopwatch::on_hide_button_clicked()
{
    this->setVisible(!this->isVisible());
}
