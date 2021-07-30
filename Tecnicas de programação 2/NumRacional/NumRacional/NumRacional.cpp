#include "NumRacional.h"
#include "ui_NumRacional.h"

NumRacional::NumRacional(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NumRacional)
{
    ui->setupUi(this);
}

NumRacional::~NumRacional()
{
    delete ui;
}
