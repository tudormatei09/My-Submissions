/*
  Link: https://codeforces.com/contest/1478/problem/E
  Nezzar and Binary String - Codeforces
  Rating : 1900
*/
#include "bits/stdc++.h"
const int SIZE = 200000;

struct Node {
    int sum;
    int lazy;
};

struct Query {
    int x, y;
};

Query w[SIZE + 5];
Node aint[4 * SIZE + 5];
int n, q, t;
std::vector<bool> a, b;

void Push(int node, int left, int right) {
    if (aint[node].lazy != -1) {
        aint[node].sum = aint[node].lazy * (right - left + 1);
        if (left != right) {
            aint[2 * node].lazy = aint[node].lazy;
            aint[2 * node + 1].lazy = aint[node].lazy;
        }
        aint[node].lazy = -1;
    }
}

void Build(int node, int left, int right) {
    if (left == right) {
        aint[node].sum = b[left - 1];
        aint[node].lazy = -1;
        return;
    }
    int mid = (left + right) / 2;
    Build(2 * node, left, mid);
    Build(2 * node + 1, mid + 1, right);
    aint[node].sum = aint[2 * node].sum + aint[2 * node + 1].sum;
    aint[node].lazy = -1;
}

void Update(int node, int left, int right, int L, int R, int val) {
    Push(node, left, right);
    if (R < left || right < L) return;
    if (L <= left && right <= R) {
        aint[node].lazy = val;
        aint[node].sum = val * (right - left + 1);
        return;
    }
    int mid = (left + right) / 2;
    Update(2 * node, left, mid, L, R, val);
    Update(2 * node + 1, mid + 1, right, L, R, val);
    aint[node].sum = aint[2 * node].sum + aint[2 * node + 1].sum;
}

int Query(int node, int left, int right, int L, int R) {
    Push(node, left, right);
    if (R < left || right < L) return 0;
    if (L <= left && right <= R) return aint[node].sum;
    int mid = (left + right) / 2;
    return Query(2 * node, left, mid, L, R) + Query(2 * node + 1, mid + 1, right, L, R);
}

bool Check() {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void Read() {
    std::cin >> q;
}

void ReadQ() {
    std::cin >> n >> t;
    std::string s, f;
    std::cin >> s >> f;

    a.assign(n, 0);
    b.assign(n, 0);

    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        b[i] = f[i] - '0';
    }

    for (int i = 1; i <= t; i++) {
        std::cin >> w[i].x >> w[i].y;
    }
}

void ProcessQueries() {
    while (q--) {
        ReadQ();
        Build(1, 1, n);
        bool ans = true;
        for (int i = t; i >= 1; --i) {
            int l = w[i].x, r = w[i].y;
            int segmentSum = Query(1, 1, n, l, r);
            int len = r - l + 1;
            if (segmentSum * 2 == len) {
                ans = false;
                break;
            }
            int newVal = (segmentSum * 2 > len) ? 1 : 0;
            Update(1, 1, n, l, r, newVal);
        }
        if (ans) {
            for (int i = 1; i <= n; i++) {
                b[i - 1] = Query(1, 1, n, i, i);
            }
            if (Check()) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        } else {
            std::cout << "NO\n";
        }
    }
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    Read();
    ProcessQueries();
    return 0;
}
