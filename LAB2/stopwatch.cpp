#include "stopwatch.h"
#include "ui_stopwatch.h"

stopwatch::stopwatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stopwatch)
{
    ui->setupUi(this);
    running = false;
    timer.setInterval(20);//start always will be start(20)
    connect(&timer,SIGNAL(timeout()),this,SLOT(onTimer()));
}

stopwatch::~stopwatch()
{
    delete ui;
}

void stopwatch::onTimer()
{
    //we finding current time on stopwatch
    int ms = time_on_stopwatch.msecsSinceStartOfDay() + QTime::currentTime().msecsSinceStartOfDay() - last_start.msecsSinceStartOfDay();
    ui->time_text->setText(QTime::fromMSecsSinceStartOfDay(ms).toString("mm:ss:zzz"));
}

void stopwatch::on_start_stop_clicked()
{
    if(timer.isActive())
    {
        timer.stop();
        time_on_stopwatch = QTime::fromMSecsSinceStartOfDay(time_on_stopwatch.msecsSinceStartOfDay()+QTime::currentTime().msecsSinceStartOfDay()- last_start.msecsSinceStartOfDay());
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
    time_on_stopwatch = QTime::fromMSecsSinceStartOfDay(0);
    ui->lap_results->clear();
}
void stopwatch::on_hide_button_clicked()
{
    this->setVisible(!this->isVisible());
}

void stopwatch::on_lap_button_clicked()
{
    count_laps++;
    QTime current_lap_time = QTime::fromMSecsSinceStartOfDay(time_on_stopwatch.msecsSinceStartOfDay()+QTime::currentTime().msecsSinceStartOfDay()- last_start.msecsSinceStartOfDay());
    int last_lap_time = current_lap_time.msecsSinceStartOfDay() - last_lap.msecsSinceStartOfDay();
    ui->lap_results->append(QString::number(count_laps) + "<b>)</b> "+current_lap_time.toString("mm:ss:zzz") + "    "
    "      + "+QTime::fromMSecsSinceStartOfDay(last_lap_time).toString("mm:ss:zzz") +"\n");
    last_lap = current_lap_time;
}
