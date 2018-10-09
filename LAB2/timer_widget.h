#ifndef TIMER_WIDGET_H
#define TIMER_WIDGET_H

#include<QDialog>
#include<QVBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QTimer>
#include<QTime>
#include<QtMultimedia/QSound>
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
void reset_clicked();
void replay_sound();
private:
    Ui::timer_widget *ui;

    int timer_time_msec = 0;

    QVBoxLayout*layout;
    QVBoxLayout*main;

    QLabel*lbl;
    QLabel*time_left;
    QLineEdit*line;
    QPushButton*ok;
    QPushButton*close;
    QPushButton*start_stop;
    QPushButton*reset;

    QString alarm_time_text;
    QTimer*time_count;//the main timer which checking time

    QTime time_on_stopwatch;//time which is on the stopwatch
    QTime last_start;//time of last start stopwatch

    QTimer*time_player;//for sound
    QSound*alarm_sound;


};

#endif // TIMER_WIDGET_H
