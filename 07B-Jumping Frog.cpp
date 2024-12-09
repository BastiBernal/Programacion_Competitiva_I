#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

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

void solve() {
    string S;
    cin >> S;
    int n = S.length();

    // Vector para almacenar los índices donde hay 'P'
    vector<int> danger;
    for (int i = 1; i < n; i++) {
        if (S[i] == 'P') {
            danger.push_back(i);
        }
    }

    // Si no hay 'P', podemos usar cualquier valor de K
    if (danger.size() == 0) {
        cout << n - 1 << endl;
        return;
    }

    // Calculamos cuántos índices comparten el mismo MCD con cada posible salto
    vector<int> cnt(n, 0);
    for (int i = 1; i < n; i++) {
        int mcd = calcularMCD(i, n);
        cnt[mcd]++;
    }
    int res = 0;

    // Recorremos los posibles saltos
    for (int d = 1; d < n; d++) {
        if (cnt[d] > 0) {
            int ok = 0;

            // Verificamos si hay un salto de longitud d que no tenga 'P'
            for (int j = 0; j < d; j++) {
                if (S[j] == 'R') {
                    int cur = 1;
                    int v = (j + d) % n;
                    while (v != j) {
                        if (S[v] != 'R') {
                            cur = 0;
                            break;
                        }
                        v = (v + d) % n;
                    }
                    if (cur) {
                        ok = 1;
                        break;
                    }
                }
            }

            // Si es válida, sumamos la cantidad de índices que comparten el MCD d
            if (ok) {
                res += cnt[d];
            }
        }
    }

    cout << res << endl;
}

int main() {
    solve();
    return 0;
}
