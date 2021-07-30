#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "QLineEdit"
#include "QTextEdit"
#include "Racional.h"
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


void MainWindow::on_pushButton_OBTER1_clicked()
{
    try {
        NumBrabo::Racional n1(ui->lineEdit_NUM1->text().toInt(), ui->lineEdit_DEN1->text().toInt());
        ui->textEdit->setText(n1.obterRacional());
    } catch (const char* c) {
        ui->textEdit->setText(c);
    }
}

void MainWindow::on_pushButton_OBTER2_clicked()
{
    try {
        NumBrabo::Racional n1(ui->lineEdit_NUM2->text().toInt(), ui->lineEdit_DEN2->text().toInt());
        ui->textEdit->setText(n1.obterRacional());
    } catch (const char* c) {
        ui->textEdit->setText(c);
    }
}

void MainWindow::on_pushButton_MAIS_clicked()
{
    try {
        NumBrabo::Racional n1(ui->lineEdit_NUM1->text().toInt(), ui->lineEdit_DEN1->text().toInt());
        NumBrabo::Racional n2(ui->lineEdit_NUM2->text().toInt(), ui->lineEdit_DEN2->text().toInt());
        NumBrabo::Racional n3=n1+n2;
        ui->textEdit->setText(n3.obterRacional());
    } catch (const char* c) {
        ui->textEdit->setText(c);
    }
}

void MainWindow::on_pushButton_MENOS_clicked()
{
    try {
        NumBrabo::Racional n1(ui->lineEdit_NUM1->text().toInt(), ui->lineEdit_DEN1->text().toInt());
        NumBrabo::Racional n2(ui->lineEdit_NUM2->text().toInt(), ui->lineEdit_DEN2->text().toInt());
        NumBrabo::Racional n3=n1-n2;
        ui->textEdit->setText(n3.obterRacional());
    } catch (const char* c) {
        ui->textEdit->setText(c);
    }
}

void MainWindow::on_pushButton_IGUAL_clicked()
{
    try {
        NumBrabo::Racional n1(ui->lineEdit_NUM1->text().toInt(), ui->lineEdit_DEN1->text().toInt());
        NumBrabo::Racional n2(ui->lineEdit_NUM2->text().toInt(), ui->lineEdit_DEN2->text().toInt());
        QString x;
        if (n1==n2)
        {
            x="Sim";
        }
        else
        {
            x="Não";
        }
        ui->textEdit->setText(x);
    } catch (const char* c) {
        ui->textEdit->setText(c);
    }
}

void MainWindow::on_pushButton_VEZES_clicked()
{
    try {
        NumBrabo::Racional n1(ui->lineEdit_NUM1->text().toInt(), ui->lineEdit_DEN1->text().toInt());
        NumBrabo::Racional n2(ui->lineEdit_NUM2->text().toInt(), ui->lineEdit_DEN2->text().toInt());
        NumBrabo::Racional n3=n1*n2;
        ui->textEdit->setText(n3.obterRacional());
    } catch (const char* c) {
        ui->textEdit->setText(c);
    }
}

void MainWindow::on_pushButton_DIVIDE_clicked()
{
    try {
        NumBrabo::Racional n1(ui->lineEdit_NUM1->text().toInt(), ui->lineEdit_DEN1->text().toInt());
        NumBrabo::Racional n2(ui->lineEdit_NUM2->text().toInt(), ui->lineEdit_DEN2->text().toInt());
        NumBrabo::Racional n3=n1/n2;
        ui->textEdit->setText(n3.obterRacional());
    } catch (const char* c) {
        ui->textEdit->setText(c);
    }
}
