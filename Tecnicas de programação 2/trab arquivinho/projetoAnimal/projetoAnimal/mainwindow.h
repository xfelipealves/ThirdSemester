#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include "Animal.h"
#include "Homem.h"
#include "Cao.h"
#include "Gato.h"
#include "Persistencia.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Executar_clicked();

    void on_pushButton_Excluir_clicked();

    void on_pushButton_Mostrar_clicked();

private:
    Ui::MainWindow *ui;
    TP2::Animal *vetor[10];
    int i=0;
    TP2::Persistencia *p = new TP2::Persistencia("arquivo.txt");
};
#endif // MAINWINDOW_H
