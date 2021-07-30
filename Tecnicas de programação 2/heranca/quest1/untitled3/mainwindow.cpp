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
{//cria est
    try {
        a=new Quest1::Estudante();
        a->setNome(ui->lineEditNome->text());
        a->setEmail(ui->lineEditEmail->text());
        a->setEndereco(ui->lineEditEndereco->text());
        a->setTelefone(ui->lineEditTelefone->text().toLong());

        a->setCurso(ui->lineEditCurso->text());
        a->setCampus(ui->lineEditCampus->text());
        a->setMatricula(ui->lineEditMatricula->text().toLong());

    } catch (QString e) {
        ui->textEdit->setText(e);
    }
}

void MainWindow::on_pushButton_3_clicked()
{//imprime trab
    if (c)
    {
        ui->textEdit->setText(c->print());
    }
    else
    {
        ui->textEdit->setText("Nao há trabalhador cadastrado");
    }
}

void MainWindow::on_pushButton_2_clicked()
{//cria trab
    try {
        c=new Quest1::Trabalhador();
        c->setNome(ui->lineEditNome->text());
        c->setEmail(ui->lineEditEmail->text());
        c->setEndereco(ui->lineEditEndereco->text());
        c->setTelefone(ui->lineEditTelefone->text().toLong());

        c->setFuncao(ui->lineEditFuncao->text());
        c->setDepartamento(ui->lineEditDepartamento->text());
        c->setSalario(ui->lineEditSalario->text().toLong());

    } catch (QString e) {
        ui->textEdit->setText(e);
    }
}

void MainWindow::on_pushButton_4_clicked()
{//cria graduado
    try {
        b=new Quest1::Graduado();
        b->setNome(ui->lineEditNome->text());
        b->setEmail(ui->lineEditEmail->text());
        b->setEndereco(ui->lineEditEndereco->text());
        b->setTelefone(ui->lineEditTelefone->text().toLong());

        b->setAnodeconclusao(ui->lineEditAnodeConclu->text().toInt());
        b->setAnodecolacao(ui->lineEditAnoDeCola->text().toInt());
        b->setNumdiploma(ui->lineEditNumDiploma->text().toInt());

    } catch (QString e) {
        ui->textEdit->setText(e);
    }
}

void MainWindow::on_pushButton_6_clicked()
{//imprime estudante
    if (a)
    {
        ui->textEdit->setText(a->print());
    }
    else
    {
        ui->textEdit->setText("Nao há estudante cadastrado");
    }
}

void MainWindow::on_pushButton_5_clicked()
{//imprime graduado
    if (b)
    {
        ui->textEdit->setText(b->print());
    }
    else
    {
        ui->textEdit->setText("Nao há graduado cadastrado");
    }
}
