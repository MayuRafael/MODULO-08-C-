#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int idade;

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "Voce tem " << idade << " anos." << endl;

    double pi = 3.14159265;
    cout << setprecision(pi) << endl;
    cout << fixed << setprecision(2) << pi << endl;

    return 0;
}
