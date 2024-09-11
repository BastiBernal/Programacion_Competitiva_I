#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    // Tablas de prefijos para contar la frecuencia de caracteres de 'a' y 'b'
    vector<vector<int>> freq_a(n + 1, vector<int>(26, 0));
    vector<vector<int>> freq_b(n + 1, vector<int>(26, 0));

    // Preprocesamiento para las frecuencias acumuladas de 'a' y 'b'
    for (int i = 0; i < n; ++i) {
        // Copiar las frecuencias anteriores
        for (int j = 0; j < 26; ++j) {
            freq_a[i + 1][j] = freq_a[i][j];
            freq_b[i + 1][j] = freq_b[i][j];
        }
        // Aumentar la frecuencia del carácter actual
        freq_a[i + 1][a[i] - 'a']++;
        freq_b[i + 1][b[i] - 'a']++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        // Calcular las diferencias de frecuencias usando las tablas de prefijos
        int dif = 0;
        for (int i = 0; i < 26; ++i) {
            int count_in_a = freq_a[r][i] - freq_a[l - 1][i];
            int count_in_b = freq_b[r][i] - freq_b[l - 1][i];
            if (count_in_a > count_in_b) {
                dif += count_in_a - count_in_b;
            }
        }

        cout << dif << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
