#include "Persistencia.h"

namespace TP2 {

    Persistencia::Persistencia(QString nomeDoArquivoNoDisco):nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
    {
    }

    void Persistencia::incluir(QString valor){
        ofstream arquivo;
        arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out | std::ios::app);
            if(!arquivo.is_open())
                throw QString("Erro ao abrir arquivo - Metodo incluir");

            arquivo << valor.toStdString()+"\n";
            arquivo.close();
    }

    QString Persistencia::mostrar(){

        ifstream arquivo;
        arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::in);

        if(!arquivo.is_open())
            throw QString("Arquivo nao foi aberto");

        string linha;
        QString saida = "";
        getline(arquivo,linha);
        if(arquivo.eof())
            throw QString ("Arquivo vazio");
        while(!arquivo.eof()){
            saida += QString::fromStdString(linha)+"\n";
            getline(arquivo,linha);
        }
        arquivo.close();
        return saida;
    }


    int Persistencia::excluir(QString valor){

        ifstream arquivo;
        arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::in);
        if(!arquivo.is_open())
            throw QString("Arquivo nao foi aberto");

        ofstream arqTemp;
        arqTemp.open("temp.txt", std::ios::out);
        if(!arqTemp.is_open()){
            throw QString("Arquivo temporario nao foi aberto");
        }

        string linha;
        int cont=0;
        while(getline(arquivo, linha)){
            if(QString::fromStdString(linha) != valor)
                arqTemp << linha + "\n";
            else
                cont++;
        }

        //fecha os arquivos
        arquivo.close();
        arqTemp.close();

        remove(nomeDoArquivoNoDisco.toStdString().c_str());
        rename("temp.txt", nomeDoArquivoNoDisco.toStdString().c_str());
        return cont;
    }
}
