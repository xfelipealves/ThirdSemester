#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i=0;i<10;i++)
    {
        P[i]=nullptr;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{//ALOCAR HOMEM
    bool x=true;
    for (int i=0;i<10;i++)
    {
        if (P[i]==nullptr)
        {
            P[i]=new Homem;
            i=10;
            x=false;
            ui->textEdit->setText("Alocado Homem");
        }
    }
    if (x)
    {
        ui->textEdit->setText("Nao tem espaco");
    }
}

void MainWindow::on_pushButton_2_clicked()
{//ALOCAR CAO
    bool x=true;
    for (int i=0;i<10;i++)
    {
        if (P[i]==nullptr)
        {
            P[i]=new Cao;
            i=10;
            x=false;
            ui->textEdit->setText("Alocado Cao");
        }
    }
    if (x)
    {
        ui->textEdit->setText("Nao tem espaco");
    }
}

void MainWindow::on_pushButton_3_clicked()
{//ALOCAR GATO
    bool x=true;
    for (int i=0;i<10;i++)
    {
        if (P[i]==nullptr)
        {
            P[i]=new Gato;
            i=10;
            x=false;
            ui->textEdit->setText("Alocado Gato");
        }
    }
    if (x)
    {
        ui->textEdit->setText("Nao tem espaco");
    }
}

void MainWindow::on_pushButton_5_clicked()
{//LOOP
    QString x="";
    for (int i=0;i<10 and P[i];i++)
    {
        x=x+P[i]->falar()+" ";
    }
    ui->textEdit->setText(x);
}

void MainWindow::on_pushButton_4_clicked()
{//LIMPAR VETOR
    for (int i=0;i<10;i++)
    {
        if (P[i])
            P[i]=nullptr;
    }
    ui->textEdit->setText("VETOR LIMPADO");
}
