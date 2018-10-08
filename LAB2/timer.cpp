#include "timer.h"
#include "ui_timer.h"

timer::timer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timer)
{
    /*ui->setupUi(this);
    lbl = new QLabel("Enter time");//амсперсант для партнера(треба натискати alt+перша буква після амперсанта)hot key
    line = new QLineEdit;
    lbl->setBuddy(line);//партнер
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    lbl->setFont(font);

    ok = new QPushButton("OK");
    ok->setDefault(true);//при нажатті ентер вона буде виконуватись
    ok->setEnabled(false);//недоступна

    close = new QPushButton("Close and delete alarm");

    layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(line);
    layout->addWidget(ok);
    layout->addWidget(close);



    main = new QVBoxLayout;
    main->addLayout(layout);
    setLayout(main);//main layout


    time = new QTimer;
    connect(line,SIGNAL(textChanged(QString)),this,SLOT(TextChanged(QString)));
    connect(close,SIGNAL(clicked()),this,SLOT(close()));
    connect(ok,SIGNAL(clicked()),this,SLOT(OkClicked()));*/
}

timer::~timer()
{
    delete ui;
}
void timer::OkClicked()
{

    time->start(1000);//start time checking every second
    QFont font;
    font.setPixelSize(15);
    font.setBold(true);


    start_stop = new QPushButton;//turn_on/turn_off button
    start_stop->setText("Turn off");
    layout->addWidget(start_stop);
    connect(start_stop,SIGNAL(clicked()),this,SLOT(turn_off_on()));

    delete line;
    delete ok;
}

void timer::TextChanged(QString str)
{
    //ok->setEnabled(!str.isEmpty());
}

void timer::check_timer()
{


}

void timer::turn_off_on()
{

}


