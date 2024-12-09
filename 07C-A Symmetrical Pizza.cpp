#include <stdio.h>
#include <iostream>

using namespace std;

// Función para calcular el máximo común divisor (MCD) usando el algoritmo de Euclides
int calcularMCD(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

// Función para calcular el mínimo común múltiplo (MCM)
int calcularMCM(int a, int b) {
    return (a / calcularMCD(a, b)) * b;
}

void solve() {
    float R;
    cin >> R;
    int n = R * 100;
    cout << calcularMCM(n, 36000) / n << endl;
}

int main() {
    solve();
    return 0;
}