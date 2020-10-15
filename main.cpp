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