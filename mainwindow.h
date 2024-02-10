#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "employe.h"


#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
#include <QSqlQuery>
#include <QMainWindow>

#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>

#include "employe.h"
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSortFilterProxyModel *proxy;


private slots:

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifer_clicked();

private:
    Ui::MainWindow *ui;
    Employe E;


};

#endif // MAINWINDOW_H
