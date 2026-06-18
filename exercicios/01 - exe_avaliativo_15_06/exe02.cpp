#include <iostream>
#include <string>
using namespace std;


class Pessoa {
public:
    string nome;
    int idade;

    Pessoa(string n, int i) {
        nome = n;
        idade = i;
    }

    
    void mostrarDados() {
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }
};

int main() {
    
    Pessoa pessoa1("Ana", 25);
    Pessoa pessoa2("Carlos", 30);

    pessoa1.mostrarDados();
    pessoa2.mostrarDados();

    return 0;
}
