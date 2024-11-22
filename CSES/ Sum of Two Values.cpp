/*
  Link : https://cses.fi/problemset/task/1640
  Sum of Two Values - CSES
  Sorting and Searching
*/
#include "bits/stdc++.h"
const int SIZE = 200000;
int n, k;
struct Element{
  int val;
  int pos;
  bool operator<(Element &a) const{
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
  std :: sort(v + 1,  v + n + 1);
  int left = 1, right = n;
  while(left < right){
    //std :: cout << left << ' ' << right << '\n';
    if(v[left].val + v[right].val == k){
      std :: cout << v[left].pos << ' ' << v[right].pos;
      return;
    }
    if(v[left].val + v[right].val < k){
      left++;
    }
    if(v[left].val + v[right].val > k){
      right--;
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
