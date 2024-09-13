#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Ordenamos el array para hacer búsqueda binaria
    sort(a.begin(), a.end());

    ll count = 0;

    for (int i = 0; i < n; i++) {
        int low = l - a[i];
        int high = r - a[i];

        // Usuamos búqueda binaria para encontrar l <= a[i] + a[j] y a[i] + a[j] <= r
        auto left = lower_bound(a.begin() + i + 1, a.end(), low);
        auto right = upper_bound(a.begin() + i + 1, a.end(), high);

        // Restamos los resultados para encontrar el rango de j válido
        count += (right - left);
    }

    cout << count << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}