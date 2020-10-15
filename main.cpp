#include <iostream>
#include <fstream>
#include <math.h>

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

        int bloco = tamanho%1000;
        char * buffer = new char [bloco];

        while(!file.eof()){
            file.read(buffer,bloco);
            //shuffle(buffer,&(buffer[bloco]),bloco);
            for(int i = 0; i < bloco; i++){
                cout << buffer[i]; 
            }
            cout<<"\n";
        }

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

void quickSort(int vet[],int inicio,int fim)
{
    if (inicio<fim)
    {

        int part = particao(vet,inicio,fim);
        quickSort(vet,inicio,part-1);
        quickSort(vet,part+1,fim);
    }
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
    
    //Passar para .h depois 
    
    //pegar depois dos arquivos 
    //authors: lista de ids de autores entre colchetes e separados por vírgulas (os nomes dos autores associados aos ids estão em authors.csv)
    //categories: lista de ids de categorias de livros (os nomes das categorias estão em categories.csv)
    
    int id;         //id: id único do livro atribuído pelo Bookdepository.com (int)
    string title;   //title: título (str)
    int rank;       //bestsellers-rank: ranking na lista de mais vendidos (int)
    float rating;   //rating-avg: avaliação média 0-5 <---------------------------------------------------------- ver se é float ou int
    int count;      //rating-count: número de avaliações
    string edition; //edition: edição (str)
    string isbn10;  //isbn10: ISBN-10 (str)
    string isbn13;  //isbn13: ISBN-13 (str)


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
