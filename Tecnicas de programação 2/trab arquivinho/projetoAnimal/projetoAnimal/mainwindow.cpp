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


void MainWindow::on_pushButton_Executar_clicked()
{
    try {
        if(ui->radioButton_Homem->isChecked())
        {
            TP2::Animal *obj = new TP2::Homem();
            p->incluir(obj->falar());
        }
        else if(ui->radioButton_Cao->isChecked())
        {
            TP2::Animal *obj = new TP2::Cao();
            p->incluir(obj->falar());
        }
        else if(ui->radioButton_Gato->isChecked())
        {
            TP2::Animal *obj = new TP2::Gato();
            p->incluir(obj->falar());
        }
        else
        {
           ui->textEdit->setText("Qual Animal inserir no arquivo?");
        }
    } catch (QString erro) {
        QMessageBox::information(this, "Erro: ", erro);
    }
}


void MainWindow::on_pushButton_Excluir_clicked()
{
    try {
        int aux;
        if(ui->radioButton_Homem_Oi->isChecked())
        {
            aux = p->excluir("Oi");
            if(aux != 0)
                ui->textEdit->setText(QString::number(aux)+ " ocorrencia de Oi excluidas do arquivo.");
            else
                ui->textEdit->setText("Nenhuma ocorrencia de Oi");
        }
        else if(ui->radioButton_Cao_AuAu->isChecked())
        {
            aux = p->excluir("Au Au");
            if(aux != 0)
                ui->textEdit->setText(QString::number(aux)+ " ocorrencia de Au Au excluidas do arquivo.");
            else
                ui->textEdit->setText("Nenhuma ocorrencia de Au Au");
        }
        else if(ui->radioButton_Gato_Miau->isChecked())
        {
            aux = p->excluir("Miau");
            if(aux != 0)
                ui->textEdit->setText(QString::number(aux)+ " ocorrencia de Miau excluidas do arquivo.");
            else
                ui->textEdit->setText("Nenhuma ocorrencia de Miau");
        }
        else
        {
            ui->textEdit->setText("Qual string deve ser excluida do arquivo?");
        }
    } catch (QString erro) {
        QMessageBox::information(this, "Erro: ", erro);
    }
}


void MainWindow::on_pushButton_Mostrar_clicked()
{
    try {
        ui->textEdit->clear();
        ui->textEdit->setText(p->mostrar());
    } catch (QString erro) {
        QMessageBox::information(this, "Erro: ", erro);
    }
}
