#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <sstream>

using namespace std;

void lerArquivo(){

    fstream file;
    file.open("archive/dataset.csv", fstream::binary | fstream::in);


    //"authors","bestsellers-rank","categories","description","dimension-x","dimension-y","dimension-z","edition","edition-statement","for-ages","format","id","illustrations-note","imprint","index-date","isbn10","isbn13","lang","publication-date","publication-place","rating-avg","rating-count","title","url","weight"

    if(file.is_open()){

        // Pega o tamanho do arquivo
        file.seekg (0, file.end);
        int tamanho = file.tellg();
        file.seekg (0, file.beg);

        string data;
        getline(file,data);

        while(!file.eof()){
            
            getline(file,data,'[');
            getline(file,data,']');
            cout<<"autor: "<<data<<endl;
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');
            cout<<"rank: "<<data<<endl;

            getline(file,data,'[');
            getline(file,data,']');
            cout<<"categorias: "<<data<<endl;
            getline(file,data,'"');

            getline(file,data,'"');
            bool verifica = false;
            string buffer;
            data = "";
            while(!verifica){

                getline(file, buffer, '"');
                data = data + buffer;

                char aux;
                file.get(aux);
                if(aux == ','){
                    file.get(aux);
                    if(aux == '"')
                        verifica = true;
                
                    else
                        file.unget();
                }
                else
                    file.unget();
            }

            cout<<"descricao: "<<data<<endl;

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            cout<<"edicao: "<<data<<endl;

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');
            cout<<"id: "<<data<<endl;

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');
            cout<<"isbn10: "<<data<<endl;

            getline(file,data,'"');
            getline(file,data,'"');
            cout<<"isbn13: "<<data<<endl;

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');
            cout<<"rating: "<<data<<endl;

            getline(file,data,'"');
            getline(file,data,'"');
            cout<<"count: "<<data<<endl;

            getline(file,data,'"');
            getline(file,data,'"');
            cout<<"titulo: "<<data<<endl;

            getline(file,data);
            cout<<endl;
        }
        //shuffle(comeco,fim,std::default_random_engine(seed));
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