#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>






MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Employe E;

    ui->setupUi(this);
    ui->tab_employe->setModel(E.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_pb_ajouter_clicked()
{

    int identifiant=ui->le_id->text().toInt();
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fonctionnalites=ui->la_fonctionnalites->text();
    QString grade=ui->le_grade->text();

    Employe E(identifiant,cin,nom,prenom,fonctionnalites, grade);


     bool test=E.ajouter();
      QMessageBox msgBox;

     if (test)
     {
         ui->tab_employe->setModel(E.afficher());
         QMessageBox::information(nullptr, QObject::tr("OK"),
              QObject::tr("Ajout avec succès.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->le_id->clear();
         ui->le_nom->clear();
         ui->le_prenom->clear();
         ui->le_cin->clear();
         ui->la_fonctionnalites->clear();
         ui->le_grade->clear();

     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
               QObject::tr("Echec d'ajout.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

     }
}

void MainWindow::on_pb_supprimer_clicked()
{
    Employe E;

    E.setidentifiant(ui->le_id_supp->text().toInt());
    bool test=E.supprimer(E.getidentifiant());
       QMessageBox msgBox;

        if(test)
        {

               msgBox.setText("Suppression avec succès.");
             ui->tab_employe->setModel(E.afficher());

             ui->le_id_supp->clear();

        }
        else
        {
            msgBox.setText("Echec de suppression");
             ui->le_id_supp->clear();

        }
     msgBox.exec();
}




///////////////////////////////////////////

void MainWindow::on_pb_modifer_clicked()
{

    int identifiant=ui->le_id->text().toInt();
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fonctionnalites=ui->la_fonctionnalites->text();
    QString grade=ui->le_grade->text();


    Employe E1(identifiant,cin,nom,prenom,fonctionnalites, grade);

     bool test2=E1.modifier();


     if (test2)
     {
        QMessageBox::information(nullptr, QObject::tr("OK"),
              QObject::tr("Modification avec succés\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_employe->setModel(E1.afficher());

        ui->le_id->clear();
        ui->le_nom->clear();
        ui->le_prenom->clear();
        ui->le_cin->clear();
        ui->la_fonctionnalites->clear();
        ui->le_grade->clear();


     }
     else
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
               QObject::tr("Echec de modification.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

     ui->le_id->clear();
     ui->le_nom->clear();
     ui->le_prenom->clear();
     ui->le_cin->clear();
     ui->la_fonctionnalites->clear();
     ui->le_grade->clear();

}

/////////////////////////////////////////////////////////////////////////////////////

