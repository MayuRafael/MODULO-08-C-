#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
using namespace std;

class Produto {
protected:
    string nome;
    double preco;

public:
    Produto(string n, double p) : nome(n), preco(p) {}

    // Método virtual para permitir sobrescrita

    virtual void mostrarInfo() {
        cout << "Produto: " << nome << " = Preço: R$" << preco << endl;
    }

};

// classe Livro

class Livro : public Produto {
private:
    string autor;

public:
    Livro(string n, double p, string a) : Produto(n, p), autor(a) {}

    void mostrarInfo() override {
        cout << "Livro: " << nome << "  Autor: " << autor 
             << "  Preço: R$" << preco << endl;
    }
};

// classe Eletrônicos

class Eletronico : public Produto {
private:
    string marca;

public:
    Eletronico(string n, double p, string m) : Produto(n, p), marca(m) {}

    void mostrarInfo() override {
        cout << "Eletrônico: " << nome << "  Marca: " << marca 
             << "  Preço: R$" << preco << endl;
    }
};

int main() {
    // Configura o console para UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Configura a localização para português
    setlocale(LC_ALL, "pt_BR.UTF-8");

    Livro l1("O Senhor dos Anéis", 59.90, "J.R.R. Tolkien");
    Livro l2("Dom Casmurro", 39.90, "Machado de Assis");

    Eletronico e1("Smartphone", 1999.00, "Samsung");
    Eletronico e2("Notebook", 3500.00, "Dell");

    l1.mostrarInfo();
    l2.mostrarInfo();
    e1.mostrarInfo();
    e2.mostrarInfo();

    return 0;
}