#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <FiguraGeometrica.h>
#include <Esfera.h>
#include <Cilindro.h>
#include <Cone.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void desabilitarRaio();
    void habilitarRaio();
    void desabilitarAltura();
    void habilitarAltura();
    void desabilitarResultado();
    void habilitarExecutar();
    void desabilitarExecutar();

private slots:

//    void on_radioButton_FiguraGeometrica_clicked();

    void on_pushButton_Executar_clicked();

    void on_radioButton_Esfera_clicked();

    void on_radioButton_Cilindro_clicked();

    void on_radioButton_Cone_clicked();

    void on_pushButton_Limpar_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
