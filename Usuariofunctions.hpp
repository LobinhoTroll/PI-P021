#ifndef USUARIOFUNCTIONS_HPP
#define USUARIOFUNCTIONS_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Usuario
{
private:
    string nome;
    string cpf;
public:
    static void getUserinfo();
};

string nome_,cpf_;

void Usuario::getUserinfo(){

    cout << "Informe o título do livro: ";
    cin >> nome_;
    cout << "Informe o autor do livro: ";
    cin >> cpf_;

}

#endif