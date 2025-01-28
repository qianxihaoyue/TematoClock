#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QTimer>
#include<QTime>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void showExternalWindow();
    void start_and_end_time();
    QString int_to_str(int time);
    void set_30();
    void set_60();
    void showTime();
    ~MainWindow();

private:
    QPoint m_lastPos; //**定义QPoint
    Ui::MainWindow *ui;

   //倒计时
    QTimer *timer;
    int remainingTime;
    QString timeStr;
    bool isRunTime;

};
#endif // MAINWINDOW_H
