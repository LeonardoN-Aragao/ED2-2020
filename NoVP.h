#include <iostream>

class NoVP{

    public:
        NoVP(){
            cor = 'v';
            fator = 0; 
            esq = NULL;
            dir = NULL;
            pai = NULL;
        }
        NoVP(int v){ NoVP(); value = v;}
        ~NoVP(){}

        char cor;
        int fator; 
        int value;
        NoVP * esq;
        NoVP * dir;
        NoVP * pai;

        int getValue(){ return value;}
        int getFator(){ return fator;}
        char getCor(){ return cor;}
        NoVP * getEsq(){ return esq;}
        NoVP * getDir(){ return dir;}
        NoVP * getPai(){ return pai;}

        void setValue(int v){ value = v;}
        void setFator(int f){ fator = f;}
        void setCor(char c){ cor = c;}
        void setEsq(NoVP * p){ esq = p;}
        void setDir(NoVP * p){ dir = p;}
        void setPai(NoVP * p){ pai = p;}
};