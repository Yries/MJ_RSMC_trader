#include "db_conn.h"

db_conn::db_conn()
{
    qDebug() << "pgdb_test.isDriverAvailable(lite);" << pgdb_test.isDriverAvailable("lite");
        qDebug() << "pgdb_test.drivers();" <<pgdb_test.drivers();
        qDebug() << "<< QSqlDatabase::drivers()" << QSqlDatabase::drivers();
    qDebug() <<"[+]Konstruktor baz pg :)";
}

QSqlDatabase db_conn::pgdb_test = QSqlDatabase::addDatabase("QPSQL","mypostgres_test");
QSqlDatabase db_conn::pgdb_prod = QSqlDatabase::addDatabase("QPSQL","mypostgres_prod");
QSqlDatabase db_conn::pgdb_tf = QSqlDatabase::addDatabase("QPSQL","mypostgres_tf");

db_conn::db_conn(QString host, int port, QString user, QString pass, QString dbname, QString typ) //: QSqlDatabase()
{

if(typ == "pgtest"){
    /*DEBUG*/
    qDebug() << "pgdb_test.isDriverAvailable(lite);" << pgdb_test.isDriverAvailable("lite");
    qDebug() << "pgdb_test.drivers();" <<pgdb_test.drivers();
    qDebug() << "<< QSqlDatabase::drivers()" << QSqlDatabase::drivers();
    qDebug() << "<< QSqlDatabase::isDriverAvailable(lite)" << QSqlDatabase::isDriverAvailable("lite");
    qDebug() << "<< QSqlDatabase::isDriverAvailable(typ);" << QSqlDatabase::isDriverAvailable(typ);
    qDebug() << "Błąd otworzenia: " << pgdb_test.isOpenError();
    qDebug() << "Czy jest otwarta: "<< pgdb_test.isOpen();
    //qDebug() << pgdb_test
    /*DEBUG*/


    if(test_conn(host)){
            //pgdb_test.setConnectOptions("POLICY_DB_DEFAULT=None; POLICY_DB_WRITE=sid[0x12345678], WriteDeviceData");
            pgdb_test.setDatabaseName(dbname);
            pgdb_test.setHostName(host);
            pgdb_test.setPort(port);
            pgdb_test.setUserName(user);
            pgdb_test.setPassword(pass);

            if(pgdb_test.open()){
                qDebug() <<"[+]Połączono z bazą pg :)";
            }else{
                qDebug() <<"[!] Nie udało się połączyć z bazą pg :(";
        }

        /*DEBUG*/

            qDebug() << "pgdb_test.isDriverAvailable(lite);" << pgdb_test.isDriverAvailable("lite");
                qDebug() << "pgdb_test.drivers();" <<pgdb_test.drivers();
                qDebug() << "<< QSqlDatabase::drivers()" << QSqlDatabase::drivers();
                qDebug() << "<< QSqlDatabase::isDriverAvailable(lite)" << QSqlDatabase::isDriverAvailable("lite");
                 qDebug() << "<< QSqlDatabase::isDriverAvailable(typ);" << QSqlDatabase::isDriverAvailable(typ);
                 qDebug() << "Błąd otworzenia: " << pgdb_test.isOpenError();
                 qDebug() << "Czy jest otwarta: "<< pgdb_test.isOpen();
        /*DEBUG*/
    }
}

if(typ == "pgprod"){
    /*DEBUG*/
    qDebug() << "pgdb_prod.isDriverAvailable(lite);" << pgdb_prod.isDriverAvailable("lite");
    qDebug() << "pgdb_prod.drivers();" <<pgdb_prod.drivers();
    qDebug() << "<< QSqlDatabase::drivers()" << QSqlDatabase::drivers();
    qDebug() << "<< QSqlDatabase::isDriverAvailable(lite)" << QSqlDatabase::isDriverAvailable("lite");
    qDebug() << "<< QSqlDatabase::isDriverAvailable(typ);" << QSqlDatabase::isDriverAvailable(typ);
    qDebug() << "Błąd otworzenia: " << pgdb_prod.isOpenError();
    qDebug() << "Czy jest otwarta: "<< pgdb_prod.isOpen();
    //qDebug() << pgdb_prod
    /*DEBUG*/


    if(test_conn(host)){
            //pgdb_prod.setConnectOptions("POLICY_DB_DEFAULT=None; POLICY_DB_WRITE=sid[0x12345678], WriteDeviceData");
            pgdb_prod.setDatabaseName(dbname);
            pgdb_prod.setHostName(host);
            pgdb_prod.setPort(port);
            pgdb_prod.setUserName(user);
            pgdb_prod.setPassword(pass);

            if(pgdb_prod.open()){
                qDebug() <<"[+]Połączono z bazą pg :)";
            }else{
                qDebug() <<"[!] Nie udało się połączyć z bazą pg :(";
        }

        /*DEBUG*/

            qDebug() << "pgdb_prod.isDriverAvailable(lite);" << pgdb_prod.isDriverAvailable("lite");
                qDebug() << "pgdb_prod.drivers();" <<pgdb_prod.drivers();
                qDebug() << "<< QSqlDatabase::drivers()" << QSqlDatabase::drivers();
                qDebug() << "<< QSqlDatabase::isDriverAvailable(lite)" << QSqlDatabase::isDriverAvailable("lite");
                 qDebug() << "<< QSqlDatabase::isDriverAvailable(typ);" << QSqlDatabase::isDriverAvailable(typ);
                 qDebug() << "Błąd otworzenia: " << pgdb_prod.isOpenError();
                 qDebug() << "Czy jest otwarta: "<< pgdb_prod.isOpen();
        /*DEBUG*/
    }
}

if(typ == "pgtf"){
    /*DEBUG*/
    qDebug() << "pgdb_tf.isDriverAvailable(lite);" << pgdb_tf.isDriverAvailable("lite");
    qDebug() << "pgdb_tf.drivers();" <<pgdb_tf.drivers();
    qDebug() << "<< QSqlDatabase::drivers()" << QSqlDatabase::drivers();
    qDebug() << "<< QSqlDatabase::isDriverAvailable(lite)" << QSqlDatabase::isDriverAvailable("lite");
    qDebug() << "<< QSqlDatabase::isDriverAvailable(typ);" << QSqlDatabase::isDriverAvailable(typ);
    qDebug() << "Błąd otworzenia: " << pgdb_tf.isOpenError();
    qDebug() << "Czy jest otwarta: "<< pgdb_tf.isOpen();
    //qDebug() << pgdb_tf
    /*DEBUG*/


    if(test_conn(host)){
            //pgdb_tf.setConnectOptions("POLICY_DB_DEFAULT=None; POLICY_DB_WRITE=sid[0x12345678], WriteDeviceData");
            pgdb_tf.setDatabaseName(dbname);
            pgdb_tf.setHostName(host);
            pgdb_tf.setPort(port);
            pgdb_tf.setUserName(user);
            pgdb_tf.setPassword(pass);

            if(pgdb_tf.open()){
                qDebug() <<"[+]Połączono z bazą pg :)";
            }else{
                qDebug() <<"[!] Nie udało się połączyć z bazą pg :(";
        }

        /*DEBUG*/

            qDebug() << "pgdb_tf.isDriverAvailable(lite);" << pgdb_tf.isDriverAvailable("lite");
                qDebug() << "pgdb_tf.drivers();" <<pgdb_tf.drivers();
                qDebug() << "<< QSqlDatabase::drivers()" << QSqlDatabase::drivers();
                qDebug() << "<< QSqlDatabase::isDriverAvailable(lite)" << QSqlDatabase::isDriverAvailable("lite");
                 qDebug() << "<< QSqlDatabase::isDriverAvailable(typ);" << QSqlDatabase::isDriverAvailable(typ);
                 qDebug() << "Błąd otworzenia: " << pgdb_tf.isOpenError();
                 qDebug() << "Czy jest otwarta: "<< pgdb_tf.isOpen();
        /*DEBUG*/
    }
}

}

/************baza dynamicznie************/
//test
QSqlDatabase db_conn::_pgdb_test()
{
    qDebug() << QSqlDatabase::drivers();
    return pgdb_test;
}

db_conn *db_conn::_obj_pgdb_test()
{
    qDebug() << QSqlDatabase::drivers();
    if(!obj_pgdb_test)
    {
        qDebug() << QSqlDatabase::drivers();
        obj_pgdb_test = new db_conn();
    }
    return obj_pgdb_test;
}

db_conn *db_conn::obj_pgdb_test = new db_conn;
//prod
QSqlDatabase db_conn::_pgdb_prod()
{
    qDebug() << QSqlDatabase::drivers();
    return pgdb_prod;
}

db_conn *db_conn::_obj_pgdb_prod()
{
    qDebug() << QSqlDatabase::drivers();
    if(!obj_pgdb_prod)
    {
        qDebug() << QSqlDatabase::drivers();
        obj_pgdb_prod = new db_conn();
    }
    return obj_pgdb_prod;
}

db_conn *db_conn::obj_pgdb_prod = new db_conn;
//tf
QSqlDatabase db_conn::_pgdb_tf()
{
    qDebug() << QSqlDatabase::drivers();
    return pgdb_tf;
}

db_conn *db_conn::_obj_pgdb_tf()
{
    qDebug() << QSqlDatabase::drivers();
    if(!obj_pgdb_tf)
    {
        qDebug() << QSqlDatabase::drivers();
        obj_pgdb_tf = new db_conn();
    }
    return obj_pgdb_tf;
}

db_conn *db_conn::obj_pgdb_tf = new db_conn;
/************baza dynamicznie************/

db_conn::~db_conn()
{
    qDebug() <<"[+]Rozłączono z bazą pg :)";
    //pgdb.close();
}

bool db_conn::test_conn(QString host)
{
    return 1;
    // TYMCZASOWO, POPRAWIĆ
}

/*=================NOWE ZAPYTANIA===============*/

void insertyKonta(
        QString Baza,
        int KOntoID,
        QString KOnto_BROKER,
        QString KOnto_Dzwignia,
        bool KOnto_SPREAD,
        QString KOntoDLL)
{
    QSqlDatabase *bierzacaBaza = NULL;
    QString fQuery("INSERT INTO public.\"WALUTY\"(\"WA_KOD\") VALUES ( :Waluta );");
    if(Baza == "pgtest") bierzacaBaza = &db_conn::pgdb_test;
    if(Baza == "pgtprod") bierzacaBaza = &db_conn::pgdb_prod;
    if(Baza == "pgtf") bierzacaBaza = &db_conn::pgdb_tf;
    QSqlQuery qry( *bierzacaBaza );
    qry.prepare(fQuery);
    //qry.bindValue(":Waluta", Waluta);
    if(! bierzacaBaza->isOpen())
        {
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< bierzacaBaza->lastError().text() << "\n"<< QSqlDatabase::drivers();
        }
    else{
        if(qry.exec()){
            //qDebug() << "Wstawiono rekord do tabeli walut: " << Baza << ", " << Waluta;
        }
        else{
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< qry.lastError().text() << "\n"<< QSqlDatabase::drivers() << "\n";
        }
    }
}

void insertKursParyGlownej( // KPG - kurs pary głównej
        QString Baza,
        int KPG_ID,
        float KPG_CenaSell,
        float KPG_CenaBuy,
        QString KPG_Time,
        float KPG_Opor24,
        float KPG_Wsparcie24,
        float KPG_Opor1,
        float KPG_Wsparcie1,
        QString KPG_Waluta_Pierwotna,
        QString KPG_Odniesienia
        )
{
    QSqlDatabase *bierzacaBaza = NULL;
    QString fQuery("INSERT INTO public.\"WALUTY\"(\"WA_KOD\") VALUES ( :Waluta );");
    if(Baza == "pgtest") bierzacaBaza = &db_conn::pgdb_test;
    if(Baza == "pgtprod") bierzacaBaza = &db_conn::pgdb_prod;
    if(Baza == "pgtf") bierzacaBaza = &db_conn::pgdb_tf;
    QSqlQuery qry( *bierzacaBaza );
    qry.prepare(fQuery);
    //qry.bindValue(":Waluta", Waluta);
    if(! bierzacaBaza->isOpen())
        {
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< bierzacaBaza->lastError().text() << "\n"<< QSqlDatabase::drivers();
        }
    else{
        if(qry.exec()){
            //qDebug() << "Wstawiono rekord do tabeli walut: " << Baza << ", " << Waluta;
        }
        else{
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< qry.lastError().text() << "\n"<< QSqlDatabase::drivers() << "\n";
        }
    }
}

void insertKontaWalutyDelta(  // kurs na danym koncie
        QString Baza,
        int KOntoID,
        int KPG_ID,
        QString KPG_Waluta_Pierwotna,
        QString KPG_Odniesienia)
{
    QSqlDatabase *bierzacaBaza = NULL;
    QString fQuery("INSERT INTO public.\"WALUTY\"(\"WA_KOD\") VALUES ( :Waluta );");
    if(Baza == "pgtest") bierzacaBaza = &db_conn::pgdb_test;
    if(Baza == "pgtprod") bierzacaBaza = &db_conn::pgdb_prod;
    if(Baza == "pgtf") bierzacaBaza = &db_conn::pgdb_tf;
    QSqlQuery qry( *bierzacaBaza );
    qry.prepare(fQuery);
    //qry.bindValue(":Waluta", Waluta);
    if(! bierzacaBaza->isOpen())
        {
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< bierzacaBaza->lastError().text() << "\n"<< QSqlDatabase::drivers();
        }
    else{
        if(qry.exec()){
            //qDebug() << "Wstawiono rekord do tabeli walut: " << Baza << ", " << Waluta;
        }
        else{
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< qry.lastError().text() << "\n"<< QSqlDatabase::drivers() << "\n";
        }
    }
}


void insertLogTransakcji(
        QString Baza,
        QString LOGT_KTO_Konto,
        QString LOGT_KTO_Maszyna,
        QString LOGT_KTO_CzlowiekMaszyna,
        QString LOGT_CO_Towar,
        QString LOGT_CO_Wolumen,
        QString LOGT_CO_Wartosc,
        QString LOGT_CO_Long_Short,
        /*===data=== do zmiennej LOGT_KIEDY_BAZA */
        QString LOGT_KIEDY_MT4,
        QString LOGT_KIEDY_SYSTEMOWY,
        QString LOGT_KIEDY_TERMIN_REALIZACJI,
        QString LOGT_KIEDY_CzyZrealizowano,
        QString LOGT_KIEDY_PowodTransakcji,
        QString LOGT_KIEDY_PerspektywaCzasowa,
        QString LOGT_Komentarz,
        QString LOGT_Obciazenie_Maszyny)
{
    QSqlDatabase *bierzacaBaza = NULL;
    QString fQuery("INSERT INTO public.\"WALUTY\"(\"WA_KOD\") VALUES ( :Waluta );");
    if(Baza == "pgtest") bierzacaBaza = &db_conn::pgdb_test;
    if(Baza == "pgtprod") bierzacaBaza = &db_conn::pgdb_prod;
    if(Baza == "pgtf") bierzacaBaza = &db_conn::pgdb_tf;
    QSqlQuery qry( *bierzacaBaza );
    qry.prepare(fQuery);
    //qry.bindValue(":Waluta", Waluta);
    if(! bierzacaBaza->isOpen())
        {
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< bierzacaBaza->lastError().text() << "\n"<< QSqlDatabase::drivers();
        }
    else{
        if(qry.exec()){
            //qDebug() << "Wstawiono rekord do tabeli walut: " << Baza << ", " << Waluta;
        }
        else{
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< qry.lastError().text() << "\n"<< QSqlDatabase::drivers() << "\n";
        }
    }
}


QString selectWaluta(//if exist else insert
        QString Baza,
        QString Waluta)
{
    QSqlDatabase *bierzacaBaza = NULL;
    QString fQuery("INSERT INTO public.\"WALUTY\"(\"WA_KOD\") VALUES ( :Waluta );");
    if(Baza == "pgtest") bierzacaBaza = &db_conn::pgdb_test;
    if(Baza == "pgtprod") bierzacaBaza = &db_conn::pgdb_prod;
    if(Baza == "pgtf") bierzacaBaza = &db_conn::pgdb_tf;
    QSqlQuery qry( *bierzacaBaza );
    qry.prepare(fQuery);
    qry.bindValue(":Waluta", Waluta);
    if(! bierzacaBaza->isOpen())
        {
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< bierzacaBaza->lastError().text() << "\n"<< QSqlDatabase::drivers();
        }
    else{
        if(qry.exec()){
            qDebug() << "Wstawiono rekord do tabeli walut: " << Baza << ", " << Waluta;
        }
        else{
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< qry.lastError().text() << "\n"<< QSqlDatabase::drivers() << "\n";
        }
    }
}

QString selectGeneral(
        QString Baza,
        QString Pole,
        QString Tabela,
        QString Warunek0 = NULL,
        QString Warunek1 = NULL,
        QString Warunek2 = NULL,
        QString Warunek3 = NULL,
        QString Warunek4 = NULL)
{
    QSqlDatabase bierzacaBaza;
    if(Baza == "pgtest") bierzacaBaza = db_conn::pgdb_test;
    if(Baza == "pgtprod") bierzacaBaza = db_conn::pgdb_prod;
    if(Baza == "pgtf") bierzacaBaza = db_conn::pgdb_tf;
}

QFile selectModelTF(
        QString Baza,
        QString Waluta)
{
    QSqlDatabase *bierzacaBaza = NULL;
    QString fQuery("INSERT INTO public.\"WALUTY\"(\"WA_KOD\") VALUES ( :Waluta );");
    if(Baza == "pgtest") bierzacaBaza = &db_conn::pgdb_test;
    if(Baza == "pgtprod") bierzacaBaza = &db_conn::pgdb_prod;
    if(Baza == "pgtf") bierzacaBaza = &db_conn::pgdb_tf;
    QSqlQuery qry( *bierzacaBaza );
    qry.prepare(fQuery);
    qry.bindValue(":Waluta", Waluta);
    if(! bierzacaBaza->isOpen())
        {
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< bierzacaBaza->lastError().text() << "\n"<< QSqlDatabase::drivers();
        }
    else{
        if(qry.exec()){
            qDebug() << "Wstawiono rekord do tabeli walut: " << Baza << ", " << Waluta;
        }
        else{
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< qry.lastError().text() << "\n"<< QSqlDatabase::drivers() << "\n";
        }
    }
}

void db_conn::insertWaluty(
        QString Baza,
        QString Waluta)
{
    QSqlDatabase *bierzacaBaza = NULL;
    QString fQuery("INSERT INTO public.\"WALUTY\"(\"WA_KOD\") VALUES ( :Waluta );");
    if(Baza == "pgtest") bierzacaBaza = &db_conn::pgdb_test;
    if(Baza == "pgtprod") bierzacaBaza = &db_conn::pgdb_prod;
    if(Baza == "pgtf") bierzacaBaza = &db_conn::pgdb_tf;
    QSqlQuery qry( *bierzacaBaza );
    qry.prepare(fQuery);
    qry.bindValue(":Waluta", Waluta);
    if(! bierzacaBaza->isOpen())
        {
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< bierzacaBaza->lastError().text() << "\n"<< QSqlDatabase::drivers();
        }
    else{
        if(qry.exec()){
            qDebug() << "Wstawiono rekord do tabeli walut: " << Baza << ", " << Waluta;
        }
        else{
            qDebug() << "[!] Problem z połączeniem do bazy (db_conn::insertWaluty) :( \n "<< qry.lastError().text() << "\n"<< QSqlDatabase::drivers() << "\n";
        }
    }
}
