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

class Biblioteca {
private:
    vector<Livro> ListaLivros;

public:
    void cadastrarLivro();
    void mostrarLista() const;
    void exibirInformacaoLivro(int index) const;
    int localizarLivroPorId(int id);
};

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
