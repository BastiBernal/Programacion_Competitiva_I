#include <iostream>
using namespace std;

int number_of_moves(int a, int b) {
    int dif = a - b;
    if (dif < 0) {
        dif *= -1;
    }
    
    int moves = (dif + 9) / 10;
    return moves;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        int res = number_of_moves(a, b);

        cout << res << endl;
    }

    return 0;
}