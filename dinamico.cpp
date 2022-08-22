#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
//Valor que se va usar para calcular dinamicamente el cambio restante
int sumatoria = 0;

vector<int> respuesta;
vector<int> monedas;
int cambio;

void Dynamizar(){
    if (sumatoria < cambio){
        for (int i = 0; i < monedas.size(); i++){
            if (sumatoria + monedas[i] <= cambio)
            {
                sumatoria += monedas[i];
                respuesta[i]++;
                break;
            }
        }
        Dynamizar();
    }
}

int main() {

    int largo = 0;

    cin >> largo;

    

    int temp;
    for (int i = 0; i < largo; i++){
        cin >> temp;
        monedas.push_back(temp);
        respuesta.push_back(0);
    }

    sort(monedas.begin(), monedas.end(), greater<int>());

    int P;
    int Q;
    cin >> P;
    cin >> Q;

    cambio = Q - P;


    //cout << monedas.front();

    Dynamizar();

    for (int i = 0; i < respuesta.size(); i++)
    {
        cout << respuesta[i] << endl;
    }
    

}
