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
#endif