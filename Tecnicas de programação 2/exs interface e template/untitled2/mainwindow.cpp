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


void MainWindow::on_pushButton_7_clicked()
{//instaciar INT a
    if (b)
        delete b;
    b=nullptr;
    int n1,n2;
    n1=ui->lineEdit->text().toInt();
    n2=ui->lineEdit_2->text().toInt();
    a=new Calculadora<int>(n1,n2);
    ui->textEdit->setText("Int Instanciado");
}

void MainWindow::on_pushButton_clicked()
{//instanciar FLOAT b
    if (a)
        delete a;
    a=nullptr;
    float n1,n2;
    n1=ui->lineEdit->text().toFloat();
    n2=ui->lineEdit_2->text().toFloat();
    b=new Calculadora<float>(n1,n2);
    ui->textEdit->setText("Float Instanciado");
}

void MainWindow::on_pushButton_5_clicked()
{//print
    if (a)
    {
        ui->textEdit->setText(a->print());
    }
    else
    {
        if (b)
        {
            ui->textEdit->setText(b->print());
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{//+
    if (a)
    {
        int x=a->adicionar(ui->lineEdit->text().toInt(),ui->lineEdit_2->text().toInt());
        ui->textEdit->setText(QString::number(x));
    }
    else
    {
        if (b)
        {
            float x=b->adicionar(ui->lineEdit->text().toFloat(),ui->lineEdit_2->text().toFloat());
            ui->textEdit->setText(QString::number(x));
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{//*
    if (a)
    {
        int x=a->multiplicar(ui->lineEdit->text().toInt(),ui->lineEdit_2->text().toInt());
        ui->textEdit->setText(QString::number(x));
    }
    else
    {
        if (b)
        {
            float x=b->multiplicar(ui->lineEdit->text().toFloat(),ui->lineEdit_2->text().toFloat());
            ui->textEdit->setText(QString::number(x));
        }
    }
}

void MainWindow::on_pushButton_6_clicked()
{//-
    if (a)
    {
        int x=a->subtrair(ui->lineEdit->text().toInt(),ui->lineEdit_2->text().toInt());
        ui->textEdit->setText(QString::number(x));
    }
    else
    {
        if (b)
        {
            float x=b->subtrair(ui->lineEdit->text().toFloat(),ui->lineEdit_2->text().toFloat());
            ui->textEdit->setText(QString::number(x));
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{// /
    if (a)
    {
        try {
            int x=a->dividir(ui->lineEdit->text().toInt(),ui->lineEdit_2->text().toInt());
            ui->textEdit->setText(QString::number(x));
        } catch (QString e) {
            ui->textEdit->setText(e);
        }
    }
    else
    {
        if (b)
        {
            try {
                float x=b->dividir(ui->lineEdit->text().toFloat(),ui->lineEdit_2->text().toFloat());
                ui->textEdit->setText(QString::number(x));
            } catch (QString e) {
                ui->textEdit->setText(e);
            }
        }
    }
}
