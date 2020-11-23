#include <iostream>
#include "NoVP.h"

/*
    1.Todo nó é vermelho ou preto
    2.A raiz é preta
    3.Toda folha (Nil) é preta
    4.Se um nó é vermelho, então os seus filhos são  pretos
    5.Para cada nó, todos os caminhos do nó para folhas descendentes contém o mesmo número de nós PRETOS.

    OBS: não pode existir dois nós rubros consecutivos
*/

class ArvoreVP{
    public:
        ArvoreVP(bool b);
        ~ArvoreVP(){}
        NoVP * raiz;

        int comparacao;
        bool balanceada;

        void insere(int value);
        void remove(int value);
        NoVP * busca(int value);

        void arrumaPropriedadesVP(NoVP * p);
        void rotDir(NoVP * p);
        void rotEsq(NoVP * p);
        void duplaRotDir(NoVP * p);
        void duplaRotEsq(NoVP * p);
};