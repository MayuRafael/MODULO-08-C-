#include <iostream>
#include <string>
using namespace std;

class Produto {
private:
    string nome;
    double preco;

public:
   
    Produto(string n, double p) {
       this-> nome = n;
       this -> preco = p; 
    }

    
    void setPreco(double p) {
        if (p > 0) {
            preco = p;
        } else {
            cout << "Erro: preco invalido (" << p << "). Deve ser maior que zero." << endl;
        }
    }

   
    double getPreco() {
        return preco;
    }

   
    string getNome() {
        return nome;
    }

    
    void mostrarDados() {
        cout << "Produto: " << nome << " | Preco: R$" << preco << endl;
    }
};

int main() {
   
    Produto p1("Notebook", 3500.0);
    Produto p2("Celular", -1500.0); 

  
    p1.mostrarDados();
    p2.mostrarDados();

    // Tentando alterar preço para inválido
    p1.setPreco(0);

    // Alterando para válido
    p1.setPreco(2800.0);
    p1.mostrarDados();

    return 0;
}
