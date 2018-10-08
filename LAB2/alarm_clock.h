#ifndef ALARM_CLOCK_H
#define ALARM_CLOCK_H

#include <QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QWidget>
#include<QLayout>
#include<QString>
#include<QTimer>
#include<QTime>

namespace Ui {
class alarm_clock;
}

class alarm_clock : public QDialog
{
    Q_OBJECT

public:
    explicit alarm_clock(QWidget *parent = nullptr);
    ~alarm_clock();
    static int clock_id;
private slots:
void OkClicked();
void TextChanged(QString str);
void check_alarm();
void turn_off_on();
private:
    Ui::alarm_clock *ui;
    int id;
    QVBoxLayout*layout;
    QVBoxLayout*main;

    QLabel*lbl;
    QLabel*time_left;
    QLabel*status;
    QLineEdit*line;
    QPushButton*ok;
    QPushButton*close;
    QPushButton*start_stop;

    QString alarm_time_text;
    QTimer*timer;
    QTime*alarm_time_Time;
};

#endif // ALARM_CLOCK_H
