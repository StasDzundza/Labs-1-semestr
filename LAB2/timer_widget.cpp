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
    lbl = new QLabel("Enter time for start Timer");//амсперсант для партнера(треба натискати alt+перша буква після амперсанта)hot key
    line = new QLineEdit;
    lbl->setBuddy(line);//партнер
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    lbl->setFont(font);

    ok = new QPushButton("OK");
    ok->setDefault(true);//при нажатті ентер вона буде виконуватись
    ok->setEnabled(false);//недоступна

    close = new QPushButton("Close and delete Timer");

    layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(line);
    layout->addWidget(ok);
    layout->addWidget(close);



    main = new QVBoxLayout;
    main->addLayout(layout);
    setLayout(main);//main layout


    time_count = new QTimer;
    connect(time_count,SIGNAL(timeout()),this,SLOT(check_timer()));
    connect(line,SIGNAL(textChanged(QString)),this,SLOT(TextChanged(QString)));
    connect(close,SIGNAL(clicked()),this,SLOT(close()));
    connect(ok,SIGNAL(clicked()),this,SLOT(OkClicked()));


}

timer_widget::~timer_widget()
{
    delete ui;
}

void timer_widget::OkClicked()
{
    delete close;
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

    QFont font;//font for text
    font.setPixelSize(18);
    font.setBold(true);

    time_left = new QLabel;//remaining time
    time_left->setFont(font);
    time_left->setText("<center>Left to the signal : <\center>");

    start_stop = new QPushButton;//turn_on/turn_off button
    start_stop->setText("Pause");

    close = new QPushButton;//close window button
    close->setText("Close and delete Timer");
    connect(close,SIGNAL(clicked()),this,SLOT(close()));

    reset = new QPushButton;
    reset->setText("Reset");
    connect(reset,SIGNAL(clicked()),this,SLOT(reset_clicked()));

    layout->addWidget(time_left);
    layout->addWidget(start_stop);
    layout->addWidget(reset);
    layout->addWidget(close);

    alarm_sound = new QSound(":/res/music/eminem.wav");

    time_player = new QTimer;

    connect(time_player,SIGNAL(timeout()),this,SLOT(replay_sound()));
    connect(start_stop,SIGNAL(clicked()),this,SLOT(turn_off_on()));
    time_count->start(500);
    delete line;
    delete ok;
}

void timer_widget::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());
}

void timer_widget::check_timer()
{
    int on_stopwatch = time_on_stopwatch.msecsSinceStartOfDay() + QTime::currentTime().msecsSinceStartOfDay() - last_start.msecsSinceStartOfDay();
    QString time_on_sw_string = QTime::fromMSecsSinceStartOfDay(on_stopwatch).toString("hh:mm:ss");
    if(time_on_sw_string == alarm_time_text)
    {
        time_count->stop();
        start_stop->setText("Start");
        time_left->setText("<center>Left to the signal : 00:00:00<\center>");
        time_on_stopwatch = QTime::fromMSecsSinceStartOfDay(0);

        alarm_sound->play();
        time_player->start(11000);

        QMessageBox::StandardButton answer = QMessageBox::information(this,"Timer","TIME OUT",QMessageBox::Close);
        if(answer = QMessageBox::Close)
        {
            alarm_sound->stop();
            time_player->stop();
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
    }
    else
    {
        last_start = QTime::currentTime();
        time_count->start(100);
        start_stop->setText("Pause");
    }
}

void timer_widget::reset_clicked()
{
    time_count->stop();
    start_stop->setText("Start");
    time_left->setText("<center>Left to the signal : NONE<\center>");
    time_on_stopwatch = QTime::fromMSecsSinceStartOfDay(0);
}

void timer_widget::replay_sound()
{
    alarm_sound->play();
}