#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1024000;
int ara[MAX];
int tree[4 * MAX];
int lazy[4 * MAX];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = ara[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        if (lazy[node] == 1) {
            tree[node] = (end - start + 1);
        } else if (lazy[node] == 2) {
            tree[node] = 0;
        } else if (lazy[node] == -1) {
            tree[node] = (end - start + 1) - tree[node];
        }

        if (start != end) {
            if (lazy[node] == -1) {
                lazy[2 * node] = (lazy[2 * node] == 0) ? -1 : (lazy[2 * node] == -1) ? 0 : (lazy[2 * node] == 1) ? 2 : 1;
                lazy[2 * node + 1] = (lazy[2 * node + 1] == 0) ? -1 : (lazy[2 * node + 1] == -1) ? 0 : (lazy[2 * node + 1] == 1) ? 2 : 1;
            } else {
                lazy[2 * node] = lazy[node];
                lazy[2 * node + 1] = lazy[node];
            }
        }
        lazy[node] = 0;
    }
}

void updateRange(int node, int start, int end, int l, int r, int value) {
    propagate(node, start, end);
    if (start > end || start > r || end < l) return;

    if (start >= l && end <= r) {
        lazy[node] = value;
        propagate(node, start, end);
        return;
    }

    int mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, value);
    updateRange(2 * node + 1, mid + 1, end, l, r, value);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int queryRange(int node, int start, int end, int l, int r) {
    propagate(node, start, end);
    if (start > end || start > r || end < l) return 0;

    if (start >= l && end <= r) return tree[node];

    int mid = (start + end) / 2;
    int p1 = queryRange(2 * node, start, mid, l, r);
    int p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

int main() {
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; ++cs) {
        int m;
        cin >> m;
        int COUNT = 0;
        while (m--) {
            int times;
            string s;
            cin >> times >> s;
            while (times--) {
                for (char c : s) {
                    ara[++COUNT] = c - '0';
                }
            }
        }

        memset(lazy, 0, sizeof(lazy));
        build(1, 1, COUNT);

        int q;
        cin >> q;
        cout << "Case " << cs << ":" << endl;
        int qCount = 0;

        while (q--) {
            char cmd;
            int a, b;
            cin >> cmd >> a >> b;
            a++, b++;

            if (cmd == 'F') updateRange(1, 1, COUNT, a, b, 1);
            else if (cmd == 'E') updateRange(1, 1, COUNT, a, b, 2);
            else if (cmd == 'I') updateRange(1, 1, COUNT, a, b, -1);
            else cout << "Q" << ++qCount << ": " << queryRange(1, 1, COUNT, a, b) << endl;
        }
    }
    return 0;
}