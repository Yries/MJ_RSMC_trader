#include "mt4_conn_cli.h"

Mt4_conn_cli::Mt4_conn_cli(QObject *parent) : QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(50);
}

void Mt4_conn_cli::SetSocket(int Descriptor)
{
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    socket->setSocketDescriptor(Descriptor);

    qDebug() << "[+] klient połączony";
}

void Mt4_conn_cli::SetSSLSocket(int Descriptor)
{
    sslSocket = new QSslSocket(this);
    connect(sslSocket,SIGNAL(connected()),this,SLOT(connected()));
    connect(sslSocket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(sslSocket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    sslSocket->setSocketDescriptor(Descriptor);

    qDebug() << "[+] klient połączony";
}

void Mt4_conn_cli::connected()
{
    qDebug() << "[+] połączenie klienta (event)";
}

void Mt4_conn_cli::disconnected()
{
    qDebug() << "[+] klient rozłączony";
}

void Mt4_conn_cli::readyRead()
{
    //socket->readAll();
    qDebug() << socket->readAll() ;//<< "[+] połączenie klienta (event)";
    mt4_conn_task *mytask = new mt4_conn_task();
    mytask->setAutoDelete(true);
    connect (mytask,SIGNAL(Result(int)),this,SLOT(TaskResult(int)),Qt::QueuedConnection);
    QThreadPool::globalInstance()->start(mytask);
}

void Mt4_conn_cli::readyReadSsl()
{
    //socket->readAll();
    qDebug() << sslSocket->readAll() ;//<< "[+] połączenie klienta (event)";
    mt4_conn_task *mytask = new mt4_conn_task();
    mytask->setAutoDelete(true);
    connect (mytask,SIGNAL(Result(int)),this,SLOT(TaskResult(int)),Qt::QueuedConnection);
    QThreadPool::globalInstance()->start(mytask);
}

void Mt4_conn_cli::TaskResult(int Number)
{
    //Number =
    qDebug() << "[i]" << Number << "Task Result";
    QByteArray Bufor;
    Bufor.append("\r\nWynik zadania = ");
    Bufor.append(QString::number(Number));

    socket->write(Bufor);
}

void Mt4_conn_cli::TaskResultSsl(int Number)
{
    //Number =
    qDebug() << "[i]" << Number << "Task Result";
    QByteArray Bufor;
    Bufor.append("\r\nWynik zadania = ");
    Bufor.append(QString::number(Number));

    sslSocket->write(Bufor);
}

void Mt4_conn_cli::authStep1()
{
    //jakim jestem klientem
    //dźwignia
    //build dll
    //konto mt4 / bossa
    //dane konta
    //para walutowa
    //+reakcją jest nadanie id

}

void Mt4_conn_cli::authStep2()
{
    //sprawdzenie przydzielonego ID
    //zapisanie klienta
    //timer do raportu
}

//void Mt4_conn_cli::sprawdzStan()
//{
//
//}

void Mt4_conn_cli::instrukcja()
{

}

void Mt4_conn_cli::raportTick()
{
    //                        INSERT INTO public."KURS_GLOWNEJ_PARY"(
    //                                    "KGP_ID", "KGP_CENA_SELL", "KGP_CENA_BUY", "KGP_TIME", "KOD_WALUTY_GLOWNEJ",
    //                                    "KOD_WALUTY_ZALEZNEJ"
}

void Mt4_conn_cli::zapiszLog(){}
