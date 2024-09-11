#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Función para calcular la cantidad de elementos únicos en la unión de los intervalos
long long sumElements(const vector<int>& a, long long N) {
    vector<pair<long long, long long>> intervals;

    // Para cada a[i], registramos el intervalo [a[i], a[i] + N]
    for (int i = 0; i < a.size(); ++i) {
        intervals.push_back({a[i], a[i] + N});
    }

    // Ordenamos los intervalos por su inicio
    sort(intervals.begin(), intervals.end());

    // Fusionamos los intervalos y calculamos el tamaño de la unión
    long long total = 0;
    long long current_start = intervals[0].first;
    long long current_end = intervals[0].second;

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first > current_end) {
            // No se intersectan, añadimos el intervalo actual
            total += (current_end - current_start + 1);
            current_start = intervals[i].first;
            current_end = intervals[i].second;
        } else {
            // Se intersectan, extendemos el final del intervalo actual
            current_end = max(current_end, intervals[i].second);
        }
    }

    // Añadir el último intervalo
    total += (current_end - current_start + 1);

    return total;
}

void solve() {
    int n;
    long long h; 
    cin >> n >> h;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Definimos los límites de la búsqueda binaria
    long long low = 0, high = h;
    long long result = high;

    // Realizamos la búsqueda binaria
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (sumElements(a, mid) >= h) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}