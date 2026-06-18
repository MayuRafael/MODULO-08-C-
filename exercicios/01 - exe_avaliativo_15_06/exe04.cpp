#include <iostream>
#include <string>
using namespace std;

class Aluno {

    public:

    string nome;
    float nota1;
    float nota2;

    Aluno(string n, float n1, float n2 ) {
        nome = n;
        nota1 = n1;
        nota2 = n2;

    }

    float calcularMedia(){
        return (nota1 + nota2)/2;
    }

    void verificarAprovacao() {
        float media = calcularMedia();
        cout << "Aluno: " << nome << " | Media: " << media << " | ";
        if (media >= 7) {
            cout << "Aprovado " << endl;
        } else {
            cout << "Reprovado" << endl;
        }
    }
};

int main() {
    
    Aluno aluno1("Maria", 8.5, 7.0);
    Aluno aluno2("Joao", 6.0, 5.5);

    // resultado
    aluno1.verificarAprovacao();
    aluno2.verificarAprovacao();

    return 0;


}