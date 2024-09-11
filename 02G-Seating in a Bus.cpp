#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void followed_recommendations(vector<int> a) {
	unordered_set<int> seats_occuped {a[0]};
	for (int i = 1; i < a.size() - 1; i++) {
		/*Si no se encuentra el i + 1 o i - 1 o si ya se ocupó el
		asiento, entonces no se siguieron las condiciones */
		if (seats_occuped.find(a[i] - 1) == seats_occuped.end() && 
		seats_occuped.find(a[i] + 1) == seats_occuped.end() || 
		seats_occuped.find(a[i]) != seats_occuped.end()) {
			cout << "NO" << endl;
			return;
		} else {
		    seats_occuped.insert(a[i]);
		}
	}
	/*Si se recorrió todo el array y no se encontró problema, se
	siguieron las condiciones */
	cout << "YES" << endl;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a;
		for (int i = 0; i < n; i++) {
			int p; cin >> p;
			a.push_back(p);
		}
		followed_recommendations(a);
	}
	return 0;
}