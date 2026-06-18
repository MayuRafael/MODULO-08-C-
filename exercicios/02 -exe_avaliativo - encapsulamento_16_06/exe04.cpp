#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Restaurante {
private:
    string nome;
    vector<string> cardapio;

public:
    Restaurante(string n) { setNome(n); }

    string getNome() { return nome; }

    void setNome(string novo_nome) {
        if (!novo_nome.empty()) nome = novo_nome;
        else cout << "Erro: nome não pode ser vazio!" << endl;
    }

    void adicionarPrato(string prato) {
        for (string p : cardapio) {
            if (p == prato) {
                cout << "Prato '" << prato << "' já existe!" << endl;
                return;
            }
        }
        cardapio.push_back(prato);
    }

    void listarCardapio() {
        cout << "Cardápio de " << nome << ":" << endl;
        for (string p : cardapio) cout << "- " << p << endl;
    }

    void atenderCliente(string cliente, string prato) {
        for (string p : cardapio) {
            if (p == prato) {
                cout << "Cliente " << cliente << " pediu '" << prato << "'. Pedido confirmado!" << endl;
                return;
            }
        }
        cout << "Cliente " << cliente << " pediu '" << prato << "', mas não existe no cardápio." << endl;
    }
};

int main() {
    Restaurante r("Sabor Caseiro");

    r.adicionarPrato("Feijoada");
    r.adicionarPrato("Lasanha");
    r.adicionarPrato("Frango Assado");

    r.listarCardapio();

    r.atenderCliente("Maria", "Feijoada"); // válido
    r.atenderCliente("João", "Pizza");     // inválido

    r.setNome("Sabor da Vovó");
    cout << "Novo nome: " << r.getNome() << endl;

    return 0;
}
