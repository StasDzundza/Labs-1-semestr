#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "stopwatch.h"
#include "alarm_clock.h"
#include "timer_widget.h"
#include <QMainWindow>
#include <QDate>
#include <QTimer>
#include <QString>
#include <QVector>
#include <QShortcut>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_stopwatch_button_clicked();
    void change_time();

    void on_open_alarm_button_clicked();
    void on_exit_button_clicked();

    void on_open_timer_button_clicked();

    void on_delete_stopwatch_button_clicked();

    void on_show_stopwatch_button_clicked();

    void on_delete_alarm_button_clicked();

    void on_show_alarm_button_clicked();

    void on_delete_timer_button_clicked();

    void on_show_timer_button_clicked();

    void change_text_in_timer_list(const QString& time,timer_widget*current_timer);

    void change_text_in_alarm_list(const QString &time, alarm_clock *current_alarm);

    void change_text_in_stopwatch_list(const QString &time, stopwatch *current_stopwatch);

private:

    int count_stopwatches = 0;
    int count_alarm_clocks = 0;
    int count_timers = 0;
    const int max_count_of_time_widgets = 5;
    Ui::MainWindow *ui;
    QDate current_date;
    QTimer current_time;
    alarm_clock*a_clock;
    timer_widget*Timer;

    QVector<stopwatch*> stopwatch_vector;
    QVector<alarm_clock*> alarm_clock_vector;
    QVector<timer_widget*> timer_vector;

    QShortcut *ctrl_plus_s;//new stopwatch
    QShortcut *ctrl_plus_a;//new alarm clock
    QShortcut *ctrl_plus_t;//new timer
};


#endif // MAINWINDOW_H
