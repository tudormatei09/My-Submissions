#include "bits/stdc++.h"
const int SIZE = 1000000;
int v[SIZE + 5], last[SIZE + 5], n, q;
struct Queries{
  int left, right, org, ans;
};
Queries p[SIZE + 5];
struct Fenwick{
  int tree[SIZE + 5], n;
  void Init(int n){
    this -> n = n;
    std :: fill(tree, tree + n + 1, 0);
  }
  void Update(int idx, int val){
    for(int i = idx; i <= n; i += (i & -i)){
      tree[i] += val;
    }
  }
  int Query(int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= (i & -i)){
      sum += tree[i];
    }
    return sum;
  }
};
Fenwick aib;
void Sort_by_right(){
  std :: sort(p + 1, p + q + 1, [](Queries &a , Queries &b){
    return a.right < b.right;
  });
}
void Update_Position(int pos){
  if(last[v[pos]]){
    aib.Update(last[v[pos]], -1);
  }
    last[v[pos]] = pos;
    aib.Update(pos, +1);
}
int Update_here(int right, int q_idx){
  while(q_idx <= q and p[q_idx].right == right){
    p[q_idx].ans = aib.Query(p[q_idx].right) - aib.Query(p[q_idx].left - 1);
    q_idx++;
  }
  return q_idx;
}
void ProcessQueries(){
  aib.Init(n);
  int idx = 1;
  for(int i = 1; i <= n; i++){
    Update_Position(i);
    idx = Update_here(i, idx);
  }
}
void Prepare_Answer(){
  std :: sort(p + 1, p + q + 1, [](Queries &a, Queries &b){
    return a.org < b.org;
  });
}
void Print(){
  for(int i = 1; i <= q; i++){
    std :: cout << p[i].ans << '\n';
  }
}
void Read(){
  std :: cin >> n;
  for(int i = 1; i <= n; i++){
    std :: cin >> v[i];
  }
  std :: cin >> q;
  for(int i = 1; i <= q; i++){
    std :: cin >> p[i].left >> p[i].right;
    p[i].org = i;
  }
}
signed main(){
  std :: ios_base :: sync_with_stdio(false);
  std :: cin.tie(0);
  Read();
  Sort_by_right();
  ProcessQueries();
  Prepare_Answer();
  Print();
  return 0;
}
