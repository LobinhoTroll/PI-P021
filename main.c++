#include <iostream>
#include <vector>
#include <array>
#include "Livrofunctions.hpp"
#include <string>
using namespace std;

class Biblioteca
{
private:
    
public:
    
};

class Usuario
{
private:
    string nome;
    string cpf;
public:
    int contadorUsuarios = 1;
};


int main(){
vector<Livro> LivrosList;

    Livro::getLivrosinfo();
    Livro::setLivrosinfo(codigo_,titulo_,autor_,numeroCopias_,LivrosList);
    Livro::mostrarLista(LivrosList);
};
