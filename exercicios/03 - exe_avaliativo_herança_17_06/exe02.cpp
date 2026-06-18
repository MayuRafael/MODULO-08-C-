#include <iostream>
#include <string>
using namespace std;

class Veiculo {
    protected:

    string marca;


    public:
    Veiculo(string m) : marca(m) {}

    void mostrarMarca() {
        cout << "Marca: " << marca << endl;
    }
};


class Carro : public Veiculo {
    private:

    string modelo;

    public:

    Carro(string m, string md) : Veiculo(m), modelo(md) {}

    void mostrarInfo() {
        cout << "Marca: " << marca << " | Modelo: " << modelo << endl;
    }
};

int main() {
    Veiculo v("Honda");
    v.mostrarMarca();

    Carro c("Toyota", "Corolla");
    c.mostrarInfo();

    return 0;
}
