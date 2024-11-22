/*
  Link: https://www.nerdarena.ro/problema/burlane
  Burlane - Nerdarena [Smenul lui Batog]
  Sursă:	selecție lot Nerdvana 2024
*/
#include "bits/stdc++.h"
const int MAXX = 101000;
struct Burlan {
    int nxt, jump, dest;
} v[MAXX + 5];
int n, q, blocksz;
void Get_input() {
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i].dest;
    }
}
void Update_interv(int idx, int start) {
    int stop = start + blocksz;
    if(idx == 0){
        idx = 1;
    }
    for (int i = idx; i < stop; i++) {
        int it = v[i].dest;
        if (it < start) {
            v[i].jump = 1;
            v[i].nxt = it;
        } else {
            v[i].jump = v[it].jump + 1;
            v[i].nxt = v[it].nxt;
        }
    }
}
void Update(int idx, int val) {
    v[idx].dest = val;
    int start = idx / blocksz * blocksz;
    Update_interv(start, start);
}
void Query(int idx) {
    int cnt = 0;
    while (idx != 0) {
        cnt += v[idx].jump;
        idx = v[idx].nxt;
    }
    std::cout << cnt << '\n';
}
void Init() {
    n++;
    blocksz = std::sqrt(n);
    int nblocks = (n - 1) / blocksz + 1;
    for (int i = 0; i < nblocks; i++) {
        int start = i * blocksz;
        Update_interv(start, start);
    }
}
void Solve() {
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int idx;
            std::cin >> idx;
            Query(idx);
        } else if (op == 2) {
            int idx, newd;
            std::cin >> idx >> newd;
            Update(idx, newd);
        }
    }
}
signed main() {
    freopen("burlane.in", "r", stdin);
    freopen("burlane.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    Get_input();
    Init();
    Solve();
    return 0;
}
