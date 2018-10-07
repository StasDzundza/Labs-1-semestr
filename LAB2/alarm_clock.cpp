#include "alarm_clock.h"
#include "ui_alarm_clock.h"
#include<QFont>
alarm_clock::alarm_clock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alarm_clock)
{
    ui->setupUi(this);
    lbl = new QLabel("Enter time");//амсперсант для партнера(треба натискати alt+перша буква після амперсанта)hot key
    line = new QLineEdit;
    lbl->setBuddy(line);//партнер
    QFont font;
    font.setPixelSize(25);
    font.setBold(true);
    lbl->setFont(font);

    ok = new QPushButton("OK");
    ok->setDefault(true);//при нажатті ентер вона буде виконуватись
    ok->setEnabled(false);//недоступна

    close = new QPushButton("Close");

    QVBoxLayout*layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(line);
    layout->addWidget(ok);
    layout->addWidget(close);



    QHBoxLayout*main = new QHBoxLayout;
    main->addLayout(layout);
    setLayout(main);//main layout
    connect(line,SIGNAL(textChanged(QString)),this,SLOT(TextChanged(QString)));
    connect(close,SIGNAL(clicked()),this,SLOT(close()));
    connect(ok,SIGNAL(clicked()),this,SLOT(OkClicked()));
    connect(this,SIGNAL(time_for_clock(const QString&str)),this,SLOT(take_signal(const QString&str)));

}
int alarm_clock::clock_id = 0;
alarm_clock::~alarm_clock()
{
    delete ui;
}

void alarm_clock::OkClicked()
{
    delete lbl;
    delete line;
    delete ok;
}

void alarm_clock::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());
}

