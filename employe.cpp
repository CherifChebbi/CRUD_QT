#include "employe.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>

#include<QSqlError>
#include <QDebug>
#include <QObject>
#include <QDate>

Employe::Employe()
{
    identifiant=0;
    cin=0;
    nom=" ";
    prenom=" ";
    fonctionnalites=" ";
    grade=" ";

}

Employe::Employe(int identifiant,int cin,QString nom,QString prenom,QString fonctionnalites,QString grade)
{
    this->identifiant=identifiant;
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->fonctionnalites=fonctionnalites;
    this->grade=grade;
}

int Employe::getidentifiant(){return identifiant;}
int Employe::getcin(){return cin;}
QString Employe::getnom(){return nom;}
QString Employe::getprenom(){return prenom;}
QString Employe::getfonctionnalites(){return fonctionnalites;}
QString Employe::getgrade(){return grade;}




void Employe::setidentifiant(int identifiant){this->identifiant=identifiant;}
void Employe::setcin(int cin){this->cin=cin;}
void Employe::setnom(QString nom){this->nom=nom;}
void Employe::setprenom(QString prenom){this->prenom=prenom;}
void Employe::setfonctionnalites(QString fonctionnalites){this->fonctionnalites=fonctionnalites;}
void Employe::setgrade(QString grade){this->grade=grade;}

////////////////////////////////////////////////////////////////////////////////////////////////
//CRUD

bool Employe::ajouter()
{
    Employe E;
        QSqlQuery query;
        QString res = QString::number(identifiant);

            query.prepare("INSERT INTO EMPLOYE(IDENTIFIANT,NOM,PRENOM,CIN,FONCTIONNALITES,GRADE) "
                          "VALUES (:identifiant,:nom,:prenom,:cin,:fonctionnalites,:grade)");

            query.bindValue(":identifiant",res);
            query.bindValue(":nom",nom);
            query.bindValue(":prenom",prenom);
            query.bindValue(":cin",cin);
            query.bindValue(":fonctionnalites",fonctionnalites);
            query.bindValue(":grade",grade);


             return query.exec();

            qDebug() <<query.lastError();
}
QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

            model->setQuery("SELECT* FROM EMPLOYE ");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("FONCTIONNALITES"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("GRADE"));

        return  model;

}
bool Employe::supprimer(int identifiant )
{
    QSqlQuery query;

            query.prepare("Delete from Employe where IDENTIFIANT=:identifiant");
            query.bindValue(":identifiant",identifiant);

          return query.exec();
}
bool Employe:: modifier()
{
    bool test2=true;
        QSqlQuery query;

        query.prepare("UPDATE EMPLOYE SET IDENTIFIANT=:identifiant, NOM=:nom,PRENOM=:prenom,CIN=:cin,FONCTIONNALITES=:fonctionnalites,GRADE=:grade WHERE IDENTIFIANT=:identifiant");

        query.bindValue(":identifiant",identifiant);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":cin",cin);
        query.bindValue(":fonctionnalites",fonctionnalites);
        query.bindValue(":grade",grade);
        query.exec();

        qDebug() <<query.lastError();
            return  test2;


}












