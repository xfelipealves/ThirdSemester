#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    stack <char> t1,t2,t3,t4,t5,t6; //torres
    queue <char> j1,j2,j3,j4; //num torre
    queue <char> c1,c2,c3,c4; //cor jogador
    char x,z;
    //leitura dos arquivos
    for (int p=1;p<5;p++)
    {
        cout<<"Leitura da fila do jogador "<<p<<endl;
        for (int i=0;i<13;i++)
        {
            cout<<"Torre: ";
            cin>>x;
            cout<<"Cor: ";
            cin>>z;
            if (p==1)
            {
                j1.push(x);
                c1.push(z);
            }
            else
            {
                if (p==2)
                {
                    j2.push(x);
                    c2.push(z);
                }
                else
                {
                    if (p==3)
                    {
                        j3.push(x);
                        c3.push(z);
                    }
                    else
                    {
                        if (p==4)
                        {
                            j4.push(x);
                            c4.push(z);
                        }
                    }
                }
            }
        }
    }
    bool ok; //validador
    bool n1=1,n2=1,n3=1,n4=1,n5=1,n6=1; //todas as filas vazias
    for (int cont=0,b=1;cont!=6;b++)
    {
        //lendo o x e o z de cada jogador na sua vez
        //'x' é o numero da torre e 'z' a cor
        if (b%4==1)
        {
            //torre
            x=j1.front();
            j1.pop();
            //cor
            z=c1.front();
            c1.pop();
        }
        else
        {
            if (b%4==2)
            {
                //torre
                x=j2.front();
                j2.pop();
                //cor
                z=c2.front();
                c2.pop();
            }
            else
            {
                if(b%4==3)
                {
                    //torre
                    x=j3.front();
                    j3.pop();
                    //cor
                    z=c3.front();
                    c3.pop();
                }
                else
                {
                    if (b%4==0)
                    {
                        //torre
                        x=j4.front();
                        j4.pop();
                        //cor
                        z=c4.front();
                        c4.pop();
                    }
                }
            }
        }

        //Desenfileirando e empilhando
        ok=false;
        //1
        if (x=='1' or ok)
        {
            if (z=='P') //remover o topo
            {
                t1.pop();
                n1=true; //tem espaco
            }
            else
            {
                if (n1)
                {//tem espaco
                    t1.push(z);
                    ok=false;
                    if (t1.size()==6)
                        n1=false; //nao tem espaco
                }
                else
                {//nao tem espaco
                    ok=true;
                }
            }
        }
        //2
        if (x=='2' or ok)
        {
            if (z=='P')
            {
                t2.pop();
                n2=true;
            }
            else
            {
                if (n2)
                {
                    t2.push(z);
                    ok=false;
                    if (t2.size()==6)
                        n2=false;
                }
                else
                {
                    ok=true;
                }
            }
        }
        //3
        if (x=='3' or ok)
        {
            if (z=='P')
            {
                t3.pop();
                n3=true;
            }
            else
            {
                if (n3)
                {
                    t3.push(z);
                    ok=false;
                    if (t3.size()==6)
                        n3=false;
                }
                else
                {
                    ok=true;
                }
            }
        }
        //4
        if (x=='4' or ok)
        {
            if (z=='P')
            {
                t4.pop();
                n4=true;
            }
            else
            {
                if (n4)
                {
                    t4.push(z);
                    ok=false;
                    if (t4.size()==6)
                        n4=false;
                }
                else
                {
                    ok=true;
                }
            }
        }
        //5
        if (x=='5' or ok)
        {
            if (z=='P')
            {
                t5.pop();
                n5=true;
            }
            else
            {
                if (n5)
                {
                    t5.push(z);
                    ok=false;
                    if (t5.size()==6)
                        n5=false;
                }
                else
                {
                    ok=true;
                }
            }
        }
        //6
        if (x=='6' or ok)
        {
            if (z=='P')
            {
                t6.pop();
                n6=true;
            }
            else
            {
                if (n6)
                {
                    t6.push(z);
                    ok=false;
                    if (t6.size()==6)
                        n6=false;
                }
                else
                {
                    ok=true;
                }
            }
        }

        if (!n1 and !n2 and !n3 and !n4 and !n5 and !n6) //se ta td cheio
            cont=6;
    }
    stack <char> k;
        cout<<"CONTEUDO DAS TORRES:"<<endl;

        cout<<"T1"<<endl;
        for (int i=1;!t1.empty();i++)
        {
            cout<<t1.top()<<" ";
            if (i==1)
            {
                k.push(t1.top());
            }
            t1.pop();
        }

        cout<<endl<<"T2"<<endl;
        for (int i=1;!t2.empty();i++)
        {
            cout<<t2.top()<<" ";
            if (i==2)
            {
                k.push(t2.top());
            }
            t2.pop();
        }

        cout<<endl<<"T3"<<endl;
        for (int i=1;!t3.empty();i++)
        {
            cout<<t3.top()<<" ";
            if (i==3)
            {
                k.push(t3.top());
            }
            t3.pop();
        }

        cout<<endl<<"T4"<<endl;
        for (int i=1;!t4.empty();i++)
        {
            cout<<t4.top()<<" ";
            if (i==4)
            {
                k.push(t4.top());
            }
            t4.pop();
        }

        cout<<endl<<"T5"<<endl;
        for (int i=1;!t5.empty();i++)
        {
            cout<<t5.top()<<" ";
            if (i==5)
            {
                k.push(t5.top());
            }
            t5.pop();
        }

        cout<<endl<<"T6"<<endl;
        for (int i=1;!t6.empty();i++)
        {
            cout<<t6.top()<<" ";
            if (i==6)
            {
                k.push(t6.top());
            }
            t6.pop();
        }

        int A,V,R,B;
        A=V=R=B=0;
        while (!t6.empty())
        {
            x=t6.top();
            t6.pop();
            if (x=='A')
            {
                A++;
            }
            else
            {
                if (x=='V')
                {
                    V++;
                }
                else
                {
                    if (x=='R')
                    {
                        R++;
                    }
                    else
                    {
                        if (x=='B')
                        {
                            B++;
                        }
                    }
                }
            }
        }





}
