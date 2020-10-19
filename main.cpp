#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include "lib.h"
#include "Livro.h"

using namespace std;

//VARIAVEIS ESTATISTICAS DE: Trocas de posicao, comparacoes de valores e tempo de execucao do algoritmo
int trocaQS_id = 0;
int compQS_id = 0;
int trocaHS_id = 0;
int compHS_id = 0;
int trocaQS_title = 0;
int compQS_title = 0;
int trocaHS_title = 0;
int compHS_title = 0;
double ti = 0;
double tf = 0;

int main(int args_tam, char *args[]){

    //"authors","bestsellers-rank","categories","description","dimension-x","dimension-y","dimension-z","edition","edition-statement","for-ages","format","id","illustrations-note","imprint","index-date","isbn10","isbn13","lang","publication-date","publication-place","rating-avg","rating-count","title","url","weight"

    //Marca tempo total
    clock_t begin, end, total_time;
    begin = clock();
    
    //Codigo
    lib a;
    lerArquivo();

    end = clock();

    //Salvado dados importantes para relatorio


    total_time = (end - begin) / CLOCKS_PER_SEC;
    cout<< "Tempo total: " << total_time << "\n";

    FILE* saida;
    saida = fopen("saida.txt","w");
    if (saida==NULL)
    {
        cout<<"\nErro na criacao do arquivo!"<<endl;
        return 0;
    }
    //CODIGO DE LEITURA DO ARQUIVO. Estou suponto que os Livro estejam armazenados em Livro* lib.

    //Variando o indice entre 0 e 1, temos a ordenacao via ID e a ordenacao via titulo

    //Como o tamanho do vetor nao obedece uma logica, eu nao vi outra forma senao essa de implementar. Nao vi como fazer por um loop, uma vez que os saltos sao alternados
    int tam = 1000;
    fprintf(saida,"\nIniciando a Ordenacao do vetor de Livro com tamanho igual a: %d\n",tam);
    auxOrdena(a,0,tam);
    fprintf(saida,"\nO Metodo QS ordenando conforme o ID dos Livro fez %d comparacoes e %d trocas.\n",compQS_id,trocaQS_id);
    fprintf(saida,"\nO Metodo HS ordenando conforme o ID dos Livro fez %d comparacoes e %d trocas.\n",compHS_id,trocaHS_id);
    auxOrdena(a,1,tam);
    fprintf(saida,"\nO Metodo QS ordenando conforme o titulo dos Livro fez %d comparacoes e %d trocas.\n",compQS_title,trocaQS_title);
    fprintf(saida,"\nO Metodo HS ordenando conforme o titulo dos Livro fez %d comparacoes e %d trocas.\n",compHS_title,trocaHS_title);

    int tam = 5000;
    fprintf(saida,"\nIniciando a Ordenacao do vetor de Livro com tamanho igual a: %d\n",tam);
    auxOrdena(a,0,tam);
    fprintf(saida,"\nO Metodo QS ordenando conforme o ID dos Livro fez %d comparacoes e %d trocas.\n",compQS_id,trocaQS_id);
    fprintf(saida,"\nO Metodo HS ordenando conforme o ID dos Livro fez %d comparacoes e %d trocas.\n",compHS_id,trocaHS_id);
    auxOrdena(a,1,tam);
    fprintf(saida,"\nO Metodo QS ordenando conforme o titulo dos Livro fez %d comparacoes e %d trocas.\n",compQS_title,trocaQS_title);
    fprintf(saida,"\nO Metodo HS ordenando conforme o titulo dos Livro fez %d comparacoes e %d trocas.\n",compHS_title,trocaHS_title);

    int tam = 10000;
    fprintf(saida,"\nIniciando a Ordenacao do vetor de Livro com tamanho igual a: %d\n",tam);
    auxOrdena(a,0,tam);
    fprintf(saida,"\nO Metodo QS ordenando conforme o ID dos Livro fez %d comparacoes e %d trocas.\n",compQS_id,trocaQS_id);
    fprintf(saida,"\nO Metodo HS ordenando conforme o ID dos Livro fez %d comparacoes e %d trocas.\n",compHS_id,trocaHS_id);
    auxOrdena(a,1,tam);
    fprintf(saida,"\nO Metodo QS ordenando conforme o titulo dos Livro fez %d comparacoes e %d trocas.\n",compQS_title,trocaQS_title);
    fprintf(saida,"\nO Metodo HS ordenando conforme o titulo dos Livro fez %d comparacoes e %d trocas.\n",compHS_title,trocaHS_title);

    int tam = 50000;
    fprintf(saida,"\nIniciando a Ordenacao do vetor de Livro com tamanho igual a: %d\n",tam);
    auxOrdena(a,0,tam);
    fprintf(saida,"\nO Metodo QS ordenando conforme o ID dos Livro fez %d comparacoes e %d trocas.\n",compQS_id,trocaQS_id);
    fprintf(saida,"\nO Metodo HS ordenando conforme o ID dos Livro fez %d comparacoes e %d trocas.\n",compHS_id,trocaHS_id);
    compHS_id=0;trocaHS_id=0;compQS_id=0;trocaQS_id=0;
    auxOrdena(a,1,tam);
    fprintf(saida,"\nO Metodo QS ordenando conforme o titulo dos Livro fez %d comparacoes e %d trocas.\n",compQS_title,trocaQS_title);
    fprintf(saida,"\nO Metodo HS ordenando conforme o titulo dos Livro fez %d comparacoes e %d trocas.\n",compHS_title,trocaHS_title);
    trocaHS_title=0,compHS_title=0;trocaQS_title=0;compQS_title=0;

    int tam = 100000;
    fprintf(saida,"\nIniciando a Ordenacao do vetor de Livro com tamanho igual a: %d\n",tam);
     auxOrdena(a,0,tam);
    fprintf(saida,"\nO Metodo QS ordenando conforme o ID dos Livro fez %d comparacoes e %d trocas.\n",compQS_id,trocaQS_id);
    fprintf(saida,"\nO Metodo HS ordenando conforme o ID dos Livro fez %d comparacoes e %d trocas.\n",compHS_id,trocaHS_id);
    compHS_id=0;trocaHS_id=0;compQS_id=0;trocaQS_id=0;
    auxOrdena(a,1,tam);
    fprintf(saida,"\nO Metodo QS ordenando conforme o titulo dos Livro fez %d comparacoes e %d trocas.\n",compQS_title,trocaQS_title);
    fprintf(saida,"\nO Metodo HS ordenando conforme o titulo dos Livro fez %d comparacoes e %d trocas.\n",compHS_title,trocaHS_title);
    trocaHS_title=0,compHS_title=0;trocaQS_title=0;compQS_title=0;

    return 0;
}


void Livro_troca(Livro* a, Livro* b)//Funcao troca adaptada para strings. Comum para a ordenacao via id ou titulo
{
    Livro t = *a;
    *a=*b;
    *b=t;
}

//ORDENACAO PARA IDs
int LivroParticao_id (Livro livro[], int inicio, int fim)//particionamento de Livro por conta do id
{
    int meio = (inicio+fim)/2;
    int m = 0;

    if ((livro[inicio].getId())<(livro[meio].getId()))// comparacao dos ids para decidir a mediana
    {
        if ((livro[meio].getId())<(livro[fim].getId()))
        {
            m = meio;
            compQS_id++;
        }
        else
        {
            if ((livro[inicio].getId())<(livro[fim].getId()))
            {
                m = fim;
                compQS_id++;
            }
            else
            {
                m = inicio;
                compQS_id++;
            }
        }
    }
    else
    {
        if ((livro[fim].getId())<(livro[meio].getId()))
        {
            m = meio;
            compQS_id++;
        }
        else
        {
            if ((livro[fim].getId())<(livro[inicio].getId()))
            {
                m = fim;
                compQS_id++;
            }
            else
            {
                m = inicio;
                compQS_id++;
            }
        }
    }
    Livro_troca(&livro[m],&livro[fim]); //troca do livro na posicao mediana para o da posicao final
    trocaQS_id++;

    int pivo = livro[fim].getId(); // selecao do pivo
    int i=(inicio-1);
    for (int j = inicio;j<=fim;j++)
    {
        if (livro[j].getId()<pivo) //comparacao do id de cada livro com o pivo
        {
            i++;
            Livro_troca(&livro[i],&livro[j]);
            trocaQS_id++;
            compQS_id++;
        }
    }
    Livro_troca(&livro[i+1],&livro[fim]);
    trocaQS_id++;
    compQS_id++;
    return (i+1); //retorno da particao
}

void Livro_quickSort_id(Livro livro[],int inicio,int fim) //chamada principal do quickSort para a ordenacao dos Livro com base no id
{
    if (inicio<fim)
    {

        int part = LivroParticao_id(livro,inicio,fim);
        Livro_quickSort_id(livro,inicio,part-1);
        Livro_quickSort_id(livro,part+1,fim);
    }
}

void livro_heap_func_id(Livro livro[], int tam, int m) //funcao auxiliar do heapsort adaptada para strings
{
	int maior = m;
	int esq = 2*m+1;
	int dir = 2*m+2;

	if (esq<tam && (livro[esq].getId())>(livro[maior].getId()))
	{
		maior = esq;
		compHS_id++;
	}

	if (dir<tam && (livro[dir].getId())>(livro[maior].getId()))
	{
		maior = dir;
		compHS_id++;
	}

	if (maior != m)
	{
		swap(livro[m],livro[maior]);//VALE VERIFICAR, Eu nao sei o funcionamento interno do swap e se ele vai conseguir trocar objetos do tipo livro. Se der problema, podemos implementar a troca padrao.
		trocaHS_id++;
		livro_heap_func_id(livro,tam,maior);
	}
}

void livro_heapSort_id(Livro livro[], int tam) //chamada principal do heapsort adaptada para Livro
{
	for (int i=tam/2 - 1; i>=0; i--)
		livro_heap_func_id(livro,tam,i);
	for (int i=tam-1; i>=0; i--)
	{
		swap(livro[0],livro[i]);
		trocaHS_id++;
		livro_heap_func_id(livro,i,0);
	}
}

//ORDENACAO PARA TITULOS
int LivroParticao_title (Livro livro[], int inicio, int fim)//particionamento de Livro por conta do titulo
{
    int meio = (inicio+fim)/2;
    int m = 0;

    if ((livro[inicio].getTitle())<(livro[meio].getTitle()))// comparacao dos titulos para decidir a mediana
    {
        if ((livro[meio].getTitle())<(livro[fim].getTitle()))
        {
            m = meio;
            compQS_title++;
        }
        else
        {
            if ((livro[inicio].getTitle())<(livro[fim].getTitle()))
            {
                m = fim;
                compQS_title++;
            }
            else
            {
                m = inicio;
                compQS_title++;
            }
        }
    }
    else
    {
        if ((livro[fim].getTitle())<(livro[meio].getTitle()))
        {
            m = meio;
            compQS_title++;
        }
        else
        {
            if (livro[fim].getTitle()<livro[inicio].getTitle())
            {
                m = fim;
                compQS_title++;
            }
            else
            {
                m = inicio;
                compQS_title++;
            }
        }
    }
    Livro_troca(&livro[m],&livro[fim]); //troca do livro na posicao mediana para o da posicao final
    trocaQS_title++;

    string pivo = livro[fim].getTitle(); // selecao do pivo
    int i=(inicio-1);
    for (int j = inicio;j<=fim;j++)
    {
        if (livro[j].getTitle()<pivo) //comparacao do titulo de cada livro com o pivo
        {
            i++;
            Livro_troca(&livro[i],&livro[j]);
            trocaQS_title++;
            compQS_title++;
        }
    }
    Livro_troca(&livro[i+1],&livro[fim]);
    trocaQS_title++;

    return (i+1); //retorno da particao
}

void Livro_quickSort_title(Livro livro[],int inicio,int fim) //chamada principal do quickSort para a ordenacao dos Livro com base no titulo
{
    if (inicio<fim)
    {

        int part = LivroParticao_title(livro,inicio,fim);
        Livro_quickSort_title(livro,inicio,part-1);
        Livro_quickSort_title(livro,part+1,fim);
    }
}

void livro_heap_func_livro(Livro livro[], int tam, int m) //funcao auxiliar do heapsort adaptada para strings
{
	int maior = m;
	int esq = 2*m+1;
	int dir = 2*m+2;

	if (esq<tam && (livro[esq].getTitle())>(livro[maior].getTitle()))
	{
		maior = esq;
		compHS_title++;
	}

	if (dir<tam && (livro[dir].getTitle())>(livro[maior].getTitle()))
	{
		maior = dir;
		compHS_title++;
	}

	if (maior != m)
	{
		swap(livro[m],livro[maior]);//VALE VERIFICAR, Eu nao sei o funcionamento interno do swap e se ele vai conseguir trocar objetos do tipo livro. Se der problema, podemos implementar a troca padrao.
		trocaHS_title++;
		livro_heap_func_id(livro,tam,maior);
	}
}

void livro_heapSort_title(Livro livro[], int tam) //chamada principal do heapsort adaptada para Livro
{
	for (int i=tam/2 - 1; i>=0; i--)
		livro_heap_func_livro(livro,tam,i);
	for (int i=tam-1; i>=0; i--)
	{
		swap(livro[0],livro[i]);
		trocaHS_title++;
		livro_heap_func_id(livro,i,0);
	}
}

void auxOrdena (Livro* lib, int indice, int tamanho)
{
    double tqs, ths; //VARIAVEIS PARA O CALCULO DE TEMPO GASTO
    //As variaveis de comparacao e troca serao executadas junto com os algoritmos, e sao globais

    Livro* livro = new Livro[tamanho];
    //ARMAZENAR OS Livro LIDOS EM UM VETOR DE TAMANHO tamanho;
    //Funcao de embaralhar o vetor

    switch (indice)
    {
    case 0:
        ti=double(clock());
        Livro_quickSort_id(livro,0,tamanho-1);//Como a funcao acessa a posicao enviada, @QS.fim = tamanho-1.
        tf=double(clock());
        tqs=(tf-ti)/CLOCKS_PER_SEC;
        ti=double(clock());//POSSO FAZER ASSIM OU TEM DE ZERAR A VARIAVEL?
        livro_heapSort_id(livro,tamanho);
        tf=double(clock());
        ths=(tf-ti)/CLOCKS_PER_SEC;
        ti=0;tf=0;
        break;
    case 1:
        ti=double(clock());
        Livro_quickSort_title(livro,0,tamanho-1);//Como a funcao acessa a posicao enviada, @QS.fim = tamanho-1.
        tf=double(clock());
        tqs=(tf-ti)/CLOCKS_PER_SEC;
        ti=double(clock());//POSSO FAZER ASSIM OU TEM DE ZERAR A VARIAVEL?
        livro_heapSort_title(livro,tamanho);
        tf=double(clock());
        ths=(tf-ti)/CLOCKS_PER_SEC;
        ti=0;tf=0;
        break;
    default:
        cout<<"\nCaso default no switch de ordenacao. ERRO!\n"<<endl;
        break;
    }
}