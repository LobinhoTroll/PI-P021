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
    int contadorUsuarios = 1;
};

#endif