#ifndef NUMEROCOMPLEXO_H
#define NUMEROCOMPLEXO_H
#include <QString>
namespace Felipao {

    class NumeroComplexo
    {
        private:
            float parteReal;
            float parteImag;
        public:
            NumeroComplexo();
            NumeroComplexo(float parteReal, float parteImag);
            void set(float parteReal, float parteImag);
            QString get() const;
            NumeroComplexo operator +(NumeroComplexo numero);
            NumeroComplexo operator -(NumeroComplexo numero);
            NumeroComplexo operator *(NumeroComplexo numero);
            NumeroComplexo operator /(NumeroComplexo numero);
            QString operator ==(NumeroComplexo numero);
            QString operator !=(NumeroComplexo numero);
    };

}


#endif // NUMEROCOMPLEXO_H
