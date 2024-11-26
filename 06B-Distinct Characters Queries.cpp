#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
    int ans;
    int cnt[26];

    node() {
        ans = 0;
        memset(cnt, 0, sizeof cnt);
    }

    node(char c) {
        ans = 1;
        memset(cnt, 0, sizeof cnt);
        cnt[c-'a'] = 1;
    }

    node(const node &l, const node &r) {
        ans = l.ans + r.ans;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < 26; i++) {
            cnt[i] = l.cnt[i] + r.cnt[i];
        }

        ans = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                ans++;
            }
        }
    }
};

template<class node> class ST {
    vector<node> t;
    int n;

public:
    ST(vector<node> &arr) {
        n = arr.size();
        t.resize(n*2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n-1; i > 0; --i)
            t[i] = node(t[i<<1], t[i<<1|1]);
    }

    void set_point(int p, const node &value) {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p>>1] = node(t[p], t[p^1]);
    }
    node query(int l, int r) {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) ansl = node(ansl, t[l++]);
            if (r&1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();
    vector<node> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = node(s[i]);
    }

    ST<node> st(arr);
    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            // Consulta de tipo 1: actualizar la posición pos con el carácter c
            int pos;
            char c;
            cin >> pos >> c;
            pos--;
            st.set_point(pos, node(c));
        } else if (type == 2) {
            // Consulta de tipo 2: contar los caracteres distintos en el rango [l, r]
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << st.query(l, r + 1).ans << '\n';
        }
    }
    return 0;
}