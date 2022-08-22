//Francisco Rocha
//Iker Guerrero
//Juan Carlos Llanos
//Algoritmo Avaro. Actividad 1.2

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <execution>
using namespace std;

//Funcion para hacer pruebas e imprimir cualquier vector
void imprimirArreglo (vector<int> vector){
    int s=vector.size();
    for (int i = 0; i < s; i++)
    {
        cout<<vector[i]<<endl;
    }
    
}

//División de int regresa int y nos permite saber la máxima cantidad de billetes
//de cierta cantidad
int maxBilletes (int cantidad, int valor){
    return cantidad/valor;
}

//Funcion que toma como argumento el vector ordenado de valor de billetes
//y el precio a pagar. Nos devuelve un vector de respuestas
vector<int> maxCambio (vector<int> valorBilletes, int precio, int pago){
    vector<int> respuestas;
    vector<int> cambiosRestantes; 
    int cambioRestante;
    int cambio=pago-precio;
    

    for (int i = 0; i < valorBilletes.size(); i++)
    {
        if (i==0)
        {
            cambioRestante=cambio;
            cambiosRestantes.push_back(cambioRestante);
            cambiosRestantes.push_back(cambioRestante-((maxBilletes(cambiosRestantes[0],valorBilletes[0]))*valorBilletes[0]));
            respuestas.push_back(maxBilletes(cambiosRestantes[0],valorBilletes[0]));
        } else{
            cambioRestante=cambiosRestantes[i-1]-valorBilletes[i-1]*respuestas[i-1];
            cambiosRestantes.push_back(cambioRestante);
            respuestas.push_back(maxBilletes(cambiosRestantes[i+1],valorBilletes[i]));
        }
        
    }
    
    return respuestas;
}

int main() {

//Tenemos que hacer un arreglo que se ordene de mayor a menor
//las DENOMINACIONES de los billetes disponibles
vector<int> valorBilletes; //DENOMINACIONES
int cantTipos, valor, precio, pago;
cin>>cantTipos;
//En este ciclo for vamos metiendo al vector los valores para
//posteriormente ordenarlos
for (int i = 0; i < cantTipos; i++)
{
    cin>>valor;
    valorBilletes.push_back(valor);
}
//Ordenamos con ejecución en paralelo de mayor a menor
sort(execution::par, valorBilletes.begin(),valorBilletes.end(), greater<>());
cin>>precio; //El precio que cuesta el producto
cin>>pago; // Billete o moneda con el que se paga dicho producto

//Imprimimos arreglo final de respuestas llamando a la función maxCambio
//que nos regresa un vector con las respuestas finales
imprimirArreglo(maxCambio(valorBilletes,precio,pago));

return 0;
}
