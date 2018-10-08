#include "timer_widget.h"
#include "ui_timer_widget.h"
#include<QMessageBox>
timer_widget::timer_widget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timer_widget)
{
    ui->setupUi(this);
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
    QString time = line->text();
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
    hh = 3600*1000;
    int ms = QTime::currentTime().msecsSinceStartOfDay() + ss+mm+hh;
    endTime = QTime::fromMSecsSinceStartOfDay(ms);
    connect(time_count,SIGNAL(timeout()),this,SLOT(check_timer()));
    time_count->start();
    alarm_time_text = line->text();
    lbl->setText("Timer time " + alarm_time_text);
    time_count->start(1000);//start time checking every second
    QFont font;
    font.setPixelSize(15);
    font.setBold(true);
    time_left = new QLabel;//remaining time
    time_left->setFont(font);
    time_left->setText("Left to the signal : ");

    start_stop = new QPushButton;//turn_on/turn_off button
    start_stop->setText("Pause");

    layout->addWidget(time_left);
    layout->addWidget(start_stop);
    connect(start_stop,SIGNAL(clicked()),this,SLOT(turn_off_on()));

    delete line;
    delete ok;
}

void timer_widget::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());
}

void timer_widget::check_timer()
{
    QString current_time = QTime::currentTime().toString("hh:mm:ss");
    if(current_time == alarm_time_text)
    {
        start_stop->setText("Start");
        QMessageBox::information(this,"Timer!!!","Timer!!!");
    }
    else
    {
        int remain_msec = QTime::currentTime().msecsTo(endTime);//find msec to alarm
        QTime remaining_time = QTime::fromMSecsSinceStartOfDay(remain_msec);//convert to Qtime
        time_left->setText("Left to the end : " + remaining_time.toString("hh:mm:ss"));//set on label time_left
    }
}
void timer_widget::turn_off_on()
{
    if(start_stop->text() != "Pause")
    {
        time_count->start();
        start_stop->setText("Pause");
    }
    else
    {
        time_count->stop();
        start_stop->setText("Continue");
    }
}
