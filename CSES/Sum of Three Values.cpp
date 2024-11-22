/*
  Link : https://cses.fi/problemset/task/1641
  Sum of Three Values  - CSES
  Sorting and Searching
*/
#include "bits/stdc++.h"
#define int long long int
const int SIZE = 5000;
int n, k;
struct Element{
  int val, pos;
  bool operator<(Element &a) const {
    return a.val > val;
  }
};
Element v[SIZE + 5];
void Solve(){
  std :: cin >> n >> k;
  for(int i = 1; i <= n; i++){
    std :: cin >> v[i].val;
    v[i].pos = i;
  }
  std :: sort(v + 1, v + n + 1);
  for(int pas = 1; pas <= n; pas++){
    int i = 1, j = n;
    while(i <= j){
      if(v[i].val + v[j].val + v[pas].val == k and j != pas and i != pas and i != j){
        std :: cout << v[i].pos << ' ' << v[j].pos << ' ' << v[pas].pos;
        return;
      }
      if(v[i].val + v[j].val + v[pas].val < k){
        i++;
      }
      if(v[i].val + v[j].val + v[pas].val >= k){
        j--;
      }
    }
  }
  std :: cout << "IMPOSSIBLE";
}
signed main(){
  std :: ios_base :: sync_with_stdio(false);
  std :: cin.tie(0);
  Solve();
  return 0;
}
