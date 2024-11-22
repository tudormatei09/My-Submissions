/* 
  Link : https://www.infoarena.ro/problema/rangemode
  Range Mode - Infoarena [MO's Algorithm]
  Rating : 5 stars
*/
#include "bits/stdc++.h"
const int SIZE = 100000;
const int Block_Size = 300;
struct Query {
    int left, right, idx;
};
bool Cmp(Query a, Query b) {
    if (a.left / Block_Size != b.left / Block_Size) {
        return a.left / Block_Size < b.left / Block_Size;
    }
    return a.right < b.right;
}
int ans[SIZE + 5];
Query q[SIZE + 5];
int v[SIZE + 5], n, op;
int frecv1[SIZE + 5], frecv2[SIZE + 5], maxx;
void Adauga(int idx) {
    frecv2[frecv1[v[idx]]]--;
    frecv1[v[idx]]++;
    frecv2[frecv1[v[idx]]]++;
    maxx = std :: max(maxx, frecv1[v[idx]]);
}
void Elimina(int idx) {
    frecv2[frecv1[v[idx]]]--;
    if (frecv1[v[idx]] == maxx && frecv2[frecv1[v[idx]]] == 0) {
        maxx--;
    }
    frecv1[v[idx]]--;
    frecv2[frecv1[v[idx]]]++;
}
int Ans() {
    for (int i = 1; i <= SIZE; i++) {
        if (frecv1[i] == maxx) {
            return i;
        }
    }
    return -1;
}
void PrintAns() {
    for (int i = 1; i <= op; i++) {
        std :: cout << ans[i] << '\n';
    }
}
void ProcessQueries() {
    int l = 1, r = 0;
    for (int i = 1; i <= op; i++) {
        while (r < q[i].right) {
            r++;
            Adauga(r);
        }
        while (r > q[i].right) {
            Elimina(r);
            r--;
        }
        while (l < q[i].left) {
            Elimina(l);
            l++;
        }
        while (l > q[i].left) {
            l--;
            Adauga(l);
        }
        ans[q[i].idx] = Ans();
    }
}
void SortQueries() {
    std :: sort(q + 1, q + op + 1, Cmp);
}
void ReadInput() {
    std :: cin >> n >> op;
    for (int i = 1; i <= n; i++) {
        std :: cin >> v[i];
    }
    for (int i = 1; i <= op; i++) {
        std :: cin >> q[i].left >> q[i].right;
        q[i].idx = i;
    }
}
signed main() {
    freopen("rangemode.in", "r", stdin);
    freopen("rangemode.out", "w", stdout);
    std :: ios_base::sync_with_stdio(false);
    std :: cin.tie(0);
    ReadInput();
    SortQueries();
    ProcessQueries();
    PrintAns();

    return 0;
}
