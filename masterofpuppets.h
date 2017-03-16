#ifndef MASTEROFPUPPETS_H
#define MASTEROFPUPPETS_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include "ui_masterofpuppets.h"
#include "save_settings.h"
#include "db_conn.h"

namespace Ui {
class MasterOfPuppets;
}
class MasterOfPuppets : public QMainWindow
{
    Q_OBJECT

public:
    explicit MasterOfPuppets(int argc, char *argv[],db_conn* , db_conn* , db_conn* , QWidget *parent = 0);
    virtual ~MasterOfPuppets();
    int margc;// = argc;
    char **mpath;
    bool ok;
    db_conn *pTest;
    db_conn *pProd;
    db_conn *pTF;

    int insertRowIntoTableWidget(QString typ,QString ip,QString paraWal);
    void delRowFromTableWidgewt (int ID);


private slots:
    void on_buttConnectDB1_clicked();
    void on_buttConnectDB2_clicked();
    void on_buttConnectDB3_clicked();
    void on_pushButtonArmagedon_clicked();

private:
    Ui::MasterOfPuppets *ui;
};

#endif // MASTEROFPUPPETS_H
