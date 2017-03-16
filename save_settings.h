#ifndef SAVE_SETTINGS_H
#define SAVE_SETTINGS_H

#include <QString>
#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include <QSqlDatabase>

class save_settings : public QObject
{
    Q_OBJECT
    const QString sqlpath;

public:
    save_settings(int , char **);
    save_settings();
    ~save_settings();
    // STARY LOAD QString QString load(char,int);
    QString load(QString);
    void save(QString, QString);
    //save(char,int);

    /************baza dynamicznie************/
    static save_settings *obj_mydb;
    static save_settings *_obj_mydb();

    static QSqlDatabase mydb;
    static QSqlDatabase _mydb();

    /************baza dynamicznie************/

    QString checkParamsToOtherSqlPatch(int , char **);

    QString db_ask_tab(char,int);
    QString db_ask_no(char,int);

    void db_creation();
    void tab_creation();

    //pętla logów (+przyjęcie zadanej ilości logów przed przesianiem)

private:
    //QSqlDatabase mydb;
    void saveTableCreation();
    void saveDbCreation();
};

#endif // SAVE_SETTINGS_H
