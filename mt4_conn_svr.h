#ifndef MT4_CONN_SVR_H
#define MT4_CONN_SVR_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QList>
#include <QDebug>
#include "mt4_conn_cli.h"

class mt4_conn_svr : public QTcpServer
{
    Q_OBJECT
public:
    explicit mt4_conn_svr (QObject *parent = 0);
    void StartServer();



    //do obsługi połączeń serwera - logika wyższa
    void potwierdzPolaczenie();
    //klienci - bez gita
    //QList klienci;
    //void dodajKlienta();
    //void usunKlienta(Qlist klient, int ID);

protected:
    void incomingConnection(int handle);

};

#endif // A70SVR_H

