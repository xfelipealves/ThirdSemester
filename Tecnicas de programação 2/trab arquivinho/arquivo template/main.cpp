#include <iostream>
#include <fstream>
using namespace std;

string alterar (string a)
{
    string x="";
    for (int i=0; a[i]!='\0'; i++)
    {
        if ((a[i]>='A' and a[i]<='Z') or (a[i]>='a' and a[i]<='z'))
        {
            x+=a[i]^32;
        }
        else
            x+=a[i];
    }
    return x;
}

int main()
{
    ifstream arq1; //colocar em parametro onde tem q ser lido
    string nome;
    getline(cin,nome);
    arq1.open(nome);
    if (arq1.is_open())
    {
        ofstream arq2("saida.txt"); //colocar em parametro onde deve ser salvo
        string n,nf;
        while (!arq1.eof())
        {
            getline(arq1, n);
            nf=alterar(n);
            arq2<<nf<<endl;
        }
        arq2.close();
        cout<<"arquivo alterado :)"<<endl;
    }
    else
        cout<<"arquivo nao encontrado"<<endl;
}
