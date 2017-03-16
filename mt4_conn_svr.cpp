#include "mt4_conn_svr.h"

mt4_conn_svr::mt4_conn_svr(QObject *parent) : QTcpServer(parent)
{

}

void mt4_conn_svr::StartServer()
{
    if(listen(QHostAddress::Any,1234))
    {
        qDebug() << "[+] Serwer nasłuchuje :)";
    }else{
        qDebug() << "[-] Nie można uruchomić serwera";
    }
}

void mt4_conn_svr::incomingConnection(int handle)
{
    Mt4_conn_cli *client = new Mt4_conn_cli(this);
    client->SetSocket(handle);
}

