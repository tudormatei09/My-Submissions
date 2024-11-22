/*
  Link : https://codeforces.com/contest/12/problem/D
  Ball - Codeforces [Fenwick Tree]
  Rating : 2400
*/
#include "bits/stdc++.h"
#define int long long int
const int SIZE = 500000;
struct Lady{
    int x, y, z;
};
Lady v[SIZE + 5];
int aux[SIZE + 5], aib[SIZE + 5];
int n;
bool Cmp(Lady a, Lady b){
    return a.z > b.z;
}
void UpdatePoint(int idx, int val){
    idx = n - idx + 1;
    while(idx <= n){
        aib[idx] = std :: max(aib[idx], val);
        idx += idx & (-idx);
    }
}
void UpdateRange(int l, int r){
    for(int i = l; i <= r; i++){
           UpdatePoint(v[i].x, v[i].y);
    }
}
int Query(int idx){
    int ans = 0;
    idx = n - idx + 1;
    while(idx >= 1){
        ans = std :: max(ans, aib[idx]);
        idx = idx & (idx - 1);
    }
    return ans;
}
void Normalize(){
    std :: unordered_map < int, int > m;
    std :: sort(aux + 1, aux + n + 1);
    int cnt = 1;
    m[aux[1]] = cnt++;
    for(int i = 2; i <= n; i++){
        if(aux[i] != aux[i - 1])
            m[aux[i]] = cnt++;
    }
    for(int i = 1; i <= n; i++){
        v[i].x = m[v[i].x];
    }
}
void Read(){
    std :: cin >> n;
    for(int i = 1; i <= n; i++){
        std :: cin >> v[i].x;
        aux[i] = v[i].x;
    }
    for(int i = 1; i <= n; i++){
        std :: cin >> v[i].y;
    }
    for(int i = 1; i <= n; i++){
        std :: cin >> v[i].z;
    }
}
void DescendingZ(){
    std :: sort(v + 1, v + n + 1, Cmp);
}
void Solve(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int  j = i;
        while(j <= n and v[i].z == v[j].z){
            if(Query(v[j].x + 1) > v[j].y)
                cnt++;
            j++;
        }
        UpdateRange(i, j - 1);
        i = j - 1;
    }
    std :: cout << cnt;
}
signed main(){
    std :: ios_base :: sync_with_stdio(false);
    std :: cin.tie(0);
    Read();
    Normalize();
    DescendingZ();
    Solve();
    return 0;
}
