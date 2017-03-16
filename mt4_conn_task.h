#ifndef MT4_CONN_TASK_H
#define MT4_CONN_TASK_H

#include <QRunnable>
#include <QObject>
#include <QDebug>

class mt4_conn_task : public QObject, public QRunnable
{
    Q_OBJECT
public:
    mt4_conn_task();

signals:
    void Result(int iNumber);
protected:
    void run();

};

#endif // mt4_conn_task_H
