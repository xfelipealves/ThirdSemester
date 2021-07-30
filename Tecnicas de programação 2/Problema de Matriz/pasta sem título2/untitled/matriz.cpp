#include "matriz.h"

Brabissimo::Matriz::Matriz(int l, int c)
{
    if (l<=0 or c<=0)
    {
        throw QString ("Nao pode ser 0");
    }
    linhas=l;
    colunas=c;
    M=new int[colunas*linhas];
}

bool Brabissimo::Matriz::setMatriz(int *V)
{
    if ((sizeof (V)/sizeof (int))!=(linhas*colunas))
    {
        throw QString ("Preenche o negocio antes");
    }
    M=V;
    return true;
}

QString Brabissimo::Matriz::getMatriz()
{
    QString x;
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            x+=QString::number(M[colunas*i+j])+" ";
        }
        x+="\n";
    }
    return x;
}

Brabissimo::Matriz Brabissimo::Matriz::operator +(Brabissimo::Matriz &matrix)
{
    if (linhas!=matrix.linhas or colunas!=matrix.colunas)
    {
        throw QString ("Tamanho invalido para esta operacao");
    }
    int V[linhas*colunas];
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            V[colunas*i+j]=M[colunas*i+j]+matrix.M[matrix.colunas*i+j];
        }
    }
    Matriz X(linhas,colunas);
    X.setMatriz(V);
    return X;
}

Brabissimo::Matriz Brabissimo::Matriz::operator -(Brabissimo::Matriz &matrix)
{
    if (linhas!=matrix.linhas or colunas!=matrix.colunas)
    {
        throw QString ("Tamanho invalido para esta operacao");
    }
    int V[linhas*colunas];
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            V[colunas*i+j]=M[colunas*i+j]-matrix.M[matrix.colunas*i+j];
        }
    }
    Matriz X(linhas,colunas);
    X.setMatriz(V);
    return X;
}

Brabissimo::Matriz Brabissimo::Matriz::operator *(Brabissimo::Matriz &matrix)
{
    if (colunas!=matrix.linhas)
    {
        throw QString ("Tamanho invalido para esta operacao");
    }
    int V[linhas*matrix.colunas];
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<matrix.colunas;j++)
        {
            V[matrix.colunas*i+j]=0;
            for (int k=0;j<colunas;k++)
            {
                V[matrix.colunas*i+j]=V[matrix.colunas*i+j]+M[colunas*i+k]*matrix.M[matrix.colunas*k+j];
            }
        }
    }
    Matriz X(linhas,matrix.colunas);
    X.setMatriz(V);
    return X;
}

Brabissimo::Matriz Brabissimo::Matriz::operator *(int k)
{
    int V[linhas*colunas];
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            V[colunas*i+j]=M[colunas*i+j]*k;
        }
    }
    Matriz X(linhas,colunas);
    X.setMatriz(V);
    return X;
}

bool Brabissimo::Matriz::operator ==(Brabissimo::Matriz& matrix)
{
    if (linhas!=matrix.linhas or colunas!=matrix.colunas)
    {
        return false;
    }
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            if (M[colunas*i+j]!=matrix.M[colunas*i+j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Brabissimo::Matriz::operator !=(Brabissimo::Matriz& matrix)
{
    if (linhas!=matrix.linhas or colunas!=matrix.colunas)
    {
        return true;
    }
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            if (M[colunas*i+j]==matrix.M[colunas*i+j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Brabissimo::Matriz::trianSup()
{
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            if (i>j)
            {
                if (M[colunas*i+j]!=0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Brabissimo::Matriz::trianInf()
{
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            if (i<j)
            {
                if (M[colunas*i+j]!=0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Brabissimo::Matriz::simetrica()
{
    if (linhas!=colunas)
    {
        return false;
    }
    Matriz x=this->transposta();
    Matriz z=x.transposta();
    if (x==z)
    {
        return true;
    }
    return false;
}

bool Brabissimo::Matriz::identidade()
{
    if (linhas!=colunas)
    {
        return false;
    }
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            if (i==j)
            {
                if (M[colunas*i+j]!=1)
                {
                    return false;
                }
            }
            else {
                if (M[colunas*i+j]!=0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Brabissimo::Matriz::ortogonal()
{
    Matriz t=this->transposta();
    Matriz o=t.transposta();
    if (t.linhas!=o.linhas or t.colunas!=o.colunas)
    {
        return false;
    }
    Matriz k=o*t;
    return k.identidade();
}

bool Brabissimo::Matriz::permutacao()
{
    if (linhas==colunas)
    {
        bool ok;
        for (int i=0;i<linhas;i++)
        {
            ok=false;
            for (int j=0;j<colunas;j++)
            {
                if (M[colunas*i+j]!=0 and M[colunas*i+j]!=1)
                {
                    return false;
                }
                if (M[colunas*i+j]==1)
                {
                    if (ok)
                    {
                        return false;
                    }
                    ok=true;
                }
            }
            if (!ok)
            {
                return false;
            }
        }
    }
    return false;
}

Brabissimo::Matriz Brabissimo::Matriz::transposta()
{
    int V[linhas*colunas];
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            V[colunas*i+j]=M[colunas*j+i];
        }
    }
    Matriz x(colunas,linhas);
    x.setMatriz(V);
}

Brabissimo::Matriz Brabissimo::Matriz::potencia(int n)
{
    int V[linhas*colunas];
    for (int i=0;i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            V[colunas*i+j]=pow(M[colunas*i+j],n);
        }
    }
    Matriz x(linhas,colunas);
    x.setMatriz(V);
    return x;
}

bool Brabissimo::Matriz::setPosicao(int n, int i, int j)
{
    M[colunas*i+j]=n;
}
