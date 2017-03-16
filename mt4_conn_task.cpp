#include "mt4_conn_task.h"

mt4_conn_task::mt4_conn_task()
{

}

void mt4_conn_task::run()
{
    qDebug() << "[+] Zadanie wystartowało";
    int iNumber = 0;
    for(int i = 0; i < 1000; i++)
    {
        iNumber += i;
    }
    qDebug() << "[+] Zadanie zakończone";
    emit Result(iNumber);
}
