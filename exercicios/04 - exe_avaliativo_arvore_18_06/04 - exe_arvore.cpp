#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
using namespace std;

// ============================================================
//  CLASSE BASE: Personagem
//  Representa qualquer ser da Floresta Encantada.
//  Atributos: nome, poder (usado para organizar a árvore) e tipo.
// ============================================================

class Personagem {
protected:
    string nome;
    int    poder;
    string tipo;

public:
    // Construtor
    Personagem(string nome, int poder, string tipo)
        : nome(nome), poder(poder), tipo(tipo) {}

    // Retorna o nível de poder (usado pela BST para comparações)
    int getPoder() const { return poder; }

    // Exibe as informações do personagem
    // "virtual" permite que subclasses sobrescrevam este método (polimorfismo)
    virtual void exibir() const {
        cout << "  [" << tipo << "] " << nome
             << " | Poder: " << poder << endl;
    }

    
    
};

// ============================================================
//  CLASSE DERIVADA: Chefe
//  Herda de Personagem e adiciona o atributo "reino".
// ============================================================

class Chefe : public Personagem {
private:
    string reino;

public:
    Chefe(string nome, int poder, string tipo, string reino)
        : Personagem(nome, poder, tipo), reino(reino) {}

    // Sobrescreve exibir() para mostrar também o reino
    void exibir() const override {
        cout << "  [" << tipo << " - CHEFE] " << nome
             << " | Poder: " << poder
             << " | Reino: " << reino << endl;
    }
};

// ============================================================
//  NÓ DA ÁRVORE BST
//  Cada nó guarda um ponteiro para um Personagem e dois filhos.
// ============================================================

struct No {
    Personagem* personagem; // ponteiro para o objeto (pode ser Chefe ou Personagem)
    No* esquerda;           // personagens MENOS poderosos
    No* direita;            // personagens MAIS poderosos

    No(Personagem* p) : personagem(p), esquerda(nullptr), direita(nullptr) {}
};

// ============================================================
//  CLASSE: ArvoreFloresta (Árvore Binária de Busca - BST)
//  Organiza os personagens pelo nível de poder:
//    - menor poder → vai para a esquerda
//    - maior poder → vai para a direita
// ============================================================

class ArvoreFloresta {
private:
    No* raiz;

    // Insere recursivamente um novo nó na posição correta
    No* inserir(No* no, Personagem* p) {
        if (no == nullptr) {
            return new No(p); // posição encontrada, cria o nó
        }
        if (p->getPoder() < no->personagem->getPoder()) {
            no->esquerda = inserir(no->esquerda, p); // vai para a esquerda
        } else {
            no->direita = inserir(no->direita, p);   // vai para a direita
        }
        return no;
    }

    // Percorre em ordem (esquerda → raiz → direita)
    // Resultado: do MENOS poderoso ao MAIS poderoso

    void emOrdem(No* no) const {
        if (no == nullptr) return;
        emOrdem(no->esquerda);
        no->personagem->exibir(); // polimorfismo: chama o método correto
        emOrdem(no->direita);
    }

    // Libera memória recursivamente

    void destruir(No* no) {
        if (no == nullptr) return;
        destruir(no->esquerda);
        destruir(no->direita);
        delete no->personagem;
        delete no;
    }

public:
    ArvoreFloresta() : raiz(nullptr) {}

    ~ArvoreFloresta() { destruir(raiz); }

    // Método público para inserir personagem
    void inserir(Personagem* p) {
        raiz = inserir(raiz, p);
    }

    // Método público para exibir todos em ordem de poder
    void exibirEmOrdem() const {
        cout << "\n========================================" << endl;
        cout << "  Personagens da Floresta Encantada" << endl;
        cout << "  (do menos poderoso ao mais poderoso)" << endl;
        cout << "========================================" << endl;
        emOrdem(raiz);
        cout << "========================================\n" << endl;
    }
};

// ============================================================
//  FUNÇÃO PRINCIPAL
// ============================================================

int main() {

     // Configura o console para UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "pt_BR.UTF-8");

    ArvoreFloresta floresta;

    // Adicionando personagens comuns
    floresta.inserir(new Personagem("Lupi",        30, "Animal"));
    floresta.inserir(new Personagem("Mago Merlin", 75, "Mago"));
    floresta.inserir(new Personagem("Fada Iris",   45, "Fada"));
    floresta.inserir(new Personagem("Goblin Zuk",  20, "Animal"));

    // Adicionando Chefes (herdam de Personagem, com atributo reino) 
    floresta.inserir(new Chefe("Chefe Dragão",  90, "Dragão", "Montanhas de Fogo"));
    floresta.inserir(new Chefe("Rainha Selene", 60, "Fada",   "Vale das Estrelas"));

    // Exibindo todos os personagens em ordem de poder ---
    floresta.exibirEmOrdem();

    return 0;
}