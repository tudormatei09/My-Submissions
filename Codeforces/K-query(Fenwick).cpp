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
struct Fenwick{
	int v[2 * SIZE_N + 5], n;
	void Init(int n){
		this -> n = n;
	}
	void Update(int idx, int val){
		for(int i = idx; i <= 2 *  n; i += (i & -i)){
			v[i] += val;
		}
	}
	int Query(int idx){
		int sum = 0;
		for(int i = idx; i > 0; i -= (i & -i)){
			sum += v[i];
		}
		return sum;
	}
};
/*
 Initialization
*/
int n, t, ans[SIZE_Q + 5];
Elem v[SIZE_N + 5];
Queries q[SIZE_Q + 5];
Fenwick aib;
/******************/
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
	aib.Init(n);
	int j = 1;
	for(int i = 1; i <= t; i++){
		while(j <= n and v[j].val > q[i].val){
			aib.Update(v[j].idx, 1);
			j++;
		}
		ans[q[i].idx] = aib.Query(q[i].right) - aib.Query(q[i].left - 1);
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
