#include <iostream>
#include <string>
#include <locale.h>
#include <stdexcept>
#include <windows.h>

using namespace std;

int main() {

    /*SeteConsoleOutputCP(CP_UTF8);
    SeteConsoleCP(CP_UTF8),
    SeteLocale(LC_ALL, "UTF*");*/

    string usuarioCorreto = "admin";
    string senhaCorreta = "1234";
    string usuario, senha;
    int tentativas = 0;
    bool acesso = false;

   
    try{
        while (tentativas < 3 && !acesso) {
            cout << "Tentativa " << (tentativas + 1) << " de 3" << endl;

            cout << "Digite o login: ";
            cin >> usuario;

            cout << "Digite a senha: "; 
            cin >> senha;

            if (usuario == usuarioCorreto && senha == senhaCorreta) {
                cout << "Login realizado com sucesso!" << endl;
                acesso = true;
            } else {
                cout << "Login ou senha incorretos." << endl;
                tentativas++;
            }
        }

        if (!acesso) {
            cout << "Acesso bloqueado." << endl;

            throw runtime_error("Número máximo de tentativas excedido.");
        }

    } catch (const exception &e) {
                
        cout << "Erro capturado: " << e.what() << endl;
        cout << "Por favor, procure o administrador." << endl;
    }

    return 0;
}
