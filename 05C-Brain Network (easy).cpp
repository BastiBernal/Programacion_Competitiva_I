#include <iostream>
#include <vector>

using namespace std;

// DFS para recorrer el grafo y marcar los nodos visitados
void DFS(int v, vector<vector<int>>& grafo, vector<bool>& visitado) {
    visitado[v] = true;
    for (int i = 0; i < grafo[v].size(); i++) {
        int vecino = grafo[v][i];
        if (!visitado[vecino]) {
            DFS(vecino, grafo, visitado);
        }
    }
}

// Función para determinar si el grafo es conexo
bool esConexo(int n, vector<vector<int>>& grafo) {
    vector<bool> visitado(n, false);
    DFS(0, grafo, visitado);
    for (int i = 0; i < n; i++) {
        if (!visitado[i]) {
            return false;
        }
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grafo(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a - 1].push_back(b - 1);
        grafo[b - 1].push_back(a - 1);
    }

    // Para que las condiciones se cumplan, el grafo debe ser conexo y tener n - 1 aristas (un árbol)
    if (m == n - 1) {
        if (esConexo(n, grafo)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    } else {
        cout << "no" << endl;
    }
}

int main() {
    solve();
    return 0;
}