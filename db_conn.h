#ifndef DB_CONN_H
#define DB_CONN_H

//#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <string>
#include <QtSql>

class db_conn
{
    //Q_OBJECT
public:
    db_conn();
    db_conn(QString,int,QString,QString,QString,QString);
    ~db_conn();
    //void connect(QString,int,QString,QString,QString,QString);
    bool test_conn(QString);

    //z góry zakładam z iloma bazami będę się łączył
    //klasa QSqlDatabase wymaga rozłączania się z bazą
    //każdorazowe łączenie sie z bazą w celu odczytu/zapisu pojedyńczej linijki jest błędem

    //połączenie do testowej bazy danych
    static db_conn *obj_pgdb_test;
    static db_conn *_obj_pgdb_test();
    static QSqlDatabase pgdb_test;
    static QSqlDatabase _pgdb_test();
    //połączenie do produkcyjnej bazy danych
    static db_conn *obj_pgdb_prod;
    static db_conn *_obj_pgdb_prod();
    static QSqlDatabase pgdb_prod;
    static QSqlDatabase _pgdb_prod();
    //połączenie do bazy TensorFlow
    static db_conn *obj_pgdb_tf;
    static db_conn *_obj_pgdb_tf();
    static QSqlDatabase pgdb_tf;
    static QSqlDatabase _pgdb_tf();

    QSqlDatabase *pNoStatDBC;
    // hazard ?
    //ok zamiana na zmienną w funkcji


    QString selectorDB();
    /*inserty*/

    void insertyKonta(
            QString Baza,
            int KOntoID,
            QString KOnto_BROKER,
            QString KOnto_Dzwignia,
            bool KOnto_SPREAD,
            QString KOntoDLL);

    void insertWaluty(
            QString Baza,
            QString waluta);

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
            );

    void insertKontaWalutyDelta(  // kurs na danym koncie
            QString Baza,
            int KOntoID,
            int KPG_ID,
            QString KPG_Waluta_Pierwotna,
            QString KPG_Odniesienia);

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
            QString LOGT_Obciazenie_Maszyny);


    QString selectWaluta(
            QString Baza,
            QString waluta); //if exist else insert

    QString selectGeneral(
            QString Baza,
            QString Pole,
            QString Tabela,
            QString Warunek0 = NULL,
            QString Warunek1 = NULL,
            QString Warunek2 = NULL,
            QString Warunek3 = NULL,
            QString Warunek4 = NULL);

    QFile selectModelTF(
            QString Baza,
            QString typ);


    // test/prod
    void zaspisLogu(QString typ,
                              QString iLKK, QString iLKM, QString bLKCM,
                              QString iLCT, QString iLCWol, QString iLCWar,
                              QString iLCLS, /*===data===*/QString iLKmt4,
                              QString iLKsys, QString iLKtr, QString iLKcr,
                              QString iLpt, QString iLpc, QString iLkom, QString iLom);

    void zapisKonta(QString typ,long KONTO_ID,QString Broker, bool Spread, short Dzwignia);

    void zapisTick(QString typ, int KGPID, float KGP_CS, float KGP_CB, QString KGP_TIME, QString KGP_KWG, QString KGP_KWZ);

    void zapisTickDelta(QString typ);

    void cleanLog();
    // +odsiewanie logu - zakładamy, że logujemy WSZYSTKO, część logów możemy wywalić po np. 24h - regulowane
    // +metodę powinno dać sie czasowo zablokować - w przypadku crashu, na żądanie, lub np. kiedy baza nie jest zbytnio obciążona
    // metoda może wywołać porządkowanie bazy wbudowane w bazę (możliwe w PG)

    //tf

    void insertTestTF(long TestID, QString okres, float zyskStrata);

    //update test id
    void przeliczWynikiModelu(long TestId);

    /*selecty*/
    QString load(QString typ, QString pole_do_zaladowania);

    void zapiszModel(QString typ, QFile *plik, double skutecznosc, QString para, int dzwignia, long TestID );

//    QByteArray ba;
//    QFile f;
//    ba = f.readAll();
};

#endif // DB_CONN_H
