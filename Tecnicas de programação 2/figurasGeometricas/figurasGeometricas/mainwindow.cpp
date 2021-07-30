#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    desabilitarRaio();
    desabilitarAltura();
    desabilitarExecutar();
    desabilitarResultado();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::desabilitarRaio(){
    ui->lineEdit_Raio->setDisabled(true);
    ui->label_Raio->setDisabled(true);
}

void MainWindow::habilitarRaio(){
    ui->lineEdit_Raio->setDisabled(false);
    ui->label_Raio->setDisabled(false);
}

void MainWindow::desabilitarAltura(){
    ui->lineEdit_Altura->setDisabled(true);
    ui->label_Altura->setDisabled(true);
}

void MainWindow::habilitarAltura(){
    ui->lineEdit_Altura->setDisabled(false);
    ui->label_Altura->setDisabled(false);
}

void MainWindow::desabilitarResultado(){
    ui->textEdit_Resultado->setDisabled(true);
    ui->label_Resultado->setDisabled(true);
}


void MainWindow::desabilitarExecutar(){
    ui->pushButton_Executar->setDisabled(true);
}

void MainWindow::habilitarExecutar(){
    ui->pushButton_Executar->setDisabled(false);
}

void MainWindow::on_pushButton_Executar_clicked()
{
    try {
        /*if(ui->radioButton_FiguraGeometrica->isChecked()){
            TP2::FiguraGeometrica obj;
            ui->textEdit_Resultado->setText(obj.getTipoDaFigura());
        }
       else*/ if(ui->radioButton_Esfera->isChecked()){
            float r = ui->lineEdit_Raio->text().toFloat();
            TP2::Esfera objEsfera(r),*esf=0;
            TP2::FiguraGeometrica *obj=0;
            esf=&objEsfera;
            obj=&objEsfera;
            QString saida = obj->getTipoDaFigura();
            saida +="\nÁrea Total = "+QString::number(obj->calcularAreaTotal());
            saida += "\nVolume = "+QString::number(obj->calcularVolume());
            ui->textEdit_Resultado->setText(saida);
        }
        else if(ui->radioButton_Cilindro->isChecked()){
            float r = ui->lineEdit_Raio->text().toFloat();
            float h = ui->lineEdit_Altura->text().toFloat();
            TP2::Cilindro objCilindro(r,h);
            TP2::FiguraGeometrica *obj=0;
            obj=&objCilindro;
            QString saida = obj->getTipoDaFigura();
            saida += "\nÁrea Lateral = "+QString::number(objCilindro.calcularAreaLateral());
            saida += "\nÁrea Total = "+QString::number(objCilindro.calcularAreaTotal());
            saida += "\nVolume = "+QString::number(objCilindro.calcularVolume());
            ui->textEdit_Resultado->setText(saida);
        }
        else if(ui->radioButton_Cone->isChecked()){
            float r = ui->lineEdit_Raio->text().toFloat();
            float h = ui->lineEdit_Altura->text().toFloat();
            TP2::Cone objCone(r,h);
            QString saida = objCone.getTipoDaFigura();
            saida += "\nGeratriz = "+QString::number(objCone.calcularGeratriz());
            saida += "\nÁrea Lateral = "+QString::number(objCone.calcularAreaLateral());
            saida += "\nÁrea Total = "+QString::number(objCone.calcularAreaTotal());
            saida += "\nVolume = "+QString::number(objCone.calcularVolume());
            ui->textEdit_Resultado->setText(saida);
        }
        desabilitarExecutar();
    }catch(QString e)
    {
        QMessageBox::information(this, "ERRO", e);
    }

}

//void MainWindow::on_radioButton_FiguraGeometrica_clicked()
//{
//    desabilitarRaio();
//    desabilitarAltura();
//    habilitarExecutar();
//}

void MainWindow::on_radioButton_Esfera_clicked()
{
    desabilitarAltura();
    habilitarRaio();
    habilitarExecutar();
    ui->textEdit_Resultado->clear();
}

void MainWindow::on_radioButton_Cilindro_clicked()
{
    habilitarRaio();
    habilitarAltura();
    habilitarExecutar();
    ui->textEdit_Resultado->clear();
}

void MainWindow::on_radioButton_Cone_clicked()
{
    habilitarRaio();
    habilitarAltura();
    habilitarExecutar();
    ui->textEdit_Resultado->clear();
}

void MainWindow::on_pushButton_Limpar_clicked()
{

    ui->lineEdit_Raio->clear();
    ui->lineEdit_Altura->clear();
    ui->textEdit_Resultado->clear();

    desabilitarRaio();
    desabilitarAltura();
    desabilitarExecutar();

}
