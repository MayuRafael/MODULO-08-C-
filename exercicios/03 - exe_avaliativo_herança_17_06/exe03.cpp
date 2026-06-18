#include <iostream>
#include <string>
using namespace std;

class Funcionario {
protected:
    string nome;
    double salario;

public:
    Funcionario(string n, double s) : nome(n), salario(s) {}

    virtual void mostrarSalario() {
        cout << "Funcionario " << nome << " recebe R$" << salario << endl;
    }

};

class Gerente : public Funcionario {
public:
    Gerente(string n, double s) : Funcionario(n, s) {}

    void mostrarSalario() override {
        double salarioComBonus = salario * 1.2;
        cout << "Gerente " << nome << " recebe R$" << salarioComBonus 
             << " (inclui bonus de 20%)" << endl;
    }
};

int main() {
    Funcionario f("Carlos", 3000.0);
    Gerente g("Ana", 5000.0);

    f.mostrarSalario(); // usa versão da classe base
    g.mostrarSalario(); // usa versão sobrescrita

    return 0;
}
