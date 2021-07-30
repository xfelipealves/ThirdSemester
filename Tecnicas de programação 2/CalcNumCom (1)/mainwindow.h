#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "NumeroComplexo.h"
#include <QMainWindow>

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
    void on_pushButton_soma_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_multi_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_igual_clicked();

    void on_pushButton_dif_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
