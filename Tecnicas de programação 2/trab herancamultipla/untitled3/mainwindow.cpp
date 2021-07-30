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

void MainWindow::on_estudanteCriar_clicked()
{
    try {

        QString nome = ui->estudanteNome->text(),
                curso = ui->estudanteCurso->text();
        int matricula = ui->estudanteMatricula->text().toInt();

        bEstudante = new Estudante(nome, matricula,  curso );

        ui->saida->setText("Objeto criado");

    } catch (QString e) {
         QMessageBox::information(this, "ERRO", e);
    }
}

void MainWindow::on_estudanteImprimir_clicked()
{
    if(bEstudante)
        ui->saida->setText(bEstudante->print());
    else
        QMessageBox::information(this, "ERRO", "Objeto nao criado");
}

void MainWindow::on_funcionarioCriar_clicked()
{
    try {

        QString nome = ui->funcionarioNome->text(),
                turno = ui->funcionarioTurno->text();

        int rg = ui->funcionarioRG->text().toInt();
        double salario = ui->funcionarioSalario->text().toDouble();

        bFuncionario = new Funcionario(nome, salario, turno, rg);

        ui->saida->setText("Objeto criado!");

    } catch (QString e) {
         QMessageBox::information(this, "ERRO", e);
    }
}

void MainWindow::on_funcionarioImprimir_clicked()
{
    if(bFuncionario)
        ui->saida->setText(bFuncionario->print());
    else
        QMessageBox::information(this, "ERRO", "Objeto nao criado");
}

void MainWindow::on_monitorCriar_clicked()
{
    try {
        QString nome = ui->monitorNome->text(),
                curso = ui->monitorCurso->text(),
                turno = ui->monitorTurno->text(),
                disciplina = ui->monitorDisciplina->text();

        int matricula = ui->monitorMatricula->text().toInt(),
            rg = ui->monitorRG->text().toInt(),
            cargaHoraria = ui->monitorCarga->text().toInt();

        double salario = ui->monitorSalario->text().toDouble();

        bMonitor = new Monitor(nome, matricula, curso, salario, turno, rg,disciplina, cargaHoraria);

        ui->saida->setText("Objeto criado!");

    } catch(QString e) {
        QMessageBox::information(this, "ERRO", e);
   }
}

void MainWindow::on_monitorIImprirmir_clicked()
{
    if(bMonitor)
        ui->saida->setText(bMonitor->print());
    else
        QMessageBox::information(this, "ERRO", "Objeto nao criado");
}
