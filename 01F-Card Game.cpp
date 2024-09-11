#include <iostream>
using namespace std;

int number_of_wins(int a, int b, int c, int d) {
    int Sunnet_wins = 0;
    
    if (a > c && b > d || a > c && b == d || b > d && a == c) {
        Sunnet_wins += 2;
    } 
    if (a > d && b > c || a > d && b == c || b > c && a == d) {
        Sunnet_wins += 2;
    }
    
    return Sunnet_wins;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a1, a2, a3, a4;
        scanf("%d %d %d %d", &a1, &a2, &a3, &a4);

        int r = number_of_wins(a1, a2, a3, a4);
        cout << r << endl;
    }

    return 0;
}