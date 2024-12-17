#include "bits/stdc++.h"

const int SIZE = 100000;
int aint[4 * SIZE + 5];
int Convert(char c){
  return int(c) - 'a';
}
void Update(int node, int left, int right, int idx, int old_val, int new_val){
  if(left == right){
    aint[node] &= ~(1 << old_val);
    aint[node] |= (1 << (new_val));
    return;
  }
  int mid = (left + right) >> 1;
  if(idx <= mid){
    Update(2 * node, left, mid, idx, old_val, new_val);
  }else{
    Update(2 * node + 1, mid + 1, right, idx, old_val, new_val);
  }
  aint[node] = aint[2 * node] | aint[2 * node + 1];
}
int Query(int node, int left, int right, int L, int R){
  if(right < L or left > R){
    return 0;
  }
  if(left >= L and right <= R){
    return aint[node];
  }
  int mid = (left + right) >> 1;
  int ans_L = Query(2 * node, left, mid, L, R);
  int ans_R = Query(2 * node + 1, mid + 1, right, L, R);
  return (ans_L | ans_R);
}
void Solve(){
  std :: string s;
  std :: cin >> s;
  int n = s.length();
  for(int i = 0; i < n; i++){
    Update(1, 1, n, i + 1, 0, Convert(s[i]));
  }
  int q;
  std :: cin >> q;
  while(q -- ){
    int op;
    std :: cin >> op;
    if(op == 1){
      int idx;
      char c;
      std :: cin >> idx >> c;
      Update(1, 1, n, idx, Convert(s[idx - 1]), Convert(c));
      s[idx - 1] = c;
    }else{
      int left, right;
      std :: cin >> left >> right;
      std :: cout << __builtin_popcount(Query(1, 1, n, left, right)) << '\n';
    }
  }
}
signed main(){
  std :: ios_base :: sync_with_stdio(false);
  std :: cin.tie(0);
  Solve();
  return 0;
}
