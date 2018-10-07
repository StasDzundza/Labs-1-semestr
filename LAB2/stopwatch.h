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

private:
    Ui::stopwatch *ui;
    bool running;
    QTimer timer;
    QTime time_left;
    QTime last_start;
};

#endif // STOPWATCH_H
