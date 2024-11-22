/*
  Link : https://cses.fi/problemset/task/1660
  Subarray Sums 1 - CSES
  Sorting and Searching
*/
#include "bits/stdc++.h"
const int SIZE = 200000;
int n, k, ans, v[SIZE + 5];
void Solve(){
  std :: cin >> n >> k;
  for(int i = 1; i <= n; i++){
    std :: cin >> v[i];
    v[i] += v[i - 1];
  }
  int i = 1, j = 1;
  while(i <= n and j <= n){
    if(v[j] - v[i - 1] == k){
      ans++;
    }
    if(v[j]- v[i - 1] >= k){
      i++;
    }
    if(v[j] - v[i - 1] < k){
      j++;
    }
  }
  std :: cout << ans;
}
signed main(){
  std :: ios_base :: sync_with_stdio(false);
  std :: cin.tie(0);
  Solve();
  return 0;
}
