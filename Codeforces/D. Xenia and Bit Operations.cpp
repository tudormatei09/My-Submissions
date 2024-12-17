#include "bits/stdc++.h"
const int SIZE = 132000;
int aint[4 * SIZE + 5], n, q, nrelem;
void Update(int node, int left, int right, int idx, int val, int lvl){
  if(left == right){
    aint[node] = val;
    return;
  }
  int mid = (left + right) >> 1;
  if(idx <= mid){
    Update(2 * node, left, mid, idx, val, lvl - 1);
  }else{
    Update(2 * node + 1, mid + 1, right, idx, val, lvl - 1);
  }
  if(lvl % 2 == 0){
    aint[node] = aint[2 * node] ^ aint[2 * node + 1];
  }else{
    aint[node] = aint[2 * node] | aint[2 * node + 1];
  }
}
void Update(int idx, int val){
  Update(1, 1, nrelem, idx, val, n);
}
void Solve(){
  std :: cin >> n >> q;
  nrelem = (1 << n);
  for(int i = 1; i <= nrelem; i++){
    int x;
    std :: cin >> x;
    Update(i, x);
  }
  while(q -- ){
    int x, y;
    std :: cin >> x >> y;
    Update(x, y);
    std :: cout << aint[1] << '\n';
  }
}
signed main(){
  std :: ios_base :: sync_with_stdio(false);
  std :: cin.tie(0);
  Solve();
  return 0;
}
