/*
  Link : https://codeforces.com/contest/1500/problem/B
  Two chandeliers - Codeforces
  Rating : 2200 (CRT)
*/
#include "bits/stdc++.h"
#define ll long long 
const int LIM = 500000;
ll idx[2 * LIM + 10], vcrt[LIM + 5];
ll n, m, gcd, lcm, k, x, y;

void ext_gcd(ll a, ll b, ll &q, ll &p) {
    ll aux;
    if (b == 0) {
        q = 1;
        p = 0;
    } else {
        ext_gcd(b, a % b, q, p);
        aux = q;
        q = p;
        p = aux - (a / b) * p;
    }
}

ll crt(ll a, ll b) {
    return (((((b - a) / gcd * x) % (n / gcd) + (n / gcd)) % (n / gcd)) * m + a);
}

bool verif(ll lg) {
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        if (vcrt[i] != -1) {
            ans += (lg / lcm + (vcrt[i] < lg % lcm));
        }
    }
    return lg - ans >= k;
}

void Init() {
    gcd = std::gcd(n, m);
    lcm = n / gcd * m;
    ext_gcd(m / gcd, n / gcd, x, y);
    for (int i = 0; i <= 2 * LIM; i++) {
        idx[i] = -1;
    }
}

void Solve() {
    std::cin >> n >> m >> k;
    Init();
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        idx[a] = i;
    }
    if (x < 0) {
        x += n / gcd;
    }
    for (int i = 0; i < m; i++) {
        int b;
        std::cin >> b;
        vcrt[i] = -1; 
        if (idx[b] != -1 && i % gcd == idx[b] % gcd) {
            vcrt[i] = crt(i, idx[b]);
        }
    }
    ll left = 0, right = 1000000000000000000LL;
    while (left < right - 1) { 
        ll mid = (left + right) / 2;
        if (verif(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    std::cout << right;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    Solve();
    return 0;
}
