/* 
  Link : https://codeforces.com/contest/279/problem/B
  Books - Codeforces  [Two Pointers]
  Rating : 1400
*/
#include "bits/stdc++.h"
const int SIZE = 100000;
int v[SIZE + 5];
int n, k, ans;
void Read(){
  std :: cin >> n >> k;
  for(int i = 1; i <= n; i++){
    std :: cin >> v[i];
    v[i] += v[i - 1];
  }
}
void Solve(){
  int i = 1, j = 1;
  while(j <= n and i <= n){
    if(v[j] - v[i - 1] > k){
      i++;
    }else{
      j++;
    }
    ans = std :: max(ans, j - i);
  }
  std :: cout << ans;
}
signed main(){
  std :: ios_base :: sync_with_stdio(false);
  std :: cin.tie(0);
  Read();
  Solve();
  return 0;
}
