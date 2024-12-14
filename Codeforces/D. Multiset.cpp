#include "bits/stdc++.h"
const int SIZE = 1000000;
const int LOG = 20;
int aib[SIZE + 5], n;
int lsb(int i){
  return (i & (-i));
}
void Update(int idx, int val){
  for(int i = idx; i <= SIZE; i += lsb(i)){
    aib[i] += val;
  }
}
int Binary_search(int x){
  int sum = 0, pos = 0;
  for(int i = LOG; i >= 0; i--){
    if(pos + (1 << i) <= SIZE and sum + aib[pos + (1 << i)] < x){
      pos += (1 << i);
      sum += aib[pos];
    }
  }
  return pos + 1;
}
void Solve(){
  int n, q;
  std :: cin >> n >> q;
  int maxx = 0;
  for(int i = 1; i <= n; i++){
    int x;
    std :: cin >> x;
    maxx = std :: max(maxx, x);
    Update(x, 1);
  }
  while(q -- ){
    int x;
    std :: cin >> x;
    if(x < 0){
      int idx = Binary_search(std :: abs(x));
      Update(idx, - 1);
    }else{
      Update(x, 1);
      maxx = std :: max(maxx, x);
    }
  }
  for(int i = 1; i <= SIZE; i++){
    if(aib[i] > 0){
      std :: cout << i << ' ';
      return;
    }
  }
  std :: cout << 0;
}
signed main(){
  std :: ios_base :: sync_with_stdio(false);
  std :: cin.tie(0);
  Solve();
  return 0;
}
