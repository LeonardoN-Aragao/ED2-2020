#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <sstream>

using namespace std;

struct dados{
    int id;
    string dado;
};

class lib{

    public:
        dados * autores;
        dados * categorias;
        int tam_autores;
        int tam_categorias;

        lib(){ //Carrega os arquivos adicionais

            tam_autores = 50465;
            tam_categorias = 2540;

            autores = new dados[tam_autores];
            categorias = new dados[tam_categorias];

            fstream file;
            file.open("archive/authors.csv", fstream::binary | fstream::in);

            if(file.is_open()){

                string data;
                getline(file,data);

                int i = 0;
                while(!file.eof()){
                    getline(file,data,'"');
                    getline(file,data,'"');

                    if(data.empty())
                        break;

                    autores[i].id = stoi(data);

                    getline(file,data,'"');
                    getline(file,data);
                    data.erase(data.length()- 1); //Para tirar a "
                    autores[i].dado = data;
                    i++;
                }
                file.close();
            }

            file.open("archive/categories.csv", fstream::binary | fstream::in);

            if(file.is_open()){

                string data;
                getline(file,data);

                int i = 0;
                while(!file.eof()){
                    getline(file,data,'"');
                    getline(file,data,'"');

                    if(data.empty())
                        break;
                        
                    categorias[i].id = stoi(data);

                    getline(file,data,'"');
                    getline(file,data);
                    data.erase(data.length()- 1); //Para tirar a "
                    categorias[i].dado = data;
                    i++;
                }
                file.close();
            }
        }

        //@data sao os dados recebidos da leitura
        //@indice pode ser 0 (autor) ou 1 (categorias)
        string* getCod(string data, int indice) //pega os codigos e poe num vetor. Pode mudar
        {
            istringstream saux(data);//auxiliar para calcular o tamanho do vetor com os dados recebidos
            string aux;

            int tamanho = 0;
            while (getline(saux,aux,','))//calculando o tamanho do vetor
                tamanho++;

            saux.seekg (0, saux.beg);
            int vetCod[tamanho];
            string token;
            int i=0;

            while (i<tamanho){//quebrando a string pelas virgulas
                getline(saux,token,',');
                vetCod[i] = atoi(token.c_str());
                i++;
            }

            return converte(vetCod,tamanho,indice);
        }

    private:
        string auxConverte(int id, int indice){
            
            if(indice == 0){
                for(int i = 0; i<tam_autores ; i ++){
                    if (autores[i].id == id)
                        return autores[i].dado;
                } 
            }
            else if(indice == 1){
                for(int i = 0; i<tam_categorias ; i ++){
                    if (categorias[i].id == id)
                        return categorias[i].dado;
                } 
            }
            return NULL;
        }

        string * converte(int * vet, int tam, int indice){ //Converte Id para o nome do authores e categorias 
    
            string * resp = new string[tam];

            for(int i = 0; i<tam ; i ++){
                resp[i] = auxConverte(vet[i], indice);
            } 
            return resp;
        }
};

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
    troca(&vet[m],&vet[fim]); //trocando a posicacao do elemento medio com o ultimo, para usar a versao recursiva classica do QS

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

void quickSort(int vet[],int inicio,int fim)
{
    if (inicio<fim)
    {

        int part = particao(vet,inicio,fim);
        quickSort(vet,inicio,part-1);
        quickSort(vet,part+1,fim);
    }
}

void heap_func(int vet[], int tam, int m) //Criando a arvore para a ordenacao do heapsort
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

//Implementacao dos algoritmos de ordenacao para strings
void string_troca(string* a, string* b)//Funcao troca adaptada para strings
{
    string t = *a;
    *a=*b;
    *b=t;
}

int string_particao (string vet[], int inicio, int fim)//funcao auxiliar do algoritmo de ordenacao quicksort, adapatada para string
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
    string_troca(&vet[m],&vet[fim]);

    string pivo = vet[fim];
    int i=(inicio-1);
    for (int j = inicio;j<=fim;j++)
    {
        if (vet[j]<pivo)
        {
            i++;
            string_troca(&vet[i],&vet[j]);
        }
    }
    string_troca(&vet[i+1],&vet[fim]);
    return (i+1);
}

void string_quickSort(string vet[],int inicio,int fim) //chamada principal do quicksort recursivo adaptada para strings
{
    if (inicio<fim)
    {

        int part = string_particao(vet,inicio,fim);
        string_quickSort(vet,inicio,part-1);
        string_quickSort(vet,part+1,fim);
    }
}

void string_heap_func(string vet[], int tam, int m) //funcao auxiliar do heapsort adaptada para strings
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
		string_heap_func(vet,tam,maior);
	}
}

void string_heapSort(string vet[], int tam) //chamada principal do heapsort adaptada para strings
{
	for (int i=tam/2 - 1; i>=0; i--)
		string_heap_func(vet,tam,i);
	for (int i=tam-1; i>=0; i--)
	{
		swap(vet[0],vet[i]); //*
		string_heap_func(vet,i,0);
	}
}


#endif