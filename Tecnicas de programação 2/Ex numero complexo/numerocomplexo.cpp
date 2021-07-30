#include "numerocomplexo.h"

NumeroComplexo::NumeroComplexo()
{
    parteReal=0;
    parteImaginaria=0;
}

NumeroComplexo::NumeroComplexo(float pr, float pi)
{
    parteReal=pr;
    parteImaginaria=pi;
}

float NumeroComplexo::parte_real()
{
    return parteReal;
}

float NumeroComplexo::parte_imginaria()
{
    return parteImaginaria;
}

NumeroComplexo NumeroComplexo::soma(NumeroComplexo n)
{
    NumeroComplexo r;
    r.parteReal=n.parteReal+parteReal;
    r.parteImaginaria=n.parteImaginaria+parteImaginaria;
    return r;
}

NumeroComplexo NumeroComplexo::subtrai(NumeroComplexo n)
{
    NumeroComplexo r;
    r.parteReal=n.parteReal-parteReal;
    r.parteImaginaria=n.parteImaginaria-parteImaginaria;
    return r;
}

NumeroComplexo NumeroComplexo::multiplica(NumeroComplexo n)
{
    NumeroComplexo r;
    //(a+bi)*(c+di)
    r.parteReal=(parteReal*n.parteReal)-(parteImaginaria*n.parteImaginaria);
    //(ac-bd)+(ad+bc)i
    r.parteImaginaria=(parteReal*n.parteImaginaria)+(parteImaginaria*n.parteReal);
    return r;
}

NumeroComplexo NumeroComplexo::divide(NumeroComplexo n)
{
    NumeroComplexo r;
    r.parteReal=((parteReal*n.parteReal)-(parteImaginaria*n.parteImaginaria))/((n.parteImaginaria*n.parteImaginaria)+(parteImaginaria*parteImaginaria));
    r.parteImaginaria=((parteReal*n.parteImaginaria)+(parteImaginaria*n.parteReal))/((n.parteImaginaria*n.parteImaginaria)+(parteImaginaria*parteImaginaria));
    return r;
}

void NumeroComplexo::imprimir()
{
    cout<<parteReal<<" + "<<parteImaginaria<<"i"<<endl;
}
