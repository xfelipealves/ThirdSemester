#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <matriz.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void on_pushButton_clicked();

//    void on_pushButton_triangula_superior_clicked();

    void on_pushButton_Cria1_clicked();

    void on_pushButton_Cria2_clicked();

    void on_pushButton_triangula_superior2_clicked();

    void on_pushButton_Tinf_clicked();

    void on_pushButton_simetrica_clicked();

    void on_pushButton_identidade_clicked();

    void on_pushButton_permuta_clicked();

    void on_pushButton_ortogonal_clicked();

    void on_pushButton_triangula_superior2_2_clicked();

    void on_pushButton_Tinf_2_clicked();

    void on_pushButton_simetrica_2_clicked();

    void on_pushButton_identidade_2_clicked();

    void on_pushButton_permuta_2_clicked();

    void on_pushButton_ortogonal_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Brabissimo::Matriz* faustao=nullptr;
    Brabissimo::Matriz* lucianohuque=nullptr;
};

#endif // MAINWINDOW_H
