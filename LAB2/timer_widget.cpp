#include "timer_widget.h"
#include "ui_timer_widget.h"
#include<QMessageBox>
#include<QDebug>
timer_widget::timer_widget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timer_widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Timer");
    lbl = new QLabel("&Enter time for start Timer");//ampersant for hot key alt+E
    line = new QLineEdit;
    lbl->setBuddy(line);//партнер
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    lbl->setFont(font);

    ok = new QPushButton("OK");
    ok->setDefault(true);//Enter Button
    ok->setEnabled(false);//not enabled

    hide = new QPushButton;
    hide->setText("Hide");

    layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(line);
    layout->addWidget(ok);
    layout->addWidget(hide);



    main = new QVBoxLayout;
    main->addLayout(layout);
    setLayout(main);//main layout


    time_count = new QTimer;
    time_left = new QLabel;//remaining time
    start_stop = new QPushButton;//turn_on/turn_off button
    reset = new QPushButton;
    time_player = new QTimer;
    alarm_sound = new QSound(":/res/music/eminem.wav");
    do_not_distrub = new QCheckBox;

    connect(time_count,SIGNAL(timeout()),this,SLOT(check_timer()));
    connect(line,SIGNAL(textChanged(QString)),this,SLOT(TextChanged(QString)));
    connect(ok,SIGNAL(clicked()),this,SLOT(OkClicked()));
    connect(hide,SIGNAL(clicked()),this,SLOT(on_hide_button_clicked()));
}

timer_widget::~timer_widget()
{
    time_count->stop();
    time_player->stop();
    delete hide;
    delete layout;
    delete main;
    delete lbl;
    delete time_left;
    delete start_stop;
    delete time_count;
    delete alarm_sound;
    delete time_player;
    delete ui;
}

void timer_widget::OkClicked()
{
    QString time = line->text();
    //we are finding msec from string to int
    QString h;
    QString m;
    QString s;
    int hh,mm,ss;
    h = time[0];
    h = h + time[1];
    hh = h.toInt();
    m = time[3];
    m = m + time[4];
    mm = m.toInt();
    s = time[6];
    s = s + time[7];
    ss = s.toInt();
    ss*=1000;
    mm*=60*1000;
    hh*= 3600*1000;
    timer_time_msec = ss+mm+hh;//timer time in mseconds

    last_start = QTime::currentTime();

    alarm_time_text = line->text();
    lbl->setText("<center>Timer time <\center>" + alarm_time_text);
    disconnect(line,SIGNAL(textChanged(QString)),this,SLOT(TextChanged(QString)));
    disconnect(ok,SIGNAL(clicked()),this,SLOT(OkClicked()));
    delete line;
    delete ok;

    QFont font;//font for text
    font.setPixelSize(18);
    font.setBold(true);

    time_left->setFont(font);
    time_left->setText("<center>Left to the signal : <\center>");

    start_stop->setText("Pause");
    start_stop->setStyleSheet("background-color:#ff2b1c");

    reset->setText("Reset");
    connect(reset,SIGNAL(clicked()),this,SLOT(reset_clicked()));

    do_not_distrub->setText("Do not distrub");
    do_not_distrub->setFont(font);

    layout->removeWidget(hide);
    layout->addWidget(time_left);
    layout->addWidget(start_stop);
    layout->addWidget(reset);
    layout->addWidget(hide);
    layout->addWidget(do_not_distrub);

    connect(time_player,SIGNAL(timeout()),this,SLOT(replay_sound()));
    connect(start_stop,SIGNAL(clicked()),this,SLOT(turn_off_on()));
    time_count->start(500);

}

void timer_widget::on_hide_button_clicked()
{
    this->setVisible(false);
}

void timer_widget::TextChanged(QString str)
{
    if(str.size()!=8)//00:00:00
    {
        ok->setEnabled(false);
    }
    else
    {
        if(str[2]!=':'||str[5]!=':')//position of ':'
        {
            ok->setEnabled(false);
        }
        else
        {
            QString hours,minutes,seconds;
            hours = (QString)str[0] + (QString)str[1];
            int hh = hours.toInt();
            minutes = (QString)str[3] + (QString)str[4];
            int mm = minutes.toInt();
            seconds = (QString)str[6] + (QString)str[7];
            int ss = seconds.toInt();
            if(hh>=0&&hh<=23&&mm>=0&&mm<=59&&ss>=0&&ss<=59)
            {
                ok->setEnabled(true);
            }
            else
            {
                ok->setEnabled(false);
            }
        }
    }
}

void timer_widget::check_timer()
{
    int on_stopwatch = time_on_stopwatch.msecsSinceStartOfDay() + QTime::currentTime().msecsSinceStartOfDay() - last_start.msecsSinceStartOfDay();
    QString time_on_sw_string = QTime::fromMSecsSinceStartOfDay(on_stopwatch).toString("hh:mm:ss");
    if(time_on_sw_string == alarm_time_text)
    {
        if(!this->isVisible())
        {
            this->setVisible(true);
        }
        time_count->stop();
        start_stop->setText("Start");
        start_stop->setStyleSheet("background-color:#89ff0b");
        time_left->setText("<center>Left to the signal : 00:00:00<\center>");
        time_on_stopwatch = QTime::fromMSecsSinceStartOfDay(0);
        if(!do_not_distrub->isChecked())
        {
            alarm_sound->play();
            time_player->start(11000);

            QMessageBox::StandardButton answer = QMessageBox::information(this,"Timer","TIME OUT",QMessageBox::Close);
            if(answer = QMessageBox::Close)
            {
                alarm_sound->stop();
                time_player->stop();
            }
        }
    }
    else
    {
        int remine  = timer_time_msec-on_stopwatch;
        time_left->setText("<center>Left to the signal : <\center>" + QTime::fromMSecsSinceStartOfDay(remine).toString("hh:mm:ss") );

    }
}
void timer_widget::turn_off_on()
{
    if(time_count->isActive())
    {
        time_count->stop();
        time_on_stopwatch = QTime::fromMSecsSinceStartOfDay(time_on_stopwatch.msecsSinceStartOfDay()+QTime::currentTime().msecsSinceStartOfDay()- last_start.msecsSinceStartOfDay());
        start_stop->setText("Continue");
        start_stop->setStyleSheet("background-color:#89ff0b");
    }
    else
    {
        last_start = QTime::currentTime();
        time_count->start(100);
        start_stop->setText("Pause");
        start_stop->setStyleSheet("background-color:#ff2b1c");
    }
}

void timer_widget::reset_clicked()
{
    time_count->stop();
    start_stop->setText("Start");
    start_stop->setStyleSheet("background-color:#89ff0b");
    time_left->setText("<center>Left to the signal : NONE<\center>");
    time_on_stopwatch = QTime::fromMSecsSinceStartOfDay(0);
}

void timer_widget::replay_sound()
{
    alarm_sound->play();
}
