/*
  Link: https://codeforces.com/contest/292/problem/E
  Copying Data - Codeforces [Segment Tree]
  Rating : 1400
  
*/
#include "bits/stdc++.h"
#define int long long int
const int SIZE = 1000001;
int a[SIZE + 5], b[SIZE + 5], n, q;
/**
struct fast_input {
  static const int BUF_SIZE = 16384;
  char buf[BUF_SIZE + 1];
  int pos = BUF_SIZE;

  char get_char() {
    if (pos == BUF_SIZE) {
      int read = fread(buf, 1, BUF_SIZE, stdin);
      buf[read] = '\0';
      pos = 0;
    }
    return buf[pos++];
  }

  int read_int() {
    int result = 0;
    char c;
    do {
      c = get_char();
    } while (!isdigit(c));

    do {
      result = 10 * result + c - '0';
      c = get_char();
    } while (isdigit(c));

    return result;
  }
};
*/
struct Modify{
    int time, dist;
};
Modify aint[4 * SIZE + 5];
Modify Query(int idx) {
    Modify ans = {0, 0};
    idx += n;
    while(idx > 1){
        if(aint[idx].time > ans.time){
            ans = aint[idx];
        }
        idx = idx / 2;
    }
    return ans;
}
void Update(int L, int R, Modify x) {
    L = L + n;
    R = R + n;
    while (L <= R) {
        if (L % 2 == 1) {
            aint[L++] = x;
        }
        if (R % 2 == 0) {
            aint[R--] = x;
        }
        L = L / 2;
        R = R / 2;
    }
}
void Read() {
    std :: cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std :: cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std :: cin >> b[i];
    }
}
void ProcessQ1(int i){
     int x, y, k;
     std :: cin >> x >> y >> k;
     Modify p = {i, x - y};
     Update(y, y + k - 1, p);
}
void ProcessQ2(){
     int x;
     std :: cin >> x;
     Modify p = Query(x);
     if (p.time == 0) {
        std :: cout << b[x] << '\n';
     } else {
        std :: cout << a[x + p.dist] << '\n';
      }
}
void ProcessQueries() {
    for (int i = 1; i <= q; i++) {
        int op;
        std :: cin >> op;
        if (op == 1) {
            ProcessQ1(i);
        }
        if (op == 2) {
            ProcessQ2();
        }
    }
}
signed main() {
    std :: ios_base :: sync_with_stdio(false);
    std :: cin.tie(0);
    Read();
    ProcessQueries();
    return 0;
}
