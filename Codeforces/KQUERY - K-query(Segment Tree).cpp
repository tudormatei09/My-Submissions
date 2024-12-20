#include "bits/stdc++.h"
#define int long long 
const int SIZE_N = 40000;
const int SIZE_Q = 200000;
struct Elem{
	int val, idx;
};
struct Queries{
	int left, right, val, idx;
};
/*
 Initialization
*/
int n, t, ans[SIZE_Q + 5];
Elem v[SIZE_N + 5];
Queries q[SIZE_Q + 5];
int aint[4 * SIZE_N + 5];
/******************/
void Update(int node, int left, int right, int idx, int val){
	if(left == right){
		aint[node] = val;
		return;
	}
	int mid  = (left + right) >> 1;
	if(idx <= mid){
		Update(2 * node,  left, mid, idx, val);
	}else{
		Update(2 * node + 1, mid + 1,  right, idx, val);
	}
	aint[node] = aint[2 * node] + aint[2 * node + 1];
}
int Query(int node, int left, int right, int L, int R){
	if(R < left or L > right){
		return 0;
	}
	if(L <= left and right <= R){
		return aint[node];
	}
	int mid = (left + right) >> 1;
	int ans_L = Query(2 * node, left, mid, L, R);
	int ans_R = Query(2 * node + 1, mid + 1, right, L, R);
	return ans_L + ans_R;
}
void SortV_by_value(){
	std :: sort(v + 1, v + n + 1, [](Elem &a, Elem &b){
		return a.val > b.val;
	});
} 
void SortQ_by_value(){
	std :: sort(q + 1, q + t + 1, [](Queries &a, Queries&b){
		return a.val > b.val;
	});
}
void Read(){
	std :: cin >> n;
	for(int i = 1; i <= n; i++){
		std :: cin >> v[i].val;
		v[i].idx = i;
	}
	std :: cin >> t;
	for(int i = 1; i <= t; i++){
		std :: cin >> q[i].left >> q[i].right >> q[i].val;
		q[i].idx = i;
	}
}
void Process_Queries(){
	int j = 1;
	for(int i = 1; i <= t; i++){
		while(j <= n and v[j].val > q[i].val){
			Update(1, 1, n, v[j].idx, 1);
			j++;
		}
		ans[q[i].idx] = Query(1, 1, n, q[i].left, q[i].right);
	}
}
void Print(){
	for(int i = 1; i <= t; i++){
		std :: cout << ans[i] << '\n';
	}
}
void Debug(){
	std :: cout << "Vector:\n";
	for(int i = 1; i <= n; i++){
		std :: cout << v[i].val << ' ' << v[i].idx << '\n';	
	}
	std :: cout << "Queries:\n";
	for(int i = 1; i <= t; i++){
		std :: cout  << q[i].left << ' ' << q[i].right << ' ' << q[i].val << '\n'; 
 	}
}
signed main(){
	std :: ios_base :: sync_with_stdio(false);
	std :: cin.tie(0);
	Read();
	SortV_by_value();
	SortQ_by_value();
	Process_Queries();
	Print();
	//Debug();
	return 0;
}
