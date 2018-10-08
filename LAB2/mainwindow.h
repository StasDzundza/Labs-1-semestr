#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "stopwatch.h"
#include "alarm_clock.h"
#include "timer_widget.h"
#include <QMainWindow>
#include <QDate>
#include <QTimer>
#include<QString>
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

signals:
    void time_for_clock(const QString &str);
private:
    Ui::MainWindow *ui;
    QDate current_date;
    QTimer current_time;
    stopwatch *stop_watch;
    alarm_clock*a_clock;
    timer_widget*Timer;
};


#endif // MAINWINDOW_H
