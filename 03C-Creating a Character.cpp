#include <iostream>
using namespace std;

void solve() {
    long long s, i, exp; cin >> s >> i >> exp;

    long long res;
    // Caso 1: Si str es suficientemente mayor que int + exp, 
    // todos los casos son posibles (de 0 a exp, es decir, exp + 1).
    if (s > i + exp) {
        res = exp + 1;
    } 
    // Caso 2: Si str + exp es aún menor o igual que int, 
    // ningún caso es posible.
    else if (s + exp <= i) {
        res = 0;
    } 
    // Caso 3: Se utiliza la búsqueda binaria 
    // para encontrar el mínimo N donde s + N > i + (exp - N)
    else {
        // Definimos los límites de la búsqueda binaria
        long long low = 0, high = exp;

        // Realizamos la búsqueda binaria
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (s + mid > i + (exp - mid)) {
                res = exp - mid + 1;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }

    cout << res << endl;
}

int main() {
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}