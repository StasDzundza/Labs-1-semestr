#include "alarm_clock.h"
#include "ui_alarm_clock.h"
#include<QFont>
#include<QMessageBox>
alarm_clock::alarm_clock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alarm_clock)
{
    ui->setupUi(this);
    this->setWindowTitle("ALARM CLOCK");
    lbl = new QLabel("<center>Enter time<\center>");
    line = new QLineEdit;
    lbl->setBuddy(line);
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    lbl->setFont(font);

    ok = new QPushButton("OK");
    ok->setDefault(true);//Enter push
    ok->setEnabled(false);

    close = new QPushButton("Close and delete alarm");

    layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(line);
    layout->addWidget(ok);
    layout->addWidget(close);



    main = new QVBoxLayout;
    main->addLayout(layout);
    setLayout(main);//main layout

    alarm_sound = new QSound(":/res/music/eminem.wav");

    timer = new QTimer;
    alarm_time_Time = new QTime;
    time_player = new QTimer;


    time_left = new QLabel;//remaining time
    start_stop = new QPushButton;//turn_on/turn_off button
    hide = new QPushButton;
    status = new QLabel;
    do_not_distrub = new QCheckBox;



    connect(time_player,SIGNAL(timeout()),this,SLOT(replay_sound()));
    connect(line,SIGNAL(textChanged(QString)),this,SLOT(TextChanged(QString)));
    connect(close,SIGNAL(clicked()),this,SLOT(close()));
    connect(ok,SIGNAL(clicked()),this,SLOT(OkClicked()));



}
int alarm_clock::clock_id = 0;
alarm_clock::~alarm_clock()
{
    timer->stop();
    time_player->stop();
    alarm_sound->stop();
    delete layout;
    delete main;
    delete lbl;
    delete time_left;
    delete status;
    delete close;
    delete start_stop;
    delete timer;
    delete alarm_time_Time;
    delete alarm_sound;
    delete time_player;
    delete ui;

}

void alarm_clock::OkClicked()
{
    alarm_time_text = line->text();
    alarm_time_text = alarm_time_text+":00";//alarm time        //+00 because we put oly hh and mm but not ss
    *alarm_time_Time = QTime::fromString(alarm_time_text, "hh:mm:ss");//take Qtime object from string
    lbl->setText("<center>Alarm will start at <\center>" + alarm_time_text);
    if(QTime::currentTime()<*alarm_time_Time)//if alarm will be on this day
    {
        connect(timer,SIGNAL(timeout()),this,SLOT(check_alarm()));
    }
    else
    {
        connect(timer,SIGNAL(timeout()),this,SLOT(check_alarm_on_other_day()));   //if alarm will be on the other day
    }
    timer->start(1000);//start time checking every second
    QFont font;
    font.setPixelSize(15);
    font.setBold(true);
   //
    time_left->setFont(font);
    time_left->setText("<center>Left to the signal : <\center>");

    //
    start_stop->setText("Turn off");
    connect(start_stop,SIGNAL(clicked()),this,SLOT(turn_off_on()));


    hide->setText("Hide");
    connect(hide,SIGNAL(clicked()),this,SLOT(on_hide_button_clicked()));


    status->setText("<center>Status : Turned on<\center>");
    status->setFont(font);

    do_not_distrub->setText("Do not distrub");
    do_not_distrub->setFont(font);

    layout->addWidget(start_stop);
    layout->addWidget(hide);
    layout->addWidget(time_left);
    layout->addWidget(status);
    layout->addWidget(do_not_distrub);

    delete line;
    delete ok;
}

void alarm_clock::on_hide_button_clicked()
{
    this->setVisible(false);
}

void alarm_clock::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());
}

void alarm_clock::check_alarm()
{
    QString current_time = QTime::currentTime().toString("hh:mm:ss");
    if(current_time == alarm_time_text)
    {
        if(!this->isVisible())
        {
            this->setVisible(true);
        }
        timer->stop();
        start_stop->setText("Turn on");
        status->setText("<center>Status : Turned off<\center>");
        time_left->setText("<center>Left to the signal : Turned off<\center>");
        if(!do_not_distrub->isChecked())
        {
            alarm_sound->play();
            time_player->start(11000);

            QMessageBox::StandardButton answer = QMessageBox::information(this,alarm_time_text,"WAKE UP!!!",QMessageBox::Close);
            if(answer == QMessageBox::Close)
            {
                alarm_sound->stop();
                time_player->stop();
            }
        }
    }
    else
    {
        int remain_msec = QTime::currentTime().msecsTo(*alarm_time_Time);//find msec to alarm
        QTime remaining_time = QTime::fromMSecsSinceStartOfDay(remain_msec);//convert to Qtime
        time_left->setText("<center>Left to the signal : <\center>" + remaining_time.toString("hh:mm:ss"));//set on label time_left
    }

}

void alarm_clock::check_alarm_on_other_day()
{
    if(QTime::currentTime() < *alarm_time_Time)//new day is olready here
    {
        timer->stop();
        disconnect(timer,SIGNAL(timeout()),this,SLOT(check_alarm_on_other_day()));
        connect(timer,SIGNAL(timeout()),this,SLOT(check_alarm()));
        timer->start();
    }
    else
    {
        QTime ms_to_23_59 = QTime::fromString("23:59:59","hh:mm:ss");
        QTime ms_00_00(0,0,0,0);
        int remain_msec = QTime::currentTime().msecsTo(ms_to_23_59) + ms_00_00.msecsTo(*alarm_time_Time) ;//finding msec to alarm
        QTime remaining_time = QTime::fromMSecsSinceStartOfDay(remain_msec);//convert to Qtime
        time_left->setText("<center>Left to the signal : <\center>" + remaining_time.toString("hh:mm:ss"));//set on label time_left
    }
}

void alarm_clock::turn_off_on()
{
    if(!timer->isActive())
    {
        timer->start();
        start_stop->setText("Turn off");
        int remain_msec = QTime::currentTime().msecsTo(*alarm_time_Time);//find msec to alarm
        QTime remaining_time = QTime::fromMSecsSinceStartOfDay(remain_msec);//convert to Qtime
        time_left->setText("Left to the signal : " + remaining_time.toString("hh:mm:ss"));//set on label time_left

        status->setText("<center>Status : Turned on<\center>");
    }
    else
    {
        timer->stop();
        start_stop->setText("Turn on");
        time_left->setText("<center>Left to the signal : Turned off<\center>");
        status->setText("<center>Status : Turned off<\center>");
    }
}

void alarm_clock::replay_sound()
{
    alarm_sound->play();
}

