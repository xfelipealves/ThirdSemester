#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Estudante.h"
#include "Funcionario.h"
#include "Monitor.h"
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
    void on_estudanteCriar_clicked();

    void on_estudanteImprimir_clicked();

    void on_funcionarioCriar_clicked();

    void on_funcionarioImprimir_clicked();

    void on_monitorCriar_clicked();

    void on_monitorIImprirmir_clicked();

private:
    Ui::MainWindow *ui;
    Estudante *bEstudante = nullptr;
    Funcionario *bFuncionario  = nullptr;
    Estudante *bMonitor  = nullptr;
};
#endif // MAINWINDOW_H
