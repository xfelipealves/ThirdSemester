#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "Caminhao.h"
#include "CarroPasseio.h"
#include "Motor.h"
#include "Veiculo.h"
#include <QMessageBox>
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

    void on_CriaCarro_clicked();

    void on_printCarro_clicked();

    void on_CriaCaminhao_clicked();

    void on_printCaminhao_clicked();


private:
    Ui::MainWindow *ui;
    trab::Motor *Veiculo=nullptr;
    trab::Veiculo *Motor=nullptr;
};
#endif // MAINWINDOW_H
