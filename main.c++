#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "funcoesLivro.c++"
#include "funcoesUsuario.c++"

using namespace std;

class ListaLivrosEmprestimos
{

private:
    vector<string> UsuarioList;
    string *Emprestimos;
    string DataEmprestimo;
public:
    string livros;
    vector<class> LivrosList;

};

class Livros
{
private:
    string codigo;
public:
     int contadorLivros = 1;
     string titulo;
     string autor;
     int numeroCopias;
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

cadastrarLivro();

}