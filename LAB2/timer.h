#ifndef TIMER_H
#define TIMER_H

#include <QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QWidget>
#include<QLayout>
#include<QString>
#include<QTimer>
#include<QTime>
namespace Ui {
class timer;
}

class timer : public QDialog
{
    Q_OBJECT

public:
    explicit timer(QWidget *parent = nullptr);
    ~timer();

private slots:
void OkClicked();
void TextChanged(QString str);
void check_timer();
void turn_off_on();

private:
    Ui::timer *ui;
    int id;
    QVBoxLayout*layout;
    QVBoxLayout*main;

    QLabel*lbl;
    QLineEdit*line;
    QPushButton*ok;
    QPushButton*close;
    QPushButton*start_stop;

    QString timer_time_text;
    QTimer *time;
};

#endif // TIMER_H
