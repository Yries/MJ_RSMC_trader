#include "masterofpuppets.h"


MasterOfPuppets::MasterOfPuppets(int argc, char *argv[],db_conn *pTest , db_conn *pProd , db_conn *pTF,  QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MasterOfPuppets)
{
    margc = argc;
    mpath = argv;
    qDebug() <<"[+]MasterOfPuppets konstruktor :)";
    ui->setupUi(this);    

    //wczytanie save z SQLite
    save_settings *mysave = new save_settings(argc, argv);
    foreach(QLineEdit* le, this->findChildren<QLineEdit*>()) {
        le->setText(mysave->load(le->objectName()));
    }
    delete mysave;
}

MasterOfPuppets::~MasterOfPuppets()
{   qDebug() <<"[+]MasterOfPuppets destruktor :)";

    //zapamiętanie zmian ustawień
    save_settings *mysave2 = new save_settings(margc, mpath);
    foreach(QLineEdit* le, this->findChildren<QLineEdit*>()) {
        mysave2->save(le->text(),le->objectName());
    }
    delete mysave2;
    delete ui;
}

// ====Moje funkcje====
// =tabelki klientów=
int MasterOfPuppets::insertRowIntoTableWidget(QString typ,QString ip,QString paraWal)
{
    if(typ == "prod")
    {
        ui->tableWidget_prod;
        qDebug() << "[+] Dodano klienta do listy" << typ << " " << ip << " " << paraWal;
    }else{
        if(typ == "test")
        {
            ui->tableWidget_test;
            qDebug() << "[+] Dodano klienta do listy" << typ << " " << ip << " " << paraWal;
        }else{
            qDebug() << "[-] Nie udało się dodać klienta do listy" << typ << " " << ip << " " << paraWal;
        }
    }
    return 1;//id
}

void MasterOfPuppets::delRowFromTableWidgewt (int ID)
{
    if(ID == 1)
    {
        ui->tableWidget_test;
        //qDebug() << "[+] Dodano klienta do listy" << typ << " " << ip << " " << paraWal;
    }else{
        //qDebug() << "[-] Nie udało się dodać klienta do listy" << typ << " " << ip << " " << paraWal;
    }
}

//QString host, int port, QString user, QString pass, QString dbname, QString typ

//BAZA 1
//guzik
void MasterOfPuppets::on_buttConnectDB1_clicked()
{
    pTest = new db_conn(ui->lineEditHostDB1->text(),(ui->lineEditPortDB1->text()).toInt(&ok,10),ui->lineEditUserDB1->text(),ui->lineEditPassDB1->text(), ui->lineEditNameDB1->text(),"pgtest");
    qDebug() <<"[+]MasterOfPuppets klik połączenia z bazą test :)";
    qDebug() << "line edit przed" << ui->lineEditPortDB1 <<   (ui->lineEditPortDB2->text()).toInt(&ok,10) << (ui->lineEditPortDB2->text()).toInt(&ok,5) ;
}

void MasterOfPuppets::on_buttConnectDB2_clicked()
{
    pProd = new db_conn(ui->lineEditHostDB2->text(),(ui->lineEditPortDB2->text()).toInt(&ok,10),ui->lineEditUserDB2->text(),ui->lineEditPassDB2->text(), ui->lineEditNameDB2->text(),"pgprod");
    qDebug() <<"[+]MasterOfPuppets klik połączenia z bazą prod :)";
    qDebug() << "line edit przed" << ui->lineEditPortDB2 <<   (ui->lineEditPortDB2->text()).toInt(&ok,10) << (ui->lineEditPortDB2->text()).toInt(&ok,5) ;
}

void MasterOfPuppets::on_buttConnectDB3_clicked()
{
    pTF = new db_conn(ui->lineEditHostDB3->text(),(ui->lineEditPortDB3->text()).toInt(&ok,10),ui->lineEditUserDB3->text(),ui->lineEditPassDB3->text(), ui->lineEditNameDB1->text(),"pgtf");
    qDebug() <<"[+]MasterOfPuppets klik połączenia z bazą tf :)";
    qDebug() << "line edit przed" << ui->lineEditPortDB3 <<   (ui->lineEditPortDB3->text()).toInt(&ok,10) << (ui->lineEditPortDB3->text()).toInt(&ok,5) ;
}

void MasterOfPuppets::on_pushButtonArmagedon_clicked()
{
    QString typ = "pgtest";
    QString pln = "EUR";
    pTest->insertWaluty(typ,pln);
}
