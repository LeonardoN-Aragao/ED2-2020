#include <iostream>
#include <fstream>
#include <math.h>
#include "lib.h"
#include "Livro.h"

using namespace std;

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