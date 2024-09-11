#include <iostream>
#include <stack>
using namespace std;

void regular_bracket_sequence(string s, int n) {
    string res(n, '_');  // Inicializa con '_'
    
    // Rellena los caracteres en las posiciones impares con los paréntesis correctos.
    for (int i = 0; i < n; i++) {
        //Si el índice es par, se reemplaza el '_' con el paréntesis correspondiente
        //Si el anterior es '(', entonces el siguiente es ')', si no, '('
        if (i % 2 == 0) {
            if (i > 0 && res[i - 1] == '(') {
                res[i] = ')';
            } else {
                res[i] = '(';
            }
        } else {
            res[i] = s[i];
        }
    }

    stack<int> st;
    int sum_distances = 0;

    /*
    Se calculan las distancias entre el paréntesis de apertura y de cierre 
    Esto se hace usando una pila para almacenar las posiciones de los paréntesis 
    de apertura (. Cada vez que encontramos un paréntesis de cierre ), sacamos la 
    última posición de apertura de la pila y calculamos la distancia entre esa posición 
    y la posición del paréntesis de cierre. 
    */
    for (int i = 0; i < n; i++) {
        if (res[i] == '(') {
            st.push(i);
        } else if (res[i] == ')' && !st.empty()) {
            int opening_position = st.top();
            st.pop();
            sum_distances += (i - opening_position);
        }
    }

    cout << sum_distances << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        regular_bracket_sequence(s, n);
    }
    return 0;
}