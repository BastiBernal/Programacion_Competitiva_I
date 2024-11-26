#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Movimientos posibles del rey
const int kingMoves[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
// Movimientos posibles de un caballo
const int knightMoves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

// Verificar si una posición está dentro del tablero
bool isValid(int x, int y, int m, int n) {
    return x >= 0 && y >= 0 && x < m && y < n;
}

void solve(int m, int n, vector<string>& grid) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<bool>> unsafe(m, vector<bool>(n, false));
    pair<int, int> start, end;

    // Identificar posiciones iniciales y calcular casillas inseguras
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
            if (grid[i][j] == 'Z') {
                for (auto move : knightMoves) {
                    int nx = i + move[0];
                    int ny = j + move[1];
                    if (isValid(nx, ny, m, n) && grid[nx][ny] != 'A' && grid[nx][ny] != 'B') {
                        unsafe[nx][ny] = true;
                    }
                }
            }
        }
    }

    // BFS
    q.push(start);
    visited[start.first][start.second] = true;
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front();
            q.pop();

            if (x == end.first && y == end.second) {
                cout << "Minimal possible length of a trip is " << steps << '\n';
                return;
            }

            for (auto move : kingMoves) {
                int nx = x + move[0];
                int ny = y + move[1];
                if (isValid(nx, ny, m, n) && !visited[nx][ny] && grid[nx][ny] != 'Z' && !unsafe[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        ++steps;
    }
    cout << "King Peter, you can't go now!\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<string> grid(m);
        for (int i = 0; i < m; ++i) {
            cin >> grid[i];
        }

        solve(m, n, grid);
    }

    return 0;
}