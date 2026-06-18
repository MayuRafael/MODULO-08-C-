#include <iostream>
#include <string>
using namespace std;

class Aluno {
private:
    string nome;
    float nota;

public:

    Aluno(string n, float nt) {
        nome = n;
        set_nota(nt);
    }

    void set_nota(float nt) {
        if (nt >= 0 && nt <= 10) {
            nota = nt;
        } else {
            cout << "Erro: nota inválida (" << nt << "). Deve estar entre 0 e 10." << endl;
        }
    }

    float get_nota() {
        return nota;
    }

    string get_nome() {
        return nome;
    }
};

int main() {
    
    Aluno a("Carlos", 8.5);
    cout << "Aluno: " << a.get_nome() << " | Nota: " << a.get_nota() << endl;

    
    a.set_nota(12); 

    cout << "Aluno: " << a.get_nome() << " | Nota: " << a.get_nota() << endl;

    return 0;
}
