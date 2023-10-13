#include <iostream>
#include <vector>
#include <string>
#include <array>


using namespace std;

class Biblioteca
{
private:
    
public:
    
};
class Livros
{
private:
    //static int contadorLivros;
public:
    string codigo;
    string titulo;
    string autor;
    int numeroCopias;
    //void cadastrarLivro();
};


/*void Livros::cadastrarLivro(){
contadorLivros++;
string codigo,titulo,autor;
int numeroCopias;

    cout << "Informe o título do livro: ";
    cin >> titulo;
    cout << "Informe o autor do livro: ";
    cin >> autor;
    cout << "Informe o número de cópias disponiveis: ";
    cin >> numeroCopias;
    
    Livros livro;
    livro.titulo = titulo;
    livro.autor = autor;
    livro.numeroCopias = numeroCopias;
    livro.codigo = "123";

};*/
class Usuario
{
private:
    string nome;
    string cpf;
public:
    int contadorUsuarios = 1;
};

void cadastrarLivro(vector<Livros> &Lista){

string codigo_,titulo_,autor_;
int numeroCopias_;

    cout << "Informe o título do livro: ";
    cin >> titulo_;
    cout << "Informe o autor do livro: ";
    cin >> autor_;
    cout << "Informe o número de cópias disponiveis: ";
    cin >> numeroCopias_;
    
    Livros livro;
    livro.titulo = titulo_;
    livro.autor = autor_;
    livro.numeroCopias = numeroCopias_;
    livro.codigo = "123";

    Lista.push_back(livro);
    cout << Lista.size() << endl;
    cout <<Lista[0].titulo;
    
    
};

int main(){
vector<Livros> LivrosList;
/*
string codigo,titulo,autor;
int numeroCopias;

    cout << "Informe o título do livro: ";
    cin >> titulo;
    cout << "Informe o autor do livro: ";
    cin >> autor;
    cout << "Informe o número de cópias disponiveis: ";
    cin >> numeroCopias;
    
    Livros livro;
    livro.titulo = titulo;
    livro.autor = autor;
    livro.numeroCopias = numeroCopias;
    livro.codigo = "123";
*/
    cadastrarLivro(LivrosList);
    cout << LivrosList.size();
    cout << LivrosList[0].autor;
    
    
    

};