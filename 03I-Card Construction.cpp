#include <iostream>
#include <vector>
using namespace std;

// Pre computar la cantidad de cartas necesarias para las pirámides 
vector<int> pyramids() {
    vector<int> pyramids;
    int h = 1;
    while (true) {
        int cards = (3 * h * (h + 1)) / 2 - h;
        if (cards > 1e9) break;
        pyramids.push_back(cards);
        h++;
    }
    return pyramids;
}

void solve() {
    vector<int> pyramids_array = pyramids();
    int n; cin >> n;
    
    int count = 0;
    // Construye todas las pirámides posibles
    while(n >= 2) {
        // Busca la pirámide más grande que se pueda construir
        auto it = lower_bound(pyramids_array.begin(), pyramids_array.end(), n + 1) - 1;
        n -= *it;
        count++;
    }

    cout << count << endl;
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}