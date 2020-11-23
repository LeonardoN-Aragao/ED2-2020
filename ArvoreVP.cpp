#include "ArvoreVP.h"

ArvoreVP::ArvoreVP(bool b){
    raiz = NULL;
    balanceada = b;
    comparacao = 0;
}

NoVP * getTio(NoVP * p) {
    
    NoVP * pai = p->getPai();
    NoVP * avo = NULL;

    if(pai != NULL)
        avo = pai->getPai();

    if (avo == NULL) {
        return NULL;
    }
    
    if (pai->getValue() > avo->getValue())
        return avo->getEsq();
    else 
        return avo->getDir();    
}

NoVP * ArvoreVP::busca(int value){
    
    NoVP * p = raiz;

    while(p!=NULL){
        
        if(p->getValue() == value){
            comparacao++;
            return p;
        }

        if(value > p->getValue())
            p = p->getDir();
        else
            p = p->getEsq();
        
        comparacao++;
    }
    return NULL;
}

void ArvoreVP::arrumaPropriedadesVP(NoVP * p){

    NoVP * pai = p->getPai();

    //Raiz tem que ser preta
    if(pai == NULL){
        p->setCor('p');
        return;
    }
    else{
        //Se mantem a altura negra da arvore ela se mantem balanceada
        if (pai->getCor() == 'p')
		    return;
        else{
            //Se pai e tio são v, então ambos podem ser mudar para p e o avo fica vermelho
            NoVP * tio = getTio(p);
            NoVP * avo = NULL;

            if(pai != NULL)
                avo = pai->getPai();

            //Se o avo for NULL não entra nesse if
            if (tio != NULL && tio->getCor() == 'v'){
                tio->setCor('p');
                pai->setCor('p');
                avo->setCor('v');
                arrumaPropriedadesVP(avo); //Para verificar se o resto da arvore está balanceada
            } 
            else{
                //Dupla Rotação com mudança de cor

                if (p == pai->getDir() && pai == avo->getEsq()){
                    rotEsq(pai);
                    p = p->getEsq();
                } 
                else if ( p == pai->getEsq() && pai == avo->getDir()){
                    rotDir(pai);
                    p = p->getDir();
                }

                //Atualiza o Ponteiro para o pai e avo
                pai = p->getPai();
                avo = pai->getPai();

                pai->setCor('p');
                avo->setCor('v');

                if (p == pai->getEsq() && pai == avo->getEsq()){
                    rotDir(avo);
                } 
                else {
                    rotEsq(avo);
                }
            }
        }
    }     
}

void ArvoreVP::insere(int value){
    
    NoVP * p = new NoVP(value);

    if(raiz == NULL){
        raiz = p;
        raiz->setCor('p');
    }
    else{
        NoVP * q = raiz;
        NoVP * aux;

        while(q!=NULL){
            aux = q;
            //valor já adicionado
            if(q->getValue() == value){
                comparacao++;
                return;
            }

            if(value > p->getValue())
                q = q->getDir();
            else
                q = q->getEsq();
            comparacao++;
        }

        if(value > aux->getValue())
            aux->setDir(p);
        else
            aux->setEsq(p);
        
        p->setPai(aux);     
    }
    arrumaPropriedadesVP(p);
}

void ArvoreVP::remove(int value){
    
    NoVP * p = busca(value);
    NoVP * q;
    if( p != NULL){
        q = p->getPai();
        // p é folha
        if(p->getEsq() != NULL && p->getDir() != NULL)
            delete p;
        // p é pai de um filho
        else if(!p->getEsq()){
            NoVP * aux = p;
            p = p->getDir();
            p->setPai(aux->getPai());
            delete aux;
        }
        else if(!p->getDir()){
            NoVP * aux = p;
            p = p->getEsq();
            p->setPai(aux->getPai());
            delete aux;
        }
        // p é pai de 2 filhos - troca pelo maior filho da arvore a esquerda
        else {
            NoVP * aux = p->getEsq();
            while (!aux->getDir()) {
                aux = aux->getDir();
            }
            p->setValue(aux->getValue());
            delete aux;
        }
    }
    arrumaPropriedadesVP(p);
}

void ArvoreVP::rotEsq(NoVP * p){
	NoVP * q = p->getDir();
	p->setDir(q->getEsq());
	q->setEsq(p);
}

void ArvoreVP::rotDir(NoVP * p){
	NoVP * q = p->getDir();
	p->setEsq(q->getDir());
	q->setDir(p);
}

void ArvoreVP::duplaRotEsq(NoVP * p){
	rotDir(p->getDir());
	rotEsq(p);
}

void ArvoreVP::duplaRotDir(NoVP * p){
	rotEsq(p->getEsq());
	rotDir(p);
}

/*
void ArvoreVP::remove(int value) {

    NoVP * p = busca(value);

    if (p == NULL)
        return;

    if (p== raiz) {
        raiz = NULL;
        return;
    }

    if (p->getCor() == 'v' || p->getEsq()->getCor() == 'v' || p->getDir()->getCor() == 'v') {
        NoVP *filho = p->esq != NULL ? p->esq : p->dir;

        if (p == p->pai->esq) {
            p->pai->esq = filho;
            if (filho != NULL)
                filho->pai = p->pai;
            filho->setCor('p');
            delete p;
        } else {
            p->pai->dir = filho;
            if (filho != NULL)
                filho->pai = p->pai;
            filho->setCor('p');
            delete p;
        }
    } else {
        NoVP * irmao = NULL;
        NoVP * pai = NULL;
        NoVP * ptr = p;
        ptr->setCor('p');
        while (ptr != raiz && ptr->getCor() == 'p') {
            pai = ptr->pai;
            if (ptr == pai->esq) {
                irmao = pai->dir;
                if (irmao->getCor() == 'v') {
                    irmao->setCor('p');
                    pai->setCor('v');
                    rotEsq(pai);
                } else {
                    if (irmao->getEsq()->getCor() == 'p' && irmao->getDir()->getCor() == 'p') {
                        irmao->setCor('v');
                        if(pai->getCor() == 'v')
                            pai->setCor('p');
                        else
                            pai->setCor('p');
                        ptr = pai;
                    } else {
                        if (irmao->getDir()->getCor() == 'p') {
                            irmao->getEsq()->setCor('p');
                            irmao->setCor('v');
                            rotDir(irmao);
                            irmao = pai->dir;
                        }
                        irmao->setCor(pai->getCor());
                        pai->setCor('p');
                        irmao->getDir()->setCor('p');
                        rotEsq(pai);
                        break;
                    }
                }
            } else {
                irmao = pai->esq;
                if (irmao->getCor() == 'v') {
                    irmao->setCor('p');
                    pai->setCor('v');
                    rotDir(pai);
                } else {
                    if (irmao->getEsq()->getCor() == 'p' && irmao->getDir()->getCor() == 'p') {
                        irmao->setCor('v');
                        if (pai->getCor() == 'v')
                            pai->setCor('p');
                        else
                            pai->setCor('p');
                        ptr = pai;
                    } else {
                        if (irmao->getEsq()->getCor() == 'p') {
                            irmao->getDir()->setCor('p');
                            irmao->setCor('v');
                            rotEsq(irmao);
                            irmao = pai->esq;
                        }
                        irmao->setCor(pai->getCor());
                        pai->setCor('p');
                        irmao->getEsq()->setCor('p');
                        rotDir(pai);
                        break;
                    }
                }
            }
        }
        if (p== p->pai->esq)
            p->pai->esq = NULL;
        else
            p->pai->dir = NULL;
        delete p;
        raiz->setCor('p');
    }
}*/