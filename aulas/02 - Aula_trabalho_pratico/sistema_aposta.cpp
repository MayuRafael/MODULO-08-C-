#include <iostream>
#include <string>
using namespace std;

int main() {
    int totalApostadores;
    cout << "Digite o total de apostadores: ";
    cin >> totalApostadores;

    const int totalJogos = 4;
    char pais1[totalJogos][3], pais2[totalJogos][3]; // países com 3 letras
    int placarReal1[totalJogos], placarReal2[totalJogos];
    string nomes[100];
    int pontos[100] = {0};

    // Entrada dos países e resultados reais
    cout << "Digite os jogos e resultados reais no formato: BRA X ARG = 2 X 3\n";
    for (int j = 0; j < totalJogos; j++) {
        char xChar, igualChar;
        cin >> pais1[j] >> xChar >> pais2[j] >> igualChar >> placarReal1[j] >> xChar >> placarReal2[j];
    }

    // Entrada das apostas
    for (int a = 0; a < totalApostadores; a++) {
        cout << "Digite o nome do apostador " << a+1 << ": ";
        cin >> nomes[a];

        cout << "Apostas de " << nomes[a] << ":\n";
        for (int j = 0; j < totalJogos; j++) {
            cout << pais1[j] << " X " << pais2[j] << " = ";
            int g1, g2;
            char xChar;
            cin >> g1 >> xChar >> g2;

            if (g1 == placarReal1[j] && g2 == placarReal2[j]) {
                pontos[a] += 10;
            } else if ((g1 > g2 && placarReal1[j] > placarReal2[j]) ||
                       (g1 < g2 && placarReal1[j] < placarReal2[j])) {
                pontos[a] += 5;
            } else if (g1 == g2 && placarReal1[j] == placarReal2[j]) {
                pontos[a] += 5;
            }
        }
    }

    // Mostrar pontuação final
    cout << "\nPontuação final:\n";
    for (int a = 0; a < totalApostadores; a++) {
        cout << nomes[a] << ": " << pontos[a] << " pontos\n";
    }

    // Ranking
    for (int i = 0; i < totalApostadores-1; i++) {
        for (int j = i+1; j < totalApostadores; j++) {
            if (pontos[j] > pontos[i]) {
                swap(pontos[i], pontos[j]);
                swap(nomes[i], nomes[j]);
            }
        }
    }

    cout << "\nRanking dos apostadores:\n";
    for (int a = 0; a < totalApostadores; a++) {
        cout << (a+1) << "º lugar: " << nomes[a] << " com " << pontos[a] << " pontos\n";
    }

    return 0;
}
