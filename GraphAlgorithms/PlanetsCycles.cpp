#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

int src = -1;

void dfs(int node, int depth, vector<int>& d, vector<int>& vis,vector<int>& a){
	if(d[node] != -1){
		if(vis[node] == 0){
			d[node] = depth - d[node];
			src = node;
		}
		vis[node] = 1;
		return;
	}
	
	d[node] = depth;
	dfs(a[node], depth + 1, d, vis, a);
	
	if(src == -1)
		d[node] = d[a[node]] + 1;
	else
		d[node] = d[a[node]];
	vis[node] = 1;
	if(src == node) src = -1;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	vector<int> d(n + 1, -1), vis(n + 1, 0);

	for(int i = 1; i <= n; i++){
		if(d[i] == -1){
			src = -1;
			dfs(i, 0, d, vis, a);
		}
		cout << d[i] << " ";
	}
	
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cerr << "\nOutput:\n- - - - - - - - - - - - -" << endl;
	int TET = 1;
	//cin >> TET;
	for (int i = 1; i <= TET; i++) {
		cerr << "Case #" << i << ": "; 
		solve();
	}
	cerr << endl << "finished in " << (double)(clock()) * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
}
