#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matriz.h"
using namespace Brabissimo;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Cria1_clicked()
{
    try {
        int linha1 = ui->lineEdit_linha1->text().toInt();
        int coluna1 = ui->lineEdit_coluna->text().toInt();
        if (faustao!=nullptr)
            delete faustao;
        faustao=new Matriz(linha1,coluna1);
        QString a="";
        int v;
        bool ok=true;
        for (int i=0;i<linha1;i++)
        {
            for (int j=0;j<coluna1;j++)
            {
                a="Valor da matriz nessa posicao";
                a+=QString::number(i)+" ";
                a+=QString::number(j);
                v = QInputDialog::getInt(this,"Matriz",a,0,-2147483647,2147483647,1,&ok);
                faustao->setPosicao(v,i,j);
            }
        }
        ui->textEdit_matriz->setText(faustao->getMatriz());

    } catch (QString k) {
        QMessageBox::information(this,"Alerta",k);
    }
}

void MainWindow::on_pushButton_Cria2_clicked()
{
    try {
        int linha1 = ui->lineEdit_linha2->text().toInt();
        int coluna1 = ui->lineEdit_coluna2->text().toInt();
        lucianohuque=new Matriz(linha1,coluna1);
        QString a="";
        int v;
        for (int i=0;i<linha1;i++)
        {
            for (int j=0;j<coluna1;j++)
            {
                a="Valor da matriz nessa posicao";
                a+=QString::number(i)+" ";
                a+=QString::number(j);
                v=QInputDialog::getInt(this,"Matriz",a);
                lucianohuque->setPosicao(v,i,j);
            }
        }
        ui->textEdit_matriz_2->setText(lucianohuque->getMatriz());

    } catch (QString k) {
        QMessageBox::information(this,"Alerta",k);
    }
}

void MainWindow::on_pushButton_triangula_superior2_clicked()
{
    if (faustao!=nullptr)
    {
        bool ah=faustao->trianSup();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é triang sup");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é triang sup");
        }
    }
}

void MainWindow::on_pushButton_Tinf_clicked()
{
    if (faustao!=nullptr)
    {
        bool ah=faustao->trianInf();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é triang inf");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é triang inf");
        }
    }
}

void MainWindow::on_pushButton_simetrica_clicked()
{
    if (faustao!=nullptr)
    {
        bool ah=faustao->simetrica();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é simetrica");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é simetrica");
        }
    }
}

void MainWindow::on_pushButton_identidade_clicked()
{
    if (faustao!=nullptr)
    {
        bool ah=faustao->identidade();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é identidade");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é identidade");
        }
    }
}

void MainWindow::on_pushButton_permuta_clicked()
{
    if (faustao!=nullptr)
    {
        bool ah=faustao->permutacao();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é permutacao");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é permutacao");
        }
    }
}

void MainWindow::on_pushButton_ortogonal_clicked()
{
    if (faustao!=nullptr)
    {
        bool ah=faustao->ortogonal();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é ortogonal");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é ortogonal");
        }
    }
}

void MainWindow::on_pushButton_triangula_superior2_2_clicked()
{
    if (lucianohuque!=nullptr)
    {
        bool ah=lucianohuque->trianSup();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é triang sup");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é triang sup");
        }
    }
}

void MainWindow::on_pushButton_Tinf_2_clicked()
{
    if (lucianohuque!=nullptr)
    {
        bool ah=lucianohuque->trianInf();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é triang inf");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é triang inf");
        }
    }
}

void MainWindow::on_pushButton_simetrica_2_clicked()
{
    if (lucianohuque!=nullptr)
    {
        bool ah=lucianohuque->simetrica();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é simetrica");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é simetrica");
        }
    }
}

void MainWindow::on_pushButton_identidade_2_clicked()
{
    if (lucianohuque!=nullptr)
    {
        bool ah=lucianohuque->identidade();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é identidade");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é identidade");
        }
    }
}

void MainWindow::on_pushButton_permuta_2_clicked()
{
    if (lucianohuque!=nullptr)
    {
        bool ah=lucianohuque->permutacao();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é permutacao");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é permutacao");
        }
    }
}

void MainWindow::on_pushButton_ortogonal_2_clicked()
{
    if (lucianohuque!=nullptr)
    {
        bool ah=lucianohuque->ortogonal();
        if (ah)
        {
            ui->textEdit_matriz_3->setText("Sim, é ortogonal");
        }
        else {
            ui->textEdit_matriz_3->setText("Nao é ortogonal");
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (faustao!=nullptr)
    {
        Matriz g=faustao->transposta();
        ui->textEdit_matriz_3->setText(g.getMatriz());
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if (lucianohuque!=nullptr)
    {
        Matriz g=lucianohuque->transposta();
        ui->textEdit_matriz_3->setText(g.getMatriz());
    }
}

void MainWindow::on_pushButton_soma_clicked()
{
    if (lucianohuque!=nullptr and faustao!=nullptr)
    {
        try {
            Matriz g=*lucianohuque+*faustao;
            ui->textEdit_matriz_3->setText(g.getMatriz());
        } catch (QString k) {
            QMessageBox::information(this,"Alerta",k);
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if (faustao!=nullptr)
    {
        try {
            int v=QInputDialog::getInt(this,"Numero","constante", 0);
            Matriz g=*faustao*v;
            ui->textEdit_matriz_3->setText(g.getMatriz());
        } catch (QString k) {
            QMessageBox::information(this,"Alerta",k);
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (lucianohuque!=nullptr)
    {
        try {
            int v=QInputDialog::getInt(this,"Numero","constante", 0);
            Matriz g=*lucianohuque*v;
            ui->textEdit_matriz_3->setText(g.getMatriz());
        } catch (QString k) {
            QMessageBox::information(this,"Alerta",k);
        }
    }
}

void MainWindow::on_pushButton_subtrai_clicked()
{
    if (lucianohuque!=nullptr and faustao!=nullptr)
    {
        try {
            Matriz g=*faustao-*lucianohuque;
            ui->textEdit_matriz_3->setText(g.getMatriz());
        } catch (QString k) {
            QMessageBox::information(this,"Alerta",k);
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if (lucianohuque!=nullptr and faustao!=nullptr)
    {
        try {
            bool x=*lucianohuque==*faustao;
            QString a;
            if (x)
            {
                a="Sim";
            }
            else {
                a="nao";
            }
            ui->textEdit_matriz_3->setText(a);
        } catch (QString k) {
            QMessageBox::information(this,"Alerta",k);
        }
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if (lucianohuque!=nullptr and faustao!=nullptr)
    {
        try {
            bool x=*lucianohuque!=*faustao;
            QString a;
            if (x)
            {
                a="Sim";
            }
            else {
                a="nao";
            }
            ui->textEdit_matriz_3->setText(a);
        } catch (QString k) {
            QMessageBox::information(this,"Alerta",k);
        }
    }
}

void MainWindow::on_pushButton_multiplica_clicked()
{
    if (lucianohuque!=nullptr and faustao!=nullptr)
    {
        try {
            Matriz g=*faustao**lucianohuque;
            ui->textEdit_matriz_3->setText(g.getMatriz());
        } catch (QString k) {
            QMessageBox::information(this,"Alerta",k);
        }
    }
}

void MainWindow::on_pushButton_divide_2_clicked()
{
    if (faustao!=nullptr)
    {
        try {
            int v=QInputDialog::getInt(this,"Numero","constante", 0);
            Matriz g=faustao->potencia(v);
            ui->textEdit_matriz_3->setText(g.getMatriz());
        } catch (QString k) {
            QMessageBox::information(this,"Alerta",k);
        }
    }
}

void MainWindow::on_pushButton_divide_clicked()
{
    if (lucianohuque!=nullptr)
    {
        try {
            int v=QInputDialog::getInt(this,"Numero","constante", 0);
            Matriz g=lucianohuque->potencia(v);
            ui->textEdit_matriz_3->setText(g.getMatriz());
        } catch (QString k) {
            QMessageBox::information(this,"Alerta",k);
        }
    }
}
