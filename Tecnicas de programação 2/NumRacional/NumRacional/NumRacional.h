#ifndef NUMRACIONAL_H
#define NUMRACIONAL_H

#include <QMainWindow>

namespace Ui {
class NumRacional;
}

class NumRacional : public QMainWindow
{
    Q_OBJECT

public:
    explicit NumRacional(QWidget *parent = nullptr);
    ~NumRacional();

private:
    Ui::NumRacional *ui;
};

#endif // NUMRACIONAL_H
