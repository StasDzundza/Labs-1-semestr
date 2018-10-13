#ifndef ALARM_CLOCK_H
#define ALARM_CLOCK_H

#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QWidget>
#include<QLayout>
#include<QString>
#include<QTimer>
#include<QTime>
#include<QtMultimedia/QSound>
#include<QCheckBox>
#include<QGroupBox>
#include<QRadioButton>

namespace Ui {
class alarm_clock;
}

class alarm_clock : public QDialog
{
    Q_OBJECT

public:
    explicit alarm_clock(QWidget *parent = nullptr);
    ~alarm_clock();

friend QString change_from_12_to_24_format(const QString& time,const alarm_clock*clock);

signals:
void my_textChanged(QString);

private slots:
void on_12_hours_clicked();
void on_24_hours_clicked();
void OkClicked();
void on_hide_button_clicked();
void TextChanged(QString str);
void check_alarm();
void check_alarm_on_other_day();
void turn_off_on();
void replay_sound();

private:
    Ui::alarm_clock *ui;
    bool was_alarm = false;
    QGroupBox *group_box_format;
    QGroupBox *group_box_am_pm;
    QRadioButton*hour12;
    QRadioButton*hour24;
    QRadioButton*am;
    QRadioButton*pm;
    QHBoxLayout*format_and_am_pm;
    QVBoxLayout*layout;
    QVBoxLayout*main;
    QVBoxLayout*for_formats;
    QVBoxLayout*for_am_pm;

    QLabel*lbl;
    QLabel*time_left;
    QLabel*status;
    QLineEdit*line;
    QPushButton*ok;
    //QPushButton*close;
    QPushButton*start_stop;
    QPushButton*hide;
    QString alarm_time_text;
    QTimer*timer;
    QTime*alarm_time_Time;
    QCheckBox *do_not_distrub;

    QTimer*time_player;
    QSound*alarm_sound;
};

#endif // ALARM_CLOCK_H
