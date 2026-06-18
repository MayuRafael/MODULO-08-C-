#include <iostream>
#include <string>
using namespace std;


class ContaBancaria {
public:
    string titular;
    double saldo;

  
    ContaBancaria(string t, double s) {
        titular = t;
        saldo = s;
    }

    // Métodos
    void depositar(double valor) {
        saldo += valor;
        cout << "Deposito de R$" << valor << " realizado com sucesso." << endl;
    }

    void sacar(double valor) {
        if (valor <= saldo) {
            saldo -= valor;
            cout << "Saque de R$" << valor << " realizado com sucesso." << endl;
        } else {
            cout << "Saldo insuficiente para saque de R$" << valor << "." << endl;
        }
    }


    void mostrarSaldo() {
        cout << "Titular: " << titular << " | Saldo atual: R$" << saldo << endl;
    }
};

int main() {
  
    ContaBancaria conta1("Rafael", 1000.0);

   
    conta1.depositar(500.0);
    conta1.sacar(300.0);

    conta1.mostrarSaldo();

    return 0;
}
