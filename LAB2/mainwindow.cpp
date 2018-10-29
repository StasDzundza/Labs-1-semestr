#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"stopwatch.h"
#include<QString>
#include<QApplication>
#include<QListWidget>
#include<QListWidgetItem>
#include<QDebug>
#include<algorithm>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QBrush br(Qt::TexturePattern);
    br.setTextureImage(QImage(":/res/images/body.jpg"));
    QPalette plt(palette());
    plt.setBrush(QPalette::Background, br);
    this->setPalette(plt);
    this->setWindowTitle("LAB2");
    current_date = QDate::currentDate();
    ui->date_text->setText(current_date.toString("dd/MM/yy"));//set current date on main window
    connect(&current_time,SIGNAL(timeout()),this,SLOT(change_time()));
    current_time.start(1000);//every second we chande time on main window

    ctrl_plus_s = new QShortcut(this);
    ctrl_plus_s->setKey(Qt::CTRL+Qt::Key_S);
    connect(ctrl_plus_s,SIGNAL(activated()),this,SLOT(on_open_stopwatch_button_clicked()));

    ctrl_plus_a = new QShortcut(this);
    ctrl_plus_a->setKey(Qt::CTRL+Qt::Key_A);
    connect(ctrl_plus_a,SIGNAL(activated()),this,SLOT(on_open_alarm_button_clicked()));

    ctrl_plus_t = new QShortcut(this);
    ctrl_plus_t->setKey(Qt::CTRL+Qt::Key_T);
    connect(ctrl_plus_t,SIGNAL(activated()),this,SLOT(on_open_timer_button_clicked()));

    connect(ui->actionNew_stopwatch,SIGNAL(triggered()),this,SLOT(on_open_stopwatch_button_clicked()));
    connect(ui->actionNew_alarm_clock_2,SIGNAL(triggered()),this,SLOT(on_open_alarm_button_clicked()));
    connect(ui->actionNew_timer,SIGNAL(triggered()),this,SLOT(on_open_timer_button_clicked()));
}

MainWindow::~MainWindow()
{
    while(stopwatch_vector.size()!=0)
    {
        stopwatch *tmp = stopwatch_vector[0];
        delete tmp;
        stopwatch_vector.erase(stopwatch_vector.begin());
        count_stopwatches--;
    }
    while(alarm_clock_vector.size()!=0)
    {
        alarm_clock *tmp = alarm_clock_vector[0];
        delete tmp;
        alarm_clock_vector.erase(alarm_clock_vector.begin());
        count_alarm_clocks--;
    }
    while(timer_vector.size()!=0)
    {
        timer_widget*tmp = timer_vector[0];
        delete tmp;
        timer_vector.erase(timer_vector.begin());
        count_timers--;
    }
    delete ui;
}

void MainWindow::change_time()
{

    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if(time.second()%2 == 0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui->time_text->setText(time_text);

}
void MainWindow::on_open_stopwatch_button_clicked()
{
    stopwatch *stop_watch = new stopwatch;
    stopwatch_vector.push_back(stop_watch);
    connect(stop_watch,SIGNAL(current_time_signal(QString,stopwatch*)),this,SLOT(change_text_in_stopwatch_list(QString,stopwatch*)));
    QListWidgetItem *st_w = new QListWidgetItem("Stopwatch №" + QString::number(++count_stopwatches));
    ui->stopwatch_list->addItem(st_w);
    stop_watch->show();
}

void MainWindow::on_open_alarm_button_clicked()
{
    alarm_clock *a_clock = new alarm_clock;
    alarm_clock_vector.push_back(a_clock);
    connect(a_clock,SIGNAL(current_time_signal(QString,alarm_clock*)),this,SLOT(change_text_in_alarm_list(QString,alarm_clock*)));
    QListWidgetItem *clock = new QListWidgetItem("Alarm Clock №" + QString::number(++count_alarm_clocks));
    ui->alarm_list->addItem(clock);
    a_clock->show();
}

void MainWindow::on_open_timer_button_clicked()
{
    timer_widget *Timer = new timer_widget;
    timer_vector.push_back(Timer);
    connect(Timer,SIGNAL(current_time_signal(QString,timer_widget*)),this,SLOT(change_text_in_timer_list(QString,timer_widget*)));
    QListWidgetItem *t = new QListWidgetItem("Timer №" + QString::number(++count_timers));
    ui->timer_list->addItem(t);
    Timer->show();

}

void MainWindow::on_exit_button_clicked()
{
    QApplication::quit();
}

void MainWindow::on_delete_stopwatch_button_clicked()
{
   if(!stopwatch_vector.isEmpty())
   {
       QList<QListWidgetItem *> it = ui->stopwatch_list->selectedItems();
       if(!it.isEmpty())
       {
           int current = ui->stopwatch_list->currentRow();
           delete ui->stopwatch_list->currentItem();//delete element from list
           stopwatch*w = stopwatch_vector[current];
           delete w;//delete window
           QVector<stopwatch*>::Iterator it = stopwatch_vector.begin();//delete element from vector
           it = it+current;
           stopwatch_vector.erase(it);
       }
   }

}

void MainWindow::on_show_stopwatch_button_clicked()
{
    if(!stopwatch_vector.isEmpty())
    {
        QList<QListWidgetItem *> it = ui->stopwatch_list->selectedItems();
        if(!it.isEmpty())
        {
            int current = ui->stopwatch_list->currentRow();
            stopwatch*window = stopwatch_vector[current];
            if(!window->isVisible())
            {
                window->setVisible(true);
            }
        }
    }
}

void MainWindow::on_delete_alarm_button_clicked()
{
    if(!alarm_clock_vector.isEmpty())
    {
        QList<QListWidgetItem *> it = ui->alarm_list->selectedItems();
        if(!it.isEmpty())
        {
            int current = ui->alarm_list->currentRow();
            qDebug()<<current;
            delete ui->alarm_list->currentItem();//delete element from list
            alarm_clock*w = alarm_clock_vector[current];
            delete w;//delete window
            QVector<alarm_clock*>::Iterator it = alarm_clock_vector.begin();//delete element from vector
            it = it+current;
            alarm_clock_vector.erase(it);
        }
    }
}

void MainWindow::on_show_alarm_button_clicked()
{
    if(!alarm_clock_vector.isEmpty())
    {
        QList<QListWidgetItem *> it = ui->alarm_list->selectedItems();
        if(!it.isEmpty())
        {
            int current = ui->alarm_list->currentRow();
            alarm_clock*window = alarm_clock_vector[current];
            if(!window->isVisible())
            {
                window->setVisible(true);
            }
        }
    }
}

void MainWindow::on_delete_timer_button_clicked()
{
    if(!timer_vector.isEmpty())
    {
        QList<QListWidgetItem *> it = ui->timer_list->selectedItems();
        if(!it.isEmpty())
        {
            int current = ui->timer_list->currentRow();
            delete ui->timer_list->currentItem();//delete element from list
            timer_widget*wnd = timer_vector[current];
            delete wnd;//delete window
            QVector<timer_widget*>::Iterator iter = timer_vector.begin();//delete element from vector
            iter = iter+current;
            timer_vector.erase(iter);
        }
    }
}

void MainWindow::on_show_timer_button_clicked()
{   
    if(!timer_vector.isEmpty())
    {
        QList<QListWidgetItem *> it = ui->timer_list->selectedItems();
        if(!it.isEmpty())
        {
            int current = ui->timer_list->currentRow();
            timer_widget*window = timer_vector[current];
            if(!window->isVisible())
            {
                window->setVisible(true);
            }
        }
    }
}

void MainWindow::change_text_in_timer_list(const QString &time, timer_widget *current_timer)
{
    int index;
    for(int i = 0; i < timer_vector.size();i++)
    {
        if(timer_vector[i] == current_timer)
        {
            index = i;
        }
    }
    QListWidgetItem *t = ui->timer_list->item(index);
    t->setText("Timer №"+QString::number(current_timer->get_id()) + "  " + time);
}

void MainWindow::change_text_in_alarm_list(const QString &time, alarm_clock *current_alarm)
{
    int index;
    for(int i = 0; i < alarm_clock_vector.size();i++)
    {
        if(alarm_clock_vector[i] == current_alarm)
        {
            index = i;
        }
    }
    QListWidgetItem *t = ui->alarm_list->item(index);
    t->setText("Alarm Clock №"+QString::number(current_alarm->get_id()) + "  " + time);
}

void MainWindow::change_text_in_stopwatch_list(const QString &time, stopwatch *current_stopwatch)
{
    int index;
    for(int i = 0; i < stopwatch_vector.size();i++)
    {
        if(stopwatch_vector[i] == current_stopwatch)
        {
            index = i;
        }
    }
    QListWidgetItem *t = ui->stopwatch_list->item(index);
    t->setText("Stopwatch №"+QString::number(current_stopwatch->get_id()) + "  " + time);
}
