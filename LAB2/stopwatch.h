#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QDialog>
#include<QTimer>
#include<QTime>
namespace Ui {
class stopwatch;
}

class stopwatch : public QDialog
{
    Q_OBJECT

public:
    explicit stopwatch(QWidget *parent = nullptr);
    ~stopwatch();
private slots:
    void onTimer();

    void on_start_stop_clicked();

    void on_Reset_clicked();

    void on_hide_button_clicked();

    void on_lap_button_clicked();

private:
    int count_laps = 0;
    QTime last_lap = QTime::fromMSecsSinceStartOfDay(0);
    Ui::stopwatch *ui;
    bool running;
    QTimer timer;
    QTime time_on_stopwatch;//time which is on the stopwatch
    QTime last_start;//time of last start stopwatch
};

#endif // STOPWATCH_H
