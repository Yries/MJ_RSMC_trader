#include "save_settings.h"
#include <QString>

save_settings::save_settings(){}
/************baza dynamicznie************/
QSqlDatabase save_settings::mydb = QSqlDatabase::addDatabase("QSQLITE","lite"); //można korzystać z QDir ale to było pierwsze... i działa
/************baza dynamicznie************/
save_settings::save_settings(int argc, char *argv[]) : sqlpath( checkParamsToOtherSqlPatch(argc,argv))
{
//    qDebug() << QSqlDatabase::drivers();
    qDebug() <<"[i]ścieżka wewnątrz: "<< sqlpath;

    //mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setConnectOptions("POLICY_DB_DEFAULT=None; POLICY_DB_WRITE=sid[0x12345678], WriteDeviceData");
    mydb.setDatabaseName(sqlpath);
    mydb.setHostName("MyServer");
//    qDebug() << "[+] !!Result 0 = " << mydb.open();
//    mydb.setNumericalPrecisionPolicy();
//    mydb.setPassword();
//    mydb.setPort();
//    mydb.setUserName();
//    qDebug() << "[+] !!Result 0 = " << mydb.isDriverAvailable("QSQLITE");
//    qDebug() << "[+] !!Result 0 = " << mydb.isDriverAvailable("lite");


    QFileInfo checkFile(sqlpath);
    if(checkFile.isFile()){
        if(mydb.open()){
            qDebug() <<"[+]Połączono z bazą save :)";
        }else{
            qDebug() <<"[!] Nie udało się połączyć z bazą save :(";
        }
    }else{
        qDebug() <<"[!] Baza save nie istnieje! :(";  //czy utworzyć bazę save ?
    }
    //QString QSqlDatabase::connectionName() const - może sie przydać do zamykanaia
}
/************baza dynamicznie************/
QSqlDatabase save_settings::_mydb()
{
    //qDebug() << QSqlDatabase::drivers();
    return mydb;
}

save_settings *save_settings::_obj_mydb()
{
    //qDebug() << QSqlDatabase::drivers();
    if(!obj_mydb)
    {
       // qDebug() << QSqlDatabase::drivers();
        obj_mydb = new save_settings();
    }
    return obj_mydb;
}

save_settings *save_settings::obj_mydb = new save_settings;
/************baza dynamicznie************/
save_settings::~save_settings()
{
    //qDebug() << QSqlDatabase::drivers();
    mydb.close();
}

void save_settings::save(QString poleWartosc, QString poleNazwa)
{
    if(!mydb.isOpen())
        {
            qDebug() << "Problem z połączeniem do bazy (save_settings::load QString) :(";
        }

        QSqlQuery qry(mydb);
//        qDebug() << "[+] Driver " << qry.driver();
        if(qry.exec("INSERT OR REPLACE INTO INNE_POLA (NAZWA_POLA, VAL, MY_DATA) VALUES (\'" + poleNazwa + "\',\'" + poleWartosc + "\',\'GETDATE()\')"))
            //INTO names (id, name) VALUES (1, "John")       \'" + Username + "\'
        //if(qry.exec("SELECT VAL FROM INNE_POLA WHERE NAZWA_POLA = \'" + pole_do_zaladowania + "\' LIMIT 1"))
        {
            if(qry.next())
            {
                qDebug() << "[+] Wstawienie / update wiersza " + poleNazwa + " ";
//                qDebug() << "[+] Result 0 = " << qry.lastError();
                //qDebug() << "[+] Value 0 = " +qry.value(0).toString();
                //return qry.value(0).toString();
            }else{
                //qDebug() <<"[!] Nie udało się wykonać qry.next(): INSERT OR REPLACE INTO INNE_POLA (NAZWA_POLA, VAL, MY_DATA) VALUES (\'" + poleNazwa + "\',\'" + poleWartosc + "\',\'GETDATE()\')";
                qDebug() << "[+] Wstawienie / update wiersza " + poleNazwa + " ";
                qDebug() << "[+] !Result 0 = " << qry.lastError();
            }
        }else{
            qDebug() << "[!] Nie udało się wykonać zapytania: INSERT OR REPLACE INTO INNE_POLA (NAZWA_POLA, VAL, MY_DATA) VALUES (\'" + poleNazwa + "\',\'" + poleWartosc + "\',\'GETDATE()\')";
            qDebug() << "[+] Wstawienie / update wiersza " + poleNazwa + " ";
            qDebug() << "[+] !!Result 0 = " << qry.lastError();
        }
        //return 0;
}




/* STARY LOAD */

QString save_settings::load(QString pole_do_zaladowania)
{
    if(!mydb.isOpen())
        {
            //qDebug() << QSqlDatabase::drivers();
            qDebug() << "Problem z połączeniem do bazy (save_settings::save QString) :(";
            return "";
        }
qDebug() << QSqlDatabase::drivers();
        QSqlQuery qry(mydb);
        if(qry.exec("SELECT VAL FROM INNE_POLA WHERE NAZWA_POLA = \'" + pole_do_zaladowania + "\' LIMIT 1"))
        {
            if(qry.next())
            {
//                qDebug() << "[+] Zapytanie o " + pole_do_zaladowania + " ";
//                qDebug() << "[+] Value 0 = " +qry.value(0).toString();
                //qDebug() << QSqlDatabase::drivers();
                //qDebug() << "[+] Value 1 = " +qry.value(1).toString();
                return qry.value(0).toString();
            }else{
                qDebug() <<"[!] Nie udało się wykonać qry.next(): SELECT VAL FROM INNE_POLA WHERE NAZWA_POLA = \'" + pole_do_zaladowania + "\' LIMIT 1";
            }
        }else{
            qDebug() << "[!] Nie udało się wykonać zapytania: SELECT VAL FROM INNE_POLA WHERE NAZWA_POLA = \'" + pole_do_zaladowania + "\' LIMIT 1";
        }
    return qry.value(0).toString();
}

 //dodać funkcję sprawdzającą, czy nie podano ścieżki do innej bazy.
 //usunąć warningi




QString save_settings::checkParamsToOtherSqlPatch(int argc, char *argv[])
{
    QString path = argv[0];
    path.replace(QString("/MasterOfPuppets/MasterOfPuppets"), QString("/MasterOfPuppets/sqlsave.sqlite"));
    do
    {
        //qDebug() << QSqlDatabase::drivers();
       if(false)
       {
           path = argv[0];
       }
    }
    while(argc == 0);
    return path;
}

void saveTableCreation()
{
}

void saveDbCreation()
{
}

//void

QString save_settings::db_ask_tab(char tab,int no)
{
    switch (tab) {
       // case 'postgres': {
        break;}
    //}
    //QSqlQuery.prepare();
    return "";
}

QString save_settings::db_ask_no(char tab,int no)
{
    switch (no) {
        //case 'postgres': {
        break;}
    //}
    //QSqlQuery.prepare();
    return "";
}
