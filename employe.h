#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>
#include <QString>

class Employe
{

private:
    int identifiant;
    int cin ;
    QString nom;
    QString prenom;
    QString fonctionnalites;
    QString grade ;


public:
    Employe();
    Employe(int,int,QString,QString,QString,QString);
    
    int getidentifiant();
    int getcin();
    QString getnom();
    QString getprenom();
    QString getfonctionnalites();
    QString getgrade();
    void setidentifiant(int);
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setfonctionnalites(QString);
    void setgrade(QString);
    
    //crud

        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int);
        bool  modifier();
};



#endif // EMPLOYE_H
