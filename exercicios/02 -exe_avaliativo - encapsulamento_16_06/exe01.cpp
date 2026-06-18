#include <iostream>
#include <string>
using namespace std;

class contaBancaria {
    private:
     string titular;
     double saldo;


public:

    contaBancaria(string t, double s) : titular(t), saldo(s) {}

    string getTitular()const { return titular; }
    double getSaldo() const { return saldo; }

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << " Deposito de R$" << valor << " realizado" << endl;
        } else {
            cout << " Valor invalido para deposito" << endl;
        }
    }

    bool sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << " saque de R$" << valor << "realizado. " << endl;
            return true;
        } else {
            cout << "saldo insufuciente ou valor invalido" << endl;
            return false;
        }
    }
     
}; 

int main() {

     contaBancaria conta("joao", 1000.00);

    cout << " titular: " << conta.getTitular() << endl;
    cout << " Saldo: R$" << conta.getSaldo() << endl;

    conta.depositar(500.0);
    conta.sacar(200.0);
    conta.sacar(2000.0);

    cout << " Saldo final: R$" << conta.getSaldo() << endl;

    }
    