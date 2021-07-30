#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include<fstream>
#include<QString>
using std::ifstream;
using std::ofstream;
using std::string;


namespace TP2 {

    class Persistencia
    {
        private:
            QString nomeDoArquivoNoDisco;
        public:
            Persistencia(QString nomeDoArquivoNoDisco);
            void incluir(QString valor);
            int excluir(QString valor);
            QString mostrar();
            string alterar();
    };

}
#endif // PERSISTENCIA_H
