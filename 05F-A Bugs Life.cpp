#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using graph = vector<vector<int>>;

bool es_bipartita(graph& g, int u, vector<int>& color, int c = 1) {
    color[u] = c;
    for (int v : g[u]) {
        if (color[v] == c)
            return false;
        if (color[v] == 0 && !es_bipartita(g,v,color,3-c))
            return false;
    }
    return true;
}

void solve() {
    int v, e;
    cin >> v >> e;
    graph g(v);
    for (int j = 0; j < e; j++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    
    vector<int> color(g.size(), 0);
    for (int u = 0; u < g.size(); u++) {
        if (color[u] == 0 && !es_bipartita(g, u, color)) {
            cout << "Suspicious bugs found!" << endl;
            return;
        }
    }
    cout << "No suspicious bugs found!" << endl;
}

int main() {
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        cout << "Scenario #" << i + 1 << ":" << endl;
        solve();
    }
}