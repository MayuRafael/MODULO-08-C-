#include <iostream>
#include <string>
using namespace std;


class Animal {
public:
    string especie;
    string som;

  
    Animal(string e, string s) {
        especie = e;
        som = s;
    }

    // Método 
    void emitir_som() {
        cout << "O " << especie << " faz: " << som << endl;
    }
};

int main() {
    //  objeto
    Animal animal1("Cachorro", "Au Au!");
    Animal animal2("Gato", "Miau!");

   
    animal1.emitir_som();
    animal2.emitir_som();

    return 0;
}
