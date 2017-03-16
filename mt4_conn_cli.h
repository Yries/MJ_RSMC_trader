#ifndef MT4_CONN_CLI_H
#define MT4_CONN_CLI_H

#include <QObject>
#include <QTcpSocket>
#include <QSslSocket>
#include <QDebug>
#include <QThreadPool>
#include "mt4_conn_task.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

class Mt4_conn_cli :public QObject
{
    Q_OBJECT
public:
    explicit Mt4_conn_cli(QObject *parent = 0);
    void SetSocket(int Descriptor);
    void SetSSLSocket(int Descriptor);

signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void TaskResult(int Number);

    void readyReadSsl();
    void TaskResultSsl(int Number);

    //==moje==
    //uwierzytelnienie
    void authStep1();
    void authStep2();
    //sprawdzenie stanu
    //void sprawdzStan();
    void raportTick();
    //prześlij instrukcje
    void instrukcja();
    void zapiszLog();

private:
    QTcpSocket *socket;

    QSslSocket *sslSocket;
};

#endif // mt4_conn_cli_H
