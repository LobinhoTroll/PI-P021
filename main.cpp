
#include <string>
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
    Livro();
    Livro(string codigo,string titulo,string autor,int numeroCopias);
    void setLivrosinfo(string codigo,string titulo,string autor,int numeroCopias);
    void getLivrosinfo();
    void mostrarLista(vector<Livro> Lista);
    void mostrarLivro(vector<Livro> Lista,int posicao);
};
Livro::Livro(){};
Livro::Livro(string codigo,string titulo,string autor,int numeroCopias){
    this->codigo = codigo;
    this->titulo = titulo;
    this->autor = autor;
    this->numeroCopias = numeroCopias;
   

};

void Livro::getLivrosinfo(){

    cout << "\nTítulo do livro: " << titulo << endl;
    cout << "\nAutor do livro: " << autor << endl;
    cout << "\nNúmero de cópias disponiveis: " << numeroCopias << endl;
    cout << endl;
}

void Livro::setLivrosinfo(string codigo,string titulo,string autor,int numeroCopias){
    
    this->codigo = codigo;
    this->titulo = titulo;
    this->autor = autor;
    this->numeroCopias = numeroCopias;
}

void Livro::mostrarLista(vector<Livro> Lista){
for (int i = 0; i < Lista.size(); i++){
    cout << i+1 << ". " << Lista[i].titulo << endl;
    }
}


int main(){
    vector<Livro> LivrosList;
    
    //string codigo,string titulo,string autor,int numeroCopias
    Livro livro("12345678","teste","autordoteste",10);
    LivrosList.push_back(livro);
    livro.getLivrosinfo();
    livro.mostrarLista(LivrosList);
};
