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
private:
    Ui::alarm_clock *ui;
    int id;
    QLabel*lbl;
    QLineEdit*line;
    QPushButton*ok;
    QPushButton*close;
};

#endif // ALARM_CLOCK_H
