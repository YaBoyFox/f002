#include <iostream>
using namespace std;

int main() {
    float numeros[10];
    int cantidad = 2;
    char operacion;
    char opcion;

    cout << "Calculadora (2 a 10 numeros)" << endl;

    // Pedir los primeros 2 números (obligatorios)
    cout << "Ingresa el numero 1: ";
    cin >> numeros[0];

    cout << "Ingresa la operacion (+, -, *, /): ";
    cin >> operacion;

    cout << "Ingresa el numero 2: ";
    cin >> numeros[1];

    // Permitir hasta 8 números más
    for (int i = 2; i < 10; i++) {
        cout << "¿Quieres agregar otro numero? (s/n): ";
        cin >> opcion;

        if (opcion == 's' || opcion == 'S') {
            cout << "Ingresa el numero " << i + 1 << ": ";
            cin >> numeros[i];
            cantidad++;
        } else {
            break;
        }
    }

    float resultado = numeros[0];

    // Realizar la operación
    for (int i = 1; i < cantidad; i++) {
        if (operacion == '+') {
            resultado += numeros[i];
        }
        else if (operacion == '-') {
            resultado -= numeros[i];
        }
        else if (operacion == '*') {
            resultado *= numeros[i];
        }
        else if (operacion == '/') {
            if (numeros[i] == 0) {
                cout << "Error: division entre cero." << endl;
                return 0;
            }
            resultado /= numeros[i];
        }
        else {
            cout << "Operacion no valida." << endl;
            return 0;
        }
    }

    cout << "Resultado: " << resultado << endl;

    return 0;
}