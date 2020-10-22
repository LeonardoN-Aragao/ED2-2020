#include <iostream>
#include <fstream>
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
clock_t tqs_id = 0; //tempo do QS para ID
clock_t ths_id = 0;// tempo do HS para ID
clock_t tqs_title = 0; //tempo do QS para title
clock_t ths_title = 0; //tempo do HS para title

void lerArquivo(Livro * livros, int quantidade){

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

        lib *aux = new lib();
        cout<<"Lendo arquivo"<<endl;
        int i = 0;
        while(i < quantidade){
            
            Livro p;
            getline(file,data,'[');
            getline(file,data,']');
            p.setAuthor(aux->getCod(data,0));
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');
            p.setRank(atoi(data.c_str()));

            getline(file,data,'[');
            getline(file,data,']');


            istringstream saux(data);//auxiliar para calcular o tamanho do vetor com os dados recebidos
            string a;

            int tamanho = 0;
            while (getline(saux,a,','))//calculando o tamanho do vetor
                tamanho++;

            p.setCategories(aux->getCod(data,1),tamanho);
            getline(file,data,'"');

            getline(file,data,'"');

            //para passar da descricao
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

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            p.setEdition(data);

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');
            p.setId(atoi(data.c_str()));

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');
            p.setIsbn10(data);

            getline(file,data,'"');
            getline(file,data,'"');
            p.setIsbn13(data);

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');

            getline(file,data,'"');
            getline(file,data,'"');
            p.setRating(atof(data.c_str()));

            getline(file,data,'"');
            getline(file,data,'"');
            p.setCount(atoi(data.c_str()));

            getline(file,data,'"');
            getline(file,data,'"');
            p.setTitle(data);

            getline(file,data);

            livros[i] = p;
            i++;
        }
        file.close();
        cout<<"Arquivo Lido"<<endl;
    }
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

void shuffle(Livro * livros, int tam){
    int index;
    Livro temp;
    srand(time(NULL)*clock());
    for (int i = tam - 1; i > 0; i--) {
        index = rand() % tam;

        temp = livros[index];
        livros[index] = livros[i];
        livros[i] = temp;
    }
}

void auxOrdena (Livro* livro, int indice, int tamanho)
{
    //As variaveis de comparacao e troca serao executadas junto com os algoritmos, e sao globais

    //Funcao de embaralhar o vetor
    shuffle(livro,tamanho);

    clock_t ti, tf; 

    switch (indice)
    {
    case 0:
        cout<<"ID"<<endl;
        ti=clock();
        Livro_quickSort_id(livro,0,tamanho-1);//Como a funcao acessa a posicao enviada, @QS.fim = tamanho-1.
        tf=clock();
        tqs_id=(tf-ti)/1000;
        ti=clock();//POSSO FAZER ASSIM OU TEM DE ZERAR A VARIAVEL?
        livro_heapSort_id(livro,tamanho);
        tf=clock();
        ths_id=(tf-ti)/1000;
        break;
    case 1:
        cout<<"TITLE"<<endl;
        ti=clock();
        Livro_quickSort_title(livro,0,tamanho-1);//Como a funcao acessa a posicao enviada, @QS.fim = tamanho-1.
        tf=clock();
        tqs_title=(tf-ti)/1000;
        ti=clock();//POSSO FAZER ASSIM OU TEM DE ZERAR A VARIAVEL?
        livro_heapSort_title(livro,tamanho);
        tf=clock();
        ths_title=(tf-ti)/1000;
        break;
    default:
        cout<<"\nCaso default no switch de ordenacao. ERRO!\n"<<endl;
        break;
    }
}

void exporta(int tam){

    //Variando o indice entre 0 e 1, temos a ordenacao via ID e a ordenacao via titulo
    fstream saida;
    saida.open("saida.txt", std::fstream::app);
    if (!saida.is_open())
    {
        cout<<"\nErro na criacao do arquivo!"<<endl;
        return;
    }

    cout<<"Teste "<< tam <<endl;
    Livro * livros = new Livro [tam];
    lerArquivo(livros,tam);

    saida << "Iniciando a Ordenacao do vetor de Livro com tamanho igual a: " << tam << endl;
    auxOrdena(livros,0,tam);
    saida << "\nO Metodo QS ordenando conforme o ID dos Livro fez "<< compQS_id<< " comparacoes e " << trocaQS_id << " trocas.\n";
    saida << "O Tempo gasto foi de: "<<tqs_id << endl;
    saida << "\nO Metodo HS ordenando conforme o ID dos Livro fez "<< compHS_id<< " comparacoes e " << trocaHS_id << " trocas.\n";
    saida << "O Tempo gasto foi de: "<<ths_id << endl;
    auxOrdena(livros,1,tam);
    saida << "\nO Metodo QS ordenando conforme o titulo dos Livro fez " << compQS_title << " comparacoes e "<< trocaQS_title << " trocas.\n";
    saida << "O Tempo gasto foi de: "<<tqs_title << endl;
    saida << "\nO Metodo HS ordenando conforme o titulo dos Livro fez " << compHS_title << " comparacoes e "<< trocaHS_title << " trocas.\n";
    saida << "O Tempo gasto foi de: "<<ths_title << endl;
    trocaHS_title=0,compHS_title=0;trocaQS_title=0;compQS_title=0;

    saida<<endl;

   cout<<"acabou "<< tam <<endl;

}

int main(int args_tam, char *args[]){

    if (args_tam = 2){

        string data;
        fstream file;
        file.open(args[1]);

        getline(file,data);
        int tam =  stoi(data);

        for(int i = 0; i<tam; i++){
            getline(file,data);
            exporta(stoi(data));
        }
    }

    return 0;
}