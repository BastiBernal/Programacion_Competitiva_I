#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para calcular el arreglo LCP
vector<int> computeLCP(const vector<string>& phone_numbers) {
    int n = phone_numbers.size();
    vector<int> lcp(n, 0);
    for (int i = 1; i < n; i++) {
        int len = min(phone_numbers[i].size(), phone_numbers[i-1].size());
        for (int j = 0; j < len; j++) {
            if (phone_numbers[i][j] != phone_numbers[i-1][j]) {
                break;
            }
            lcp[i]++;
        }
    }
    return lcp;
}

void solve() {
    int n; cin >> n;
    vector<string> phone_numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> phone_numbers[i];
    }

    // Se ordenan los números alfabéticamente
    sort(phone_numbers.begin(), phone_numbers.end());

    // Calcular el arreglo LCP
    vector<int> lcp = computeLCP(phone_numbers);
    bool consistent = true;

    // Checar si hay un número que es prefijo de otro
    for (int i = 1; i < n; i++) {
        if (lcp[i] == phone_numbers[i-1].size()) {
            consistent = false;
            break;
        }
    }

    if (consistent) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}