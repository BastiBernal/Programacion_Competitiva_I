#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void max_score(vector<int>& a, string& s) {
    // Encuentra la posición de la primera aparición de L y de la última de R
    size_t first_L = s.find('L');
    size_t last_R = s.find_last_of('R');

    if (first_L > last_R) {
        cout << "0" << endl;
        return;
    }
    // Calcula las sumas acumuladas
    vector<long long int> sum(a.size() + 1, 0);
    for (size_t i = 1; i <= a.size(); i++) {
        sum[i] = sum[i - 1] + a[i - 1];
    } 

    long long int res = 0;
    stack<int> r;
    queue<int> l;

    //Se guardan los index de las r y l
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'R') {
            r.push(i);
        } else if (s[i] == 'L') {
            l.push(i);
        }
    }

    //Número de casos máximos
    int len = min(r.size(), l.size());

    //Usando la lógica LIFO y FIFO, se comparan los indexes de las
    //R y L y si el index de R es menor que el de L, se suman el resultado
    //de la resta de los indexes en las sumas acumuladas, si no se imprime 
    //el resultado y se retorna
    for (int i = 0; i < len; i++) {
        int r_index = r.top(); r.pop();
        int l_index = l.front(); l.pop();
        if (r_index < l_index){
            cout << res << endl;
            return;
        }
        res += sum[r_index + 1] - sum[l_index];
    }
    cout << res << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        string s; cin >> s;
        max_score(a, s);
    }
    return 0;
}