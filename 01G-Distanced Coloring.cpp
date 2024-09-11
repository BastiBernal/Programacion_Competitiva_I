#include <iostream>
using namespace std;

int min_number_colors(int n, int m, int k) {
    if (k <= n && k <= m) {
        return k * k;
    } else if (k <= n && k > m) {
        return k * m;
    } else if (k <= m && k > n) {
        return k * n;
    } else {
        return m * n;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        scanf("%d %d %d",&n ,&m ,&k);
        
        int res = min_number_colors(n, m, k);
        cout << res << endl;
    }

    return 0;
}