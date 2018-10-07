#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"stopwatch.h"
#include<QDate>
#include<QTimer>
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

private:
    Ui::MainWindow *ui;
    QDate current_date;
    QTimer current_time;
    stopwatch*timer;
};

#endif // MAINWINDOW_H
