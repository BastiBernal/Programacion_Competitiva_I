#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void parity_checker(vector<int>& a) {
    vector<long int> evens, odds;
    for (int num : a) {
        if (num % 2 == 0) {
            evens.push_back(num);
        } else {
            odds.push_back(num);
        }
    }

    if (odds.empty() || evens.empty()) {
        // Todos son pares o todos son impares
        cout << "0" << endl;
        return;
    }

    // Ordenar los números pares para procesarlos de menor a mayor
    sort(evens.begin(), evens.end());

    // El número impar más grande
    long long int s = *max_element(odds.begin(), odds.end());

    bool even_lot_bigger = false;
    for (int i = 0; i < evens.size(); i++) {
        //Si el par es menor que el impar, el impar será la suma de ambos
        if (evens[i] < s) {
            s += evens[i];
        } else {
        //Si no, entonces habría una diferencia muy grande entre el par y el impar, por lo que 
        //el número de casos será el número de números pares + 1, ya que en ese caso el impar más
        //grande se le suma el par más grande, con lo que ahora sería el número más grande del
        //arreglo, luego se convertirían todos los otros pares con este número
            even_lot_bigger = true;
            break;
        }
    }

    int num_operations  = evens.size();
    if (even_lot_bigger == true) {
        num_operations++;
    }

    cout << num_operations << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        parity_checker(a);
    }
    return 0;
}