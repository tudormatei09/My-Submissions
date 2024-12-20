#include "iostream"
#include "cstring"
const int SIZE = 1000000;
char s[SIZE + 5];
int q;
struct Node{
  int matched, open, closed;
  Node combine(const Node& other){
    int new_matches = std :: min(open, other.closed);
    return{
      .matched = matched + other.matched + 2 * new_matches,
      .open = open + other.open - new_matches,
      .closed = closed + other.closed - new_matches,
    };
  }
};
struct AINT{
  Node v[4 * SIZE + 5];
  int n;
  void Init(char* s){
    n = strlen(s);
    Build(1, 1, n, s);
  }
  void Build(int node, int left, int right, char* s){
    if(left == right){
      v[node] = {
        .matched = 0,
        .open = (s[left - 1] == '('),
        .closed = (s[left - 1] == ')'),
      };
      return;
    }
    int mid = (left + right) >> 1;
    Build(2 * node, left, mid, s);
    Build(2 * node + 1, mid + 1, right, s);
    v[node] = v[2 * node].combine(v[2 * node + 1]);
  }
  Node Query(int node, int left, int right, int L, int R){
    if(L > right or R < left){
      return {0, 0, 0};
    }
    if(L <= left and right <= R){
      return v[node];
    }
    int mid = (left + right) >> 1;
    Node ans_l = Query(2 * node, left, mid, L, R);
    Node ans_r = Query(2 * node + 1, mid + 1, right, L, R);
    return ans_l.combine(ans_r);
  }
  int Query(int left, int right){
    return Query(1, 1, n, left, right).matched;
  }
};
AINT aint;
void Solve(){
  std :: cin >> s;
  aint.Init(s);
  std :: cin >> q;
  while(q -- ){
    int left, right;
    std :: cin >> left >> right;
    std :: cout << aint.Query(left, right) << '\n';
  }
}
signed main(){
  std :: ios_base :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  Solve();
  return 0;
}
