#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/source/icon.svg"));
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);//设置窗口，无边框，顶部显示
    setWindowModality(Qt::ApplicationModal);  //模态窗口是一种会阻塞其他窗口（或整个应用程序）的窗口，直到该模态窗口被关闭
    setAttribute(Qt::WA_TranslucentBackground);   //窗口背景为透明
    ui->setupUi(this);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWindow::close);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::showExternalWindow);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::start_and_end_time);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&MainWindow::set_30);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&MainWindow::set_60);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::showTime);

    remainingTime=0;
    timeStr=int_to_str(remainingTime);
    ui->lcdNumber->setDigitCount(8);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Filled);
    //无边框窗口,当使用该标志时，窗口将没有标题栏、边框和系统菜单按钮
    ui->lcdNumber->setWindowFlags(Qt::FramelessWindowHint);
    ui->lcdNumber->display(timeStr);
    this->isRunTime=false;
    ui->widget_2->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showExternalWindow(){
    ui->widget_2->setVisible(!ui->widget_2->isVisible());
}

void MainWindow::showTime(){
    remainingTime--;
    // QTime time = QTime::currentTime();
    // QString timeStr = time.toString("hh:mm:ss");//设置时间格式
    timeStr=int_to_str(remainingTime);
    ui->lcdNumber->display(timeStr);
    ui->lcdNumber->show();// 显示LCD数字

}





void MainWindow::start_and_end_time()
{
    if(!isRunTime){
        timer->start(1000);
        isRunTime=true;
    }
    else{
        timer->stop();
        isRunTime=false;
    }

}

QString MainWindow::int_to_str(int time)
{
    int s=time%60;
    int m=(time/60)%60;
    int h=time/3600%24;
    QString str_s= s>9 ?QString::number(s):"0"+QString::number(s);
    QString str_m= m>9 ?QString::number(m):"0"+QString::number(m);
    QString str_h= h>9 ?QString::number(h):"0"+QString::number(h);
    return str_h+":"+str_m+":"+str_s;
}


void MainWindow::set_30()
{
    remainingTime=1800;
    timeStr=int_to_str(remainingTime);
    ui->lcdNumber->display(timeStr);
    ui->lcdNumber->show();// 显示LCD数字
}




void MainWindow::set_60()
{
    remainingTime=3600;
    timeStr=int_to_str(remainingTime);
    ui->lcdNumber->display(timeStr);
    ui->lcdNumber->show();// 显示LCD数字
}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(this->x() + (event->globalX() - m_lastPos.x()),
               this->y() + (event->globalY() - m_lastPos.y()));
    m_lastPos = event->globalPos();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // 其实这里的mouseReleaseEvent函数可以不用重写
    m_lastPos = event->globalPos();
}
