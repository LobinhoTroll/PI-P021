#ifndef LIVROSFUNCTIONS_HPP
#define LIVROSFUNCTIONS_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Livro
{
private:
    string codigo;
    string titulo;
    string autor;
    int numeroCopias;
    int numeroEmprestimos; 
public:
    static void setLivrosinfo(string codigo,string titulo,string autor,int numeroCopias,vector<Livro> &Lista);
    static void getLivrosinfo();
    static void mostrarLista(vector<Livro> Lista);
    static void mostrarLivro(vector<Livro> Lista,int posicao);
};

string codigo_,titulo_,autor_;
int numeroCopias_;

void Livro::getLivrosinfo(){

    cout << "Informe o título do livro: ";
    cin >> titulo_;
    cout << "Informe o autor do livro: ";
    cin >> autor_;
    cout << "Informe o número de cópias disponiveis: ";
    cin >> numeroCopias_;

}

void Livro::setLivrosinfo(string codigo,string titulo,string autor,int numeroCopias,vector<Livro> &Lista){
    
    Livro livro;
    livro.titulo = titulo;
    livro.autor = autor;
    livro.numeroCopias = numeroCopias;
    livro.codigo = codigo;

    Lista.push_back(livro);

}

void Livro::mostrarLista(vector<Livro> Lista){
for (int i = 0; i < Lista.size(); i++){
    cout << i+1 << ". " << Lista[i].titulo << endl;
    }
}

void Livro::mostrarLivro(vector<Livro> Lista,int posicao){

    cout << "Títuo: " << Lista[posicao].titulo << endl;
    cout << "Autor: " << Lista[posicao].autor << endl;
    cout << "Numero de copias na biblioteca: " << Lista[posicao].numeroCopias << endl;
    cout << "codigo : " << Lista[posicao].codigo << endl;
}

#endif



