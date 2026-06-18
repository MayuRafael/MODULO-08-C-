#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Biblioteca {
private:
    string nome;
    vector<string> livros;

public:

    Biblioteca(string n) {
        setNome(n);
    }


    string getNome() {
        return nome;
    }


    void setNome(string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            cout << "Erro: nome da biblioteca não pode ser vazio!" << endl;
        }
    }

    void adicionarLivro(string titulo) {
        if (titulo.empty()) {
            cout << "Erro: título do livro não pode ser vazio!" << endl;
            return;
        }
        for (string l : livros) {
            if (l == titulo) {
                cout << "Livro '" << titulo << "' ja esta cadastrado!" << endl;
                return;
            }
        }
        livros.push_back(titulo);
        cout << "Livro '" << titulo << "' adicionado com sucesso." << endl;
    }

    void listarLivros() {
        if (livros.empty()) {
            cout << "Nenhum livro cadastrado." << endl;
        } else {
            cout << "Livros da biblioteca " << nome << ":" << endl;
            for (string l : livros) {
                cout << "- " << l << endl;
            }
        }
    }
};

int main() {
    
    Biblioteca b("Biblioteca Central");

    
    b.adicionarLivro("O Senhor dos Aneis");
    b.adicionarLivro("Dom Casmurro");
    b.adicionarLivro("1984");

    b.adicionarLivro("1984");

    b.listarLivros();

    b.setNome("Biblioteca Municipal");
    cout << "Novo nome: " << b.getNome() << endl;

    return 0;
}
