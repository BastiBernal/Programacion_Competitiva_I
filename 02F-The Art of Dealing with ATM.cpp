#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> denominations(n);
    for (int i = 0; i < n; i++) {
        cin >> denominations[i];
    }
    
    map<int, int> min_bills_map;
    
    // Generar todas las sumas posibles con hasta k billetes y almacenar el número mínimo de billetes para cada suma
    for (int i = 0; i < n; i++) {
        int denomination = denominations[i];
        for (int j = 1; j <= k; j++) {
            int sum = denomination * j;
            if (min_bills_map.find(sum) == min_bills_map.end()) {
                min_bills_map[sum] = j;
            } else {
                min_bills_map[sum] = min(min_bills_map[sum], j);
            }
        }
    }
    
    vector<pair<int, int>> filtered_sums(min_bills_map.begin(), min_bills_map.end());
    
    int q;
    cin >> q;
    
    while (q--) {
        int x;
        cin >> x;
        
        int min_bills = k + 1;

        // Intenta encontrar la suma usando un tipo de billete
        if (min_bills_map.find(x) != min_bills_map.end()) {
            min_bills = min(min_bills, min_bills_map[x]);
        }
        
        int left = 0, right = filtered_sums.size() - 1;
        
        // Utilice la técnica de dos punteros para ver si podemos dividir la suma en dos denominaciones.
        while (left <= right) {
            int sum = filtered_sums[left].first + filtered_sums[right].first;
            int bills_used = filtered_sums[left].second + filtered_sums[right].second;
            
            if (sum == x) {
                if (bills_used <= k) {
                    min_bills = min(min_bills, bills_used);
                }
                left++;
                right--;
            } else if (sum < x) {
                left++;
            } else {
                right--;
            }
        }
        
        if (min_bills == k + 1) {
            cout << -1 << endl;
        } else {
            cout << min_bills << endl;
        }
    }
    
    return 0;
}
