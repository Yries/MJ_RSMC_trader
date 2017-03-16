#include "klient.h"

klient::klient(QObject *parent) : QObject(parent)
{
    root = dokument.createElement("root");
}

void klient::dodajKlienta(int ID, QString PARA, QString IP, int tablica)
{

}

void klient::usunKlienta(int ID)
{

}

void klient::stanKlienta(int ID)
{

}

void klient::dodajKlientaPGSQL()
{

}

void klient::sprawdzKlientaPGSQL()
{
//jeśli nie podał stanu, wywołane na timer
}
