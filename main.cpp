#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Livro {
private:
    int codigo;
    string titulo;
    string autor;
    int numeroCopias;

public:
    Livro(string titulo, string autor, int numeroCopias);
    int getCodigo() const;
    string getTitulo() const;
    string getAutor() const;
    int getNumeroCopias() const;
    void setNumeroCopias(int copias);
};

Livro::Livro(string titulo, string autor, int numeroCopias) {
    this->codigo = rand() % 1001;
    this->titulo = titulo;
    this->autor = autor;
    this->numeroCopias = numeroCopias;
}
//gets
int Livro::getCodigo() const {
    return codigo;
}
string Livro::getTitulo() const {
    return titulo;
}
string Livro::getAutor() const {
    return autor;
}
int Livro::getNumeroCopias() const {
    return numeroCopias;
}
//sets
void Livro::setNumeroCopias(int copias) {
    numeroCopias = copias;
}

class Usuario
{
private:
    string nome;
    string cpf;
    int id;
public:
    //gets
    string getNome();
    string getCpf();
    int getId();
    //sets
    void setNomeUsuario(string nome);
    void setCpfUsuario(string cpf);
    //outras funções
    Usuario(string nome, string cpf, int id);
};
Usuario::Usuario(string nome, string cpf, int id) {
    this->nome = nome;
    this->cpf = cpf;
    this->id = rand() % 1001;
}
string Usuario::getNome(){
    return nome;
}
string Usuario::getCpf(){
    return cpf;
}
int Usuario::getId(){
    return id;
};
void Usuario::setNomeUsuario(string nome_){
    nome = nome_;
};
void Usuario::setCpfUsuario(string cpf_){
    nome = cpf_;
};


class Biblioteca {
private:
    vector<Livro> ListaLivros;
    vector<Usuario> ListaUsuarios;
public:
    void cadastrarLivro();
    void cadastrarUsuario();
    int localizarUsuarioPorId(int id);
    void mostrarLista() const;
    void exibirInformacaoLivro(int index) const;
    int localizarLivroPorId(int id);
    void listarEmprestimosDoUsuario(vector<Livro> emprestimos);
};
int Biblioteca::localizarUsuarioPorId(int id){
    for (int i = 0; i < ListaUsuarios.size(); ++i) {
        if (ListaUsuarios[i].getId() == id) {
            return i; // Retorna o índice do livro encontrado na lista
        }
    }
    return -1; // Retorna -1 se o livro com o ID especificado não for encontrado
}

void Biblioteca::listarEmprestimosDoUsuario(vector<Livro> emprestimos){
    int index = 1;
    for (const auto& livro : emprestimos) {
        cout << index << ". Código: " << livro.getCodigo() << " | Título: " << livro.getTitulo() << endl;
        index++;
    }
}

// Função para cadastrar ou atualizar as informações de um usuario
void Biblioteca::cadastrarUsuario() {
    string nome, cpf;
    char confirm;
    int id;

    cout << "\nInforme o ID do usuario: ";
    cin >> id;

    // Verifica se o usuario já existe na lista
    int indiceUsuario = localizarUsuarioPorId(id);
    if (indiceUsuario != -1) {
        // Livro encontrado, pede para atualizar o número de cópias
        cout << "O usuario já está cadastrado na biblioteca. Informe o as informações que deseja atualizar: ";
        cout << "Deseja alterar o nome? S/N" << endl;
        cin >> confirm;
        if (confirm == 'S'||confirm == 's')
        {
            cout << "Informe o novo nome:";
            cin >> nome;
            ListaUsuarios[indiceUsuario].setNomeUsuario(nome);
        }
        cout << "Deseja alterar o cpf? S/N" << endl;
        cin >> confirm;
        if (confirm == 'S'||confirm == 's')
        {
            cout << "Informe o novo cpf:";
            cin >> nome;
            ListaUsuarios[indiceUsuario].setCpfUsuario(cpf);
        }
        cout << "\nIformações do usuario atualizadas com sucesso!\n";
    } else {
        // Livro não encontrado, cadastra um novo livro
        cout << "\nInforme o nome do usuario: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Informe o cpf do usuario: ";
        getline(cin, cpf);
        id = rand() % 1001;

        Usuario novoUsuario(nome, cpf, id);
        ListaUsuarios.push_back(novoUsuario);
        cout << "\nUsuario cadastrado com sucesso!\n";
    }
}

// Função para localizar um livro por ID na lista
int Biblioteca::localizarLivroPorId(int id) {
    for (int i = 0; i < ListaLivros.size(); ++i) {
        if (ListaLivros[i].getCodigo() == id) {
            return i; // Retorna o índice do livro encontrado na lista
        }
    }
    return -1; // Retorna -1 se o livro com o ID especificado não for encontrado
}

// Função para cadastrar ou atualizar o número de cópias de um livro
void Biblioteca::cadastrarLivro() {
    string titulo, autor;
    int numeroCopias, id;

    cout << "\nInforme o ID do livro: ";
    cin >> id;

    // Verifica se o livro já existe na lista
    int indiceLivro = localizarLivroPorId(id);
    if (indiceLivro != -1) {
        // Livro encontrado, pede para atualizar o número de cópias
        cout << "O livro já existe na biblioteca. Informe o número de cópias adicionais: ";
        cin >> numeroCopias;
        ListaLivros[indiceLivro].setNumeroCopias(ListaLivros[indiceLivro].getNumeroCopias() + numeroCopias);
        cout << "\nNúmero de cópias atualizado com sucesso!\n";
    } else {
        // Livro não encontrado, cadastra um novo livro
        cout << "\nInforme o título do livro: ";
        cin.ignore();
        getline(cin, titulo);
        cout << "Informe o nome do autor do livro: ";
        getline(cin, autor);
        cout << "Informe o número de cópias disponíveis: ";
        cin >> numeroCopias;

        Livro novoLivro(titulo, autor, numeroCopias);
        ListaLivros.push_back(novoLivro);
        cout << "\nLivro cadastrado com sucesso!\n";
    }
}
void Biblioteca::mostrarLista() const {
    int index = 1;
    for (const auto& livro : ListaLivros) {
        cout << index << ". Código: " << livro.getCodigo() << " | Título: " << livro.getTitulo() << " | Autor: " << livro.getAutor() << " | Número de cópias: " << livro.getNumeroCopias() << endl;
        index++;
    }
}

void Biblioteca::exibirInformacaoLivro(int index) const {
    if (index >= 0 && index < ListaLivros.size()) {
        const Livro& livro = ListaLivros[index];
        cout << "\nInformações do Livro" << endl;
        cout << "Código: " << livro.getCodigo() << endl;
        cout << "Título: " << livro.getTitulo() << endl;
        cout << "Autor: " << livro.getAutor() << endl;
        cout << "Número de cópias: " << livro.getNumeroCopias() << endl;
    } else {
        cout << "\nLivro não encontrado." << endl;
    }
}

int main() {
    srand((time(0)));
    Biblioteca biblioteca;

    char continuar = 'S';
    do {
        int operacaoLivro;
        cout << "==== Escolha o tipo de operação ====" << endl;
        cout << "1. Cadastrar Livro" << endl;
        cout << "2. Mostrar Lista de Livros" << endl;
        cout << "3. Exibir Informações de um Livro" << endl;
        cin >> operacaoLivro;

        switch (operacaoLivro) {
            case 1:
                biblioteca.cadastrarLivro();
                break;
            case 2:
                biblioteca.mostrarLista();
                break;
            case 3:
                int indice;
                cout << "Informe o índice do livro: ";
                cin >> indice;
                indice = biblioteca.localizarLivroPorId(indice);
                biblioteca.exibirInformacaoLivro(indice); // Subtrai 1 porque os índices começam em 1 no menu
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }

        cout << "\nDeseja continuar? (S/N) ";
        cin >> continuar;

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
