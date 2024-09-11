#include <iostream>
#include <queue>
#include <set>
using namespace std;

void ids_displayed(int n, int k) {
    deque<int> show; // Cola para almacenar los IDs mostrados
    set<int> id_set; // Conjunto para rastrear IDs en la cola

    for (int i = 0; i < n; i++) {
        int id; cin >> id;

        // Si el ID no está en el deque
        if (id_set.find(id) == id_set.end()) {
            if (show.size() == k) {
                int removed_id = show.back();
                show.pop_back(); // Remueve el ID más antiguo
                id_set.erase(removed_id); // Elimina el ID del conjunto
            }
            show.push_front(id); // Agrega el nuevo ID al frente
            id_set.insert(id); // Añade el ID al conjunto
        }
    }

    cout << show.size() << endl;

    for (auto it = show.begin(); it != show.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int n, k; cin >> n >> k;
    ids_displayed(n, k);
    return 0;
}