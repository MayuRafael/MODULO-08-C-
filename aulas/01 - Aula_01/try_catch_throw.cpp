#include <iostream>
using namespace std;

int main()
{
    int n, aux=3, temp, ult=1, penult=0;

    cout << "Exibir quantos termos: ";
    cin >> n;

    cout << penult << endl << ult << endl;

    while(aux<=n){
        cout << (ult+penult) << endl;

        temp = penult;
        penult = ult;
        ult = ult + temp;

        aux++;
    }

    return 0;
}