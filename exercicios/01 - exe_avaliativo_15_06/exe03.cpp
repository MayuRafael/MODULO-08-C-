#include <iostream>
#include <string>
using namespace std;

class Cachorro {
public:

    string nome;
    string raca;

    Cachorro(string n, string r){
        nome = n;
        raca = r;
    }

    void latir() {
        cout << " Uau uau! O cachorro " << nome << " Esta latindo. " << endl;
    }
};

int main() {
    Cachorro meuCachorro("Bob", "Caramelo");
    meuCachorro.latir();

    return 0;
}