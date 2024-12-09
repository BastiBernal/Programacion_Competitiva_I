#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(1000001, 0);

    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;

        // Procesar las potencias de 2
        while (t < a.size() && a[t]) {
            a[t++] = 0; // Desactiva la posición actual
        }
        if (t < a.size()) {
            a[t] = 1; // Activa la posición actual
        }
    }

    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i]) count++;
    }

    // Si hay 2 potencias de 2, o si hay 1 potencia de 2 y N != 1
    // entonces se pueden dividir los caramelos
    if (count == 2 || (count == 1 && N != 1)) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
}

int main() {
    solve();
    return 0;
}
