#include "stopwatch.h"
#include "ui_stopwatch.h"

int stopwatch::index = 1;
stopwatch::stopwatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stopwatch)
{
    ui->setupUi(this);
    id = index;
    index++;
    this->setWindowTitle("Stopwatch");
    running = false;
    timer.setInterval(20);//start always will be start(20)
    connect(&timer,SIGNAL(timeout()),this,SLOT(onTimer()));
}

stopwatch::~stopwatch()
{
    timer.stop();
    delete ui;
}

int stopwatch::get_id()
{
    return id;
}

void stopwatch::onTimer()
{
    //we finding current time on stopwatch
    int ms = time_on_stopwatch.msecsSinceStartOfDay() + QTime::currentTime().msecsSinceStartOfDay() - last_start.msecsSinceStartOfDay();
    ui->time_text->setText(QTime::fromMSecsSinceStartOfDay(ms).toString("mm:ss:zzz"));
    emit current_time_signal(QTime::fromMSecsSinceStartOfDay(ms).toString("mm:ss:zzz"),this);
}

void stopwatch::on_start_stop_clicked()
{
    if(timer.isActive())
    {
        timer.stop();
        time_on_stopwatch = QTime::fromMSecsSinceStartOfDay(time_on_stopwatch.msecsSinceStartOfDay()+QTime::currentTime().msecsSinceStartOfDay()- last_start.msecsSinceStartOfDay());
        ui->start_stop->setText("Start");
        ui->time_text->setStyleSheet("color:black");
        ui->start_stop->setStyleSheet("background-color:#89ff0b");
    }
    else
    {
        last_start = QTime::currentTime();
        timer.start();
        ui->start_stop->setText("Stop");
        ui->time_text->setStyleSheet("color:red");
        ui->start_stop->setStyleSheet("background-color:#ff2b1c");
    }
}

void stopwatch::on_Reset_clicked()
{
    timer.stop();
    if(ui->start_stop->text() == "Stop")
    {
        ui->start_stop->setStyleSheet("background-color:#89ff0b");
    }
    ui->start_stop->setText("Start");
    ui->time_text->setText("00:00:000");
    ui->time_text->setStyleSheet("color:black");
    time_on_stopwatch = QTime::fromMSecsSinceStartOfDay(0);
    ui->lap_results->clear();
    emit current_time_signal("00:00:000",this);

}
void stopwatch::on_hide_button_clicked()
{
    this->setVisible(false);
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
