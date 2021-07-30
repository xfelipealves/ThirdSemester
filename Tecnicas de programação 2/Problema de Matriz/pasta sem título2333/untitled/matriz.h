#ifndef MATRIZ_H
#define MATRIZ_H
#include <QString>
#include <cmath>

namespace Brabissimo {

class Matriz
{
private:
    int* M;
    int linhas,colunas;
public:
    Matriz(int l, int c);   //excessao
    QString getMatriz();
    Matriz operator + (Matriz& matrix);
    Matriz operator - (Matriz& matrix);
    Matriz operator * (Matriz& matrix);
    Matriz operator * (int k);
    bool operator ==(Matriz& matrix);
    bool operator !=(Matriz& matrix);
    bool trianSup();
    bool trianInf();
    bool simetrica();
    bool identidade();
    bool ortogonal();
    bool permutacao();
    Matriz transposta();
    Matriz potencia(int n);
    bool setPosicao(int n, int i, int j);
};
}


#endif // MATRIZ_H
