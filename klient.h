#ifndef KLIENT_H
#define KLIENT_H

#include <QObject>
#include <QDebug>
#include <QList>
#include <QString>
#include <QtXml/QDomElement>
#include <QtXml/QtXml>


class klient : public QObject
{
    Q_OBJECT
public:
    explicit klient(QObject *parent = 0);


    struct klientSTR_TF{
        short myID;
        int buildDLL;
        short idListy;
        QString haslo;
        QString typKonta; //test/prod  tf ?

    };

//    void Mt4_conn_cli::authStep1()
//    {
//        //jakim jestem klientem
//        //dźwignia
//        //build dll
//        //konto mt4 / bossa
//        //dane konta
//        //para walutowa
//        //+reakcją jest nadanie id

//    }

//    void Mt4_conn_cli::authStep2()
//    {
//        //sprawdzenie przydzielonego ID
//        //zapisanie klienta
//        //timer do raportu
//    }

    struct klientSTR_ACC{
        short myID;
        int buildDLL;
        short idListy;
        QString haslo;
        QString typKonta; //test/prod  tf ?
    };

    static QList <klientSTR_ACC> listaKlientowTEST();
    static QList <klientSTR_ACC> listaKlientowPROD();
    static QList <klientSTR_TF> listaKlientowTF();

    //logika komunikacji z klientami
    //pisz xml
    QDomDocument dokument;

    //root element
    QDomElement root;

    //tworzenie dokumentu
    //QFile file("");

    void odczytajXML(QString przychodzace);

    //obsługa dynamicznych list klientów GUI
    void dodajKlienta(int ID, QString PARA, QString IP, int tablica);
    void usunKlienta(int ID);
    void stanKlienta(int ID);

    //zapytania
    void dodajKlientaPGSQL();
    void sprawdzKlientaPGSQL();



signals:

public slots:
};



#endif // KLIENT_H
