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


void MainWindow::on_pushButton_clicked()
{//cria PF
    try {
        pf=new Quest2::PessoaFisica(ui->lineNome->text(),ui->lineEndere->text(),ui->lineTelefone->text().toLong()
                                    ,ui->lineEmail->text(),ui->lineRenda->text().toDouble(),ui->lineCPF->text().toLong(),
                                    ui->lineSexo->text());
        ui->textEdit->setText("Pessoa Fisica Criada");
    } catch (QString e) {
        ui->textEdit->setText(e);
    }
}

void MainWindow::on_pushButton_3_clicked()
{//cria PJ
    try {
        pj=new Quest2::PessoaJuridica(ui->lineNome->text(),ui->lineEndere->text(),ui->lineTelefone->text().toLong()
                                    ,ui->lineEmail->text(),ui->lineRenda->text().toDouble(),ui->lineCNPJ->text().toLong(),
                                    ui->lineRazao->text());
        ui->textEdit->setText("Pessoa Juridica Criada");
    } catch (QString e) {
        ui->textEdit->setText(e);
    }
}

void MainWindow::on_pushButton_2_clicked()
{//imprime PF
    if (pf)
    {
        ui->textEdit->setText(pf->print());
    }
    else
    {
        ui->textEdit->setText("Nao há pessoa fisica cadastrada");
    }
}

void MainWindow::on_pushButton_4_clicked()
{//imprime PJ
    if (pj)
    {
        ui->textEdit->setText(pj->print());
    }
    else
    {
        ui->textEdit->setText("Nao há pessoa juridica cadastrada");
    }
}

void MainWindow::on_pushButton_5_clicked()
{//imposto PF
    if (pf)
    {
        ui->textEdit->setText(pf->calcularImposto());
    }
    else
    {
        ui->textEdit->setText("Nao há pessoa fisica cadastrada");
    }
}

void MainWindow::on_pushButton_6_clicked()
{//imposto PJ
    if (pj)
    {
        ui->textEdit->setText(pj->calcularImposto());
    }
    else
    {
        ui->textEdit->setText("Nao há pessoa juridica cadastrada");
    }
}
