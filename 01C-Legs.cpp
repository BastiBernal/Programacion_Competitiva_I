#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int res = 0;

    for (int i = 0; i < t; i++) {
        int n, aux;
        cin >> n;
        aux = n;
        
        while (aux > 0) {
            if (aux - 4 >= 0) {
                aux -= 4;
                res += 1;
            } else if (aux - 2 >= 0) {
                aux -= 2;
                res += 1;
            }
        }

        cout << res << endl;
        res = 0;
    }
    return 0;
}