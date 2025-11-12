#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

int f(int node, vector<vector<int>>& g, vector<int>& d, vector<int>& to){
	if(d[node] != -1) return d[node];

	int n = d.size() - 1;

	if(node == n) return d[node] = 1;
	if(g[node].empty()) return d[node] = -INF;
	
	int mx = -INF;

	for(int v: g[node]){
		if(d[v] == -2) continue;
		int cand = f(v, g, d, to) + 1;
		if(cand > mx){
			mx = cand;
			to[node] = v;
		}
	}
	
	return d[node] = mx;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
	
		g[u].push_back(v);
		//g[v].push_back(u);
	}

	vector<int> d(n + 1, -1), to(n + 1, -1);
	
	f(1, g, d, to);

	if(d[1] <= -1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	cout << d[1] << endl;
	
	int id = 1;
	while(id != n){
		cout << id << " ";
		id = to[id];
	}
	cout << id << endl;
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
