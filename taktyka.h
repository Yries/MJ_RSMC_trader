#ifndef TAKTYKA_H
#define TAKTYKA_H
#include <QDebug>
//#include
#include "klient.h"


class Taktyka
{
public:
    Taktyka();
    ~Taktyka();
    void check_open_position();
    //sprawdź bazę postgres
    //sprawdź tradera
    //czy dodać pozycje w traderze do obserwowanych
    //co, jeśli brakuje pozycji - zgłoś i czy coś jeszcze?
    void open_connect();
    //void nowe_zagranie(klient k);
    void zamknij_zagranie();
    void sprawdz_pozycje_na_parze();

};

#endif // TAKTYKA_H
