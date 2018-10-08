#ifndef TIMER_WIDGET_H
#define TIMER_WIDGET_H

#include <QDialog>
#include<QVBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QTimer>
#include<QTime>
namespace Ui {
class timer_widget;
}

class timer_widget : public QDialog
{
    Q_OBJECT

public:
    explicit timer_widget(QWidget *parent = nullptr);
    ~timer_widget();
private slots:
void OkClicked();
void TextChanged(QString str);
void check_timer();
void turn_off_on();
private:
    Ui::timer_widget *ui;
    QVBoxLayout*layout;
    QVBoxLayout*main;

    QLabel*lbl;
    QLabel*time_left;
    QLineEdit*line;
    QPushButton*ok;
    QPushButton*close;
    QPushButton*start_stop;
    QTime endTime;

    QString alarm_time_text;
    QTimer*time_count;

};

#endif // TIMER_WIDGET_H
