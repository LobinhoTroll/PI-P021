
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

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
    Livro(int codigo,string titulo,string autor,int numeroCopias);
    void setLivrosinfo(int codigo,string titulo,string autor,int numeroCopias);
    void getLivrosinfo();
    void mostrarLista(vector<Livro> Lista);   
};
//construtores
Livro::Livro(){};
Livro::Livro(int codigo,string titulo,string autor,int numeroCopias){
    this->codigo = codigo;
    this->titulo = titulo;
    this->autor = autor;
    this->numeroCopias = numeroCopias;
   

};

//get das informações de um livro
void Livro::getLivrosinfo(){

    cout << "\nTítulo do livro: " << titulo << endl;
    cout << "\nAutor do livro: " << autor << endl;
    cout << "\nNúmero de cópias disponiveis: " << numeroCopias << endl;
    cout << endl;
}

//set das informações do livro 
void Livro::setLivrosinfo(int codigo,string titulo,string autor,int numeroCopias){
    
    this->codigo = codigo;
    this->titulo = titulo;
    this->autor = autor;
    this->numeroCopias = numeroCopias;
}

//mostra a lista de livros cadastrados(to na duvida se esta feito corretamente)
void Livro::mostrarLista(vector<Livro> Lista){
for (int i = 0; i < Lista.size(); i++){
    cout << i+1 << ". " << Lista[i].titulo << endl;
    }
}

//get das informações para cadastrar o livro
void getCadastoInfo(string &titulo,string &autor,int &numeroCopias,int &codigo){

    cout << "\nInforme o título do livro: "; 
    cin >> titulo;
    cout << "\nInforme o nome  do autor do livro: "; 
    cin >> autor;
    cout << "\nInforme o numero de cópias disponiveis: "; 
    cin >> numeroCopias;
    codigo = rand() % 1001;
    cout << endl;

}

//menu para operações com livro
void menuLivro(int &operacaoLivro){

    cout << "==== Escolha o tipo de operação ====" << endl;
    cout << "1. Cadastrar." << endl;
    cout << "2. Listar." << endl;
    cout << "3. Exibir informação de um livro.\n" << endl;
    
    cin >> operacaoLivro;

}

//variaveis
string autor,titulo;
char continuar = 'S';
int codigo,numeroCopias,operacaoLivro;

int main(){
    srand(time(0));
    vector<Livro> LivrosList;
    Livro livro;
    
    
    do
    {
        menuLivro(operacaoLivro);
        switch (operacaoLivro)
        {
        case 1:
            getCadastoInfo(titulo,autor,numeroCopias,codigo);
            livro.setLivrosinfo(codigo,titulo,autor,numeroCopias);
            LivrosList.push_back(livro);       
        break;
        
        case 2:
            livro.mostrarLista(LivrosList);
        break;    
        case 3:
            //teoricamente é pra exibir as informações de um livro em especifico mas eu não pensei em um modo bom de fazer
        break;
        
        cout << "Deseja continuar? S/N";
        cin >> continuar;
        }
    } while (continuar == 'S'|| continuar == 's');
    

};
