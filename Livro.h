#include <iostream>
#include "lib.h"

using namespace std;

class Livro{
    
    public:
        string * author;       //authors: lista de ids de autores entre colchetes e separados por vírgulas (os nomes dos autores associados aos ids estão em authors.csv)
        string * categories; //categories: lista de ids de categorias de livros (os nomes das categorias estão em categories.csv)   
        int tam_categorias;  //quantidade de categorias
        int id;              //id: id único do livro atribuído pelo Bookdepository.com (int)
        string title;        //title: título (str)
        int rank;            //bestsellers-rank: ranking na lista de mais vendidos (int)
        float rating;        //rating-avg: avaliação média 0-5 <---------------------------------------------------------- ver se é float ou int
        int count;           //rating-count: número de avaliações
        string edition;      //edition: edição (str)
        string isbn10;       //isbn10: ISBN-10 (str)
        string isbn13;       //isbn13: ISBN-13 (str)

        //Funções
        Livro(){
        };
        ~Livro();

        //Set
        void setAuthor(string * autor){ author = autor;}
        void setCategories(string * categorias, int tam){ categories = categorias, tam_categorias = tam;}
        void setId(int numero){ id = numero;}
        void setTitle(string titulo){ title = titulo;}
        void setRank(int numero){ rank = numero;}
        void setRating(float avaliacao){ rating = avaliacao;}
        void setCount(int numero){ count = numero;}
        void setEdition(string edicao){ edition = edicao;}
        void setIsbn10(string isbn){ isbn10 = isbn;}
        void setIsbn13(string isbn){ isbn13 = isbn;}

        //Get
        string * getAuthor(){ return author;}
        string * getCategories(){ return categories;}
        int getId(){ return id;}
        string getTitle(){ return title;}
        int getRank(){ return rank;}
        float getRating(){ return rating;}
        int getCount(){ return count;}
        string getEdition(){ return edition;}
        string getIsbn10(){ return isbn10;}
        string getIsbn13(){ return isbn13;}
};