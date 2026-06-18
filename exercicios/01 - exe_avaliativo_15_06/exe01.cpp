#include <iostream>
#include <string>
using namespace std;

// ============================================================
// Aula 15/0/2026
// PROFESSORA: ÉRIKA
// AULUNO: RAFAEL DA SILVA
// ============================================================


//  CLASSE: Caneta


class Caneta {

public:
    string cor;
    string marca;
    bool tampada;
 
    // MÉTODOS

    void tampar() {
        tampada = true;
        cout << "Caneta tampada.\n";
    }
 
    void destampar() {
        tampada = false;
        cout << "Caneta destampada.\n";
    }
 
    void escrever() {
        if (tampada) {
            cout << "Destampe a caneta primeiro!\n";
        } else {
            cout << "Escrevendo com a caneta " << cor << "...\n";
        }
    }
 
    void exibirInfo() {
        cout << "Marca: " << marca << " | Cor: " << cor
             << " | Tampada: " << (tampada ? "sim" : "nao") << "\n";
    }
};
 
int main() {
    Caneta c1;
    c1.cor     = "azul";
    c1.marca   = "BIC";
    c1.tampada = true;
 
    c1.exibirInfo();
    // c1.escrever();   
    c1.destampar();
    c1.escrever();   // ok
    c1.exibirInfo();
 
    return 0;
}