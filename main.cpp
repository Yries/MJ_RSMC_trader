#include "masterofpuppets.h"
#include <QApplication>
#include <QDebug>
#include "db_conn.h"
#include "mt4_conn_svr.h"

int main(int argc, char *argv[])
{
    qDebug() << QSqlDatabase::drivers();
    QApplication a(argc, argv);
    db_conn *pTest = NULL;
    db_conn *pProd = NULL;//= &prod;
    db_conn *pTF = NULL;// = &tf;
    MasterOfPuppets w(argc,argv,pTest,pProd,pTF);
    w.show();
    mt4_conn_svr Serwer;
    Serwer.StartServer();
    return a.exec();
}
