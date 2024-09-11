#include <iostream>
#include <cstring>

using namespace std;

string strong_password(string s) {
    string aux = s;
    aux.resize(s.length() + 1);

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            if (s[i] != 'a') {
                aux[i] = 'a';
            } else {
                aux[i] = 'b';
            }
            for (int j = i + 1; j <= s.length(); j++) {
                aux[j] = s[j - 1];
            }
            return aux;
        }
    }

    if (aux[s.length() - 1] == 'a') {
        aux.back() = 'b';
    } else {
        aux.back() = 'a';
    }
    return aux;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        string res = strong_password(s);

        cout << res << endl;
    }
    return 0;
}