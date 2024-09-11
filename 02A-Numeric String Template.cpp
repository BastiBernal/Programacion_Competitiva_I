#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void matches_template(const vector<int>& numbers, const string& s) {
    //Si el tamaño del vector y el string no coinciden, no se pueden cumplir los requerimientos
    if (numbers.size() != s.size()) {
        cout << "NO" << endl;
        return;
    }

    unordered_map<char, int> map_char_int;
    unordered_map<int, char> map_int_char;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        int num = numbers[i];

        // Si ya hay una asignación diferente para el número o el carácter en los mapas, no se cumplen los requisitos
        if ((map_int_char.count(num) && map_int_char[num] != ch) || (map_char_int.count(ch) && map_char_int[ch] != num)) {
            cout << "NO" << endl;
            return;
        }
        
        // Agregar a los mapas si aún no lo están        
        map_int_char[num] = ch;
        map_char_int[ch] = num;
    }

    // Si se han verificado todas las asignaciones sin conflicto, el template coincide
    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            string s; cin >> s;
            matches_template(a, s);
        }
    }
    return 0;
}