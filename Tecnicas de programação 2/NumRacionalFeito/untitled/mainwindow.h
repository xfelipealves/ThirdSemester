#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_OBTER1_clicked();

    void on_pushButton_OBTER2_clicked();

    void on_pushButton_REDUZ1_clicked();

    void on_pushButton_REDUZ2_clicked();

    void on_pushButton_MAIS_clicked();

    void on_pushButton_MENOS_clicked();

    void on_pushButton_IGUAL_clicked();

    void on_pushButton_VEZES_clicked();

    void on_pushButton_DIVIDE_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
