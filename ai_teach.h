#ifndef AI_TEACH_H
#define AI_TEACH_H
#include <QDebug>

class AI_teach
{
public:
    AI_teach();
    ~AI_teach();
    void iterator_po_bazie(); //postgres
    void run_test();// na jakiej parze robiono testy, na jakich parach sprawdzano ?
    void add_to_list(); // do bazy i zapisz do pliku;
};

#endif // AI_TEACH_H
