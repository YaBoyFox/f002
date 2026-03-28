#include <iostream>
#include <cmath>
using namespace std;

// Función para convertir fracción a decimal
float convertirFraccion() {
    float numerador, denominador;
    char barra;

    cin >> numerador >> barra >> denominador;

    if (denominador == 0) {
        cout << "Error: denominador no puede ser 0." << endl;
        return 0;
    }

    return numerador / denominador;
}

int main() {
    float numeros[10];
    int cantidad = 2;
    char operacion;
    char opcion;
    char tipo;

    cout << "Calculadora en C++ (con raiz y fracciones)" << endl;

    // Número 1
    cout << "Numero 1 (n = normal, f = fraccion): ";
    cin >> tipo;

    if (tipo == 'f') {
        cout << "Ingresa fraccion (ej: 3/4): ";
        numeros[0] = convertirFraccion();
    } else {
        cout << "Ingresa numero: ";
        cin >> numeros[0];
    }

    // Operación
    cout << "Operacion (+, -, *, /, r = raiz): ";
    cin >> operacion;

    // RAÍZ
    if (operacion == 'r') {
        if (numeros[0] < 0) {
            cout << "Error: no hay raiz de numeros negativos." << endl;
        } else {
            cout << "Resultado: " << sqrt(numeros[0]) << endl;
        }
        return 0;
    }

    // Número 2
    cout << "Numero 2 (n = normal, f = fraccion): ";
    cin >> tipo;

    if (tipo == 'f') {
        cout << "Ingresa fraccion (ej: 3/4): ";
        numeros[1] = convertirFraccion();
    } else {
        cout << "Ingresa numero: ";
        cin >> numeros[1];
    }

    // Más números (hasta 10)
    for (int i = 2; i < 10; i++) {
        cout << "¿Agregar otro numero? (s/n): ";
        cin >> opcion;

        if (opcion == 's' || opcion == 'S') {
            cout << "Numero " << i + 1 << " (n = normal, f = fraccion): ";
            cin >> tipo;

            if (tipo == 'f') {
                cout << "Ingresa fraccion: ";
                numeros[i] = convertirFraccion();
            } else {
                cout << "Ingresa numero: ";
                cin >> numeros[i];
            }

            cantidad++;
        } else {
            break;
        }
    }

    float resultado = numeros[0];

    // Operaciones
    for (int i = 1; i < cantidad; i++) {
        if (operacion == '+') resultado += numeros[i];
        else if (operacion == '-') resultado -= numeros[i];
        else if (operacion == '*') resultado *= numeros[i];
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