#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    // Suma total de la secuencia desde k hasta k + n - 1
    long long total_sum = (n * (2 * k + (n - 1))) / 2;

    // Inicializamos los límites para la búsqueda binaria
    long long low = 0, high = n;
    long long min_diff = LLONG_MAX;
    long long res = 0;

    // Realizamos la búsqueda binaria
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // Suma de los primeros mid elementos
        long long sum_first_part = (mid * (2 * k + (mid - 1))) / 2;

        // Suma de los últimos n - mid elementos
        long long sum_second_part = total_sum - sum_first_part;

        // Calculamos la diferencia absoluta
        long long diff = abs(sum_first_part - sum_second_part);

        // Actualizamos el resultado si encontramos una diferencia menor
        if (diff < min_diff) {
            min_diff = diff;
            res = diff;
        }

        // Ajustamos los límites de la búsqueda binaria
        if (sum_first_part > sum_second_part) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
