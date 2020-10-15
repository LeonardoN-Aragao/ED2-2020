#include <iostream>
#include <fstream>
#include <math.h>
#include "Livro.h"

using namespace std;

void shuffle (char* first, char* last,int tam){
     
  iterator_traits<char*>::difference_type i, n;
  for (i=tam-1; i>0; --i) {
    swap(first[i],first[rand()%tam]);
  }
}

void lerArquivo(){

    fstream file;
    file.open("archive/formats.csv", fstream::binary | fstream::in);

    if(file.is_open()){

        // Pega o tamanho do arquivo
        file.seekg (0, file.end);
        int tamanho = file.tellg();
        file.seekg (0, file.beg);

        int bloco = 8192;
        char * buffer = new char [bloco];

        int i = 0;
        while(!file.eof()){
            char * aux;
            file.read(aux,bloco);
            
            sprintf(buffer,"%s%s",buffer,aux);


            for(int j = 0; j < bloco; j++){
                cout << buffer[j];
            }
            cout<<"\n";
            i++;
            file.seekg(file.cur-(bloco-i));
        }
        shuffle(buffer,&(buffer[bloco]),bloco);
        file.close();
    }
}

void troca(int* a, int* b) // funcao troca para o QS. Necessita da troca por endercos e nao apenas de valores como o swap
{
    int t = *a;
    *a=*b;
    *b=t;
}

int particao (int vet[], int inicio, int fim)
{
    int meio = (inicio+fim)/2;
    int m = 0;

    if (vet[inicio]<vet[meio])
    {
        if (vet[meio]<vet[fim])
        {
            m = meio;
        }
        else
        {
            if (vet[inicio]<vet[fim])
            {
                m = fim;
            }
            else
            {
                m = inicio;
            }
        }
    }
    else
    {
        if (vet[fim]<vet[meio])
        {
            m = meio;
        }
        else
        {
            if (vet[fim]<vet[inicio])
            {
                m = fim;
            }
            else
            {
                m = inicio;
            }
        }
    }
    troca(&vet[m],&vet[fim]);

    int pivo = vet[fim];
    int i=(inicio-1);
    for (int j = inicio;j<=fim;j++)
    {
        if (vet[j]<pivo)
        {
            i++;
            troca(&vet[i],&vet[j]);
        }
    }
    troca(&vet[i+1],&vet[fim]);
    return (i+1);
}

void heap_func(int vet[], int tam, int m)
{
 	int maior = m;
	int esq = 2*m+1;
	int dir = 2*m+2;

	if (esq<tam && vet[esq]>vet[maior])
	{
		maior = esq;
	}

	if (dir<tam && vet[dir]>vet[maior])
	{
		maior = dir;
	}

	if (maior != m)
	{
		swap(vet[m],vet[maior]);
		heap_func(vet,tam,maior);
	}
}

void heapSort(int vet[], int tam)
{
	for (int i=tam/2 - 1; i>=0; i--)
		heap_func(vet,tam,i);
	for (int i=tam-1; i>=0; i--)
	{
		swap(vet[0],vet[i]);
		heap_func(vet,i,0);
	}
}

//implementar o quicksort e o heapsort

int main(int args_tam, char *args[]){

    //"authors","bestsellers-rank","categories","description","dimension-x","dimension-y","dimension-z","edition","edition-statement","for-ages","format","id","illustrations-note","imprint","index-date","isbn10","isbn13","lang","publication-date","publication-place","rating-avg","rating-count","title","url","weight"

    //Marca tempo total
    clock_t begin, end, total_time;
    begin = clock();
    
    //Codigo
    lerArquivo();
    end = clock();

    //Salvado dados importantes para relatorio


    total_time = (end - begin) / CLOCKS_PER_SEC;
    cout<< "Tempo total: " << total_time << "\n";

    return 0;
}
