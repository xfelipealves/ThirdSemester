#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_soma_clicked()
{
    float r_n1,i_n1,r_n2,i_n2;
    r_n1=ui->lineEdit_1_real1->text().toFloat();
    i_n1=ui->lineEdit_2_imag1->text().toFloat();
    r_n2=ui->lineEdit_3_real2->text().toFloat();
    i_n2=ui->lineEdit_4_imag2->text().toFloat();
    Felipao::NumeroComplexo n1(r_n1,i_n1);
    Felipao::NumeroComplexo n2(r_n2,i_n2);
    Felipao::NumeroComplexo x=n1+n2;
    ui->textEdit_resultado->setText(x.get());
}

void MainWindow::on_pushButton_sub_clicked()
{
    float r_n1,i_n1,r_n2,i_n2;
    r_n1=ui->lineEdit_1_real1->text().toFloat();
    i_n1=ui->lineEdit_2_imag1->text().toFloat();
    r_n2=ui->lineEdit_3_real2->text().toFloat();
    i_n2=ui->lineEdit_4_imag2->text().toFloat();
    Felipao::NumeroComplexo n1(r_n1,i_n1);
    Felipao::NumeroComplexo n2(r_n2,i_n2);
    Felipao::NumeroComplexo x=n1-n2;
    ui->textEdit_resultado->setText(x.get());
}

void MainWindow::on_pushButton_multi_clicked()
{
    float r_n1,i_n1,r_n2,i_n2;
    r_n1=ui->lineEdit_1_real1->text().toFloat();
    i_n1=ui->lineEdit_2_imag1->text().toFloat();
    r_n2=ui->lineEdit_3_real2->text().toFloat();
    i_n2=ui->lineEdit_4_imag2->text().toFloat();
    Felipao::NumeroComplexo n1(r_n1,i_n1);
    Felipao::NumeroComplexo n2(r_n2,i_n2);
    Felipao::NumeroComplexo x=n1*n2;
    ui->textEdit_resultado->setText(x.get());
}

void MainWindow::on_pushButton_div_clicked()
{
    float r_n1,i_n1,r_n2,i_n2;
    r_n1=ui->lineEdit_1_real1->text().toFloat();
    i_n1=ui->lineEdit_2_imag1->text().toFloat();
    r_n2=ui->lineEdit_3_real2->text().toFloat();
    i_n2=ui->lineEdit_4_imag2->text().toFloat();
    Felipao::NumeroComplexo n1(r_n1,i_n1);
    Felipao::NumeroComplexo n2(r_n2,i_n2);
    Felipao::NumeroComplexo x=n1/n2;
    ui->textEdit_resultado->setText(x.get());
}

void MainWindow::on_pushButton_igual_clicked()
{
    float r_n1,i_n1,r_n2,i_n2;
    r_n1=ui->lineEdit_1_real1->text().toFloat();
    i_n1=ui->lineEdit_2_imag1->text().toFloat();
    r_n2=ui->lineEdit_3_real2->text().toFloat();
    i_n2=ui->lineEdit_4_imag2->text().toFloat();
    Felipao::NumeroComplexo n1(r_n1,i_n1);
    Felipao::NumeroComplexo n2(r_n2,i_n2);
    QString x=n1==n2;
    ui->textEdit_resultado->setText(x);
}

void MainWindow::on_pushButton_dif_clicked()
{
    float r_n1,i_n1,r_n2,i_n2;
    r_n1=ui->lineEdit_1_real1->text().toFloat();
    i_n1=ui->lineEdit_2_imag1->text().toFloat();
    r_n2=ui->lineEdit_3_real2->text().toFloat();
    i_n2=ui->lineEdit_4_imag2->text().toFloat();
    Felipao::NumeroComplexo n1(r_n1,i_n1);
    Felipao::NumeroComplexo n2(r_n2,i_n2);
    ui->textEdit_resultado->setText(n1!=n2);
}
