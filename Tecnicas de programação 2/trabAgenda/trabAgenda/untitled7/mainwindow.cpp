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

void MainWindow::on_addPF_clicked()
{//add PF
    try {
        QString nome,endereco,email,nascimento,estadoCivil;
        long long CPF;
        nome=ui->lineNome->text();
        endereco=ui->lineEndereco->text();
        email=ui->lineEmail->text();
        nascimento=ui->lineNascimento->text();
        estadoCivil=ui->lineEstadoCivil->text();
        CPF=ui->lineCPF->text().toLongLong();

        ag::Pessoa* x=new ag::PessoaFisica(nome,endereco,email,nascimento,estadoCivil,CPF);
        agenda.adiciona(x);

        ui->textEdit->setText("Pessoa Fisica adicionada");
    } catch (QString e) {
        ui->textEdit->setText(e);
    }
}

void MainWindow::on_pushButton_2_clicked()
{//addPJ
    try {
        QString nome,endereco,email,razaoSocial;
        long long CNPJ;
        int inscrEstadual;
        nome=ui->lineNome->text();
        endereco=ui->lineEndereco->text();
        email=ui->lineEmail->text();
        inscrEstadual=ui->lineInscricao->text().toInt();
        razaoSocial=ui->lineRazaoSocial->text();
        CNPJ=ui->lineCNPJ->text().toLongLong();

        ag::Pessoa*X= new ag::PessoaJuridica(nome,endereco,email,inscrEstadual,razaoSocial,CNPJ);
        agenda.adiciona(X);

        ui->textEdit->setText("Pessoa Juridica adicionada");
    } catch (QString e) {
        ui->textEdit->setText(e);
    }
}

void MainWindow::on_pushButton_3_clicked()
{//busca contato
    try {
        QString nome=ui->lineNomez->text();
        ui->textEdit->setText(agenda.buscarContato(nome));
    } catch (QString e) {
        ui->textEdit->setText(e);
    }

}

void MainWindow::on_pushButton_4_clicked()
{//remove por nome
    try {
        QString nome=ui->lineNomez->text();
        bool x=agenda.remove(nome);
        if (x)
        {
            ui->textEdit->setText("Contato removido");
        }
        else
        {
            ui->textEdit->setText("Contato nao existente");
        }
    } catch (QString e) {
        ui->textEdit->setText(e);
    }
}

void MainWindow::on_pushButton_clicked()
{//ordena
    try {
        agenda.ordena();
        ui->textEdit->setText("Agenda ordenada");
    } catch (QString e) {
        ui->textEdit->setText(e);
    }
}

void MainWindow::on_pushButton_5_clicked()
{//print agenda
    try {
        ui->textEdit->setText(agenda.printTodos());
    } catch (QString e) {
        ui->textEdit->setText(e);
    }
}
