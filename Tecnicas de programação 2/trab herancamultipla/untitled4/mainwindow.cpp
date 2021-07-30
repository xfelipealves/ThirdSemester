#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CriaCarro_clicked()
{
    try {
            Veiculo=new trab::CarroPasseio(ui->linePeso->text().toDouble(),ui->lineVelMax->text().toDouble(),ui->linePreco->text().toDouble(),
                             ui->lineNumCilindro->text().toInt(), ui->linePotencia->text().toInt(), ui->lineCor->text(),ui->lineModelo->text());
        ui->textEdit->setText("Objeto criado");
    } catch (QString e) {
        QMessageBox::information(this, "ERRO", e);
    }
}

void MainWindow::on_printCarro_clicked()
{
    ui->textEdit->setText(Veiculo->print());
}


void MainWindow::on_CriaCaminhao_clicked()
{
    try {
        Motor=new trab::Caminhao(ui->linePeso->text().toDouble(),ui->lineVelMax->text().toDouble(),ui->linePreco->text().toDouble(),
                         ui->lineNumCilindro->text().toInt(), ui->linePotencia->text().toInt(),ui->lineToneladas->text().toDouble(),
                         ui->lineAltMax->text().toDouble(),ui->lineComprimento->text().toDouble());
        ui->textEdit->setText("Objeto criado");

    } catch (QString e) {
        QMessageBox::information(this, "ERRO", e);
    }
}

void MainWindow::on_printCaminhao_clicked()
{
    ui->textEdit->setText(Motor->print());
}
