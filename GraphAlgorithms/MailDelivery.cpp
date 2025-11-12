#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(a) (int)(a.size())
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;
 
int n,m;
vector<int> degree, vis;
vector<vector<pair<int, int>>> g;
vector<int> ans;
 
void dfs(int node){
 
	while(!g[node].empty()){
		auto [v, i] = g[node].back();
		g[node].pop_back();

		if(vis[i] == 0 && degree[node] && degree[v]){
			vis[i] = 1;
			degree[node]--;
			degree[v]--;
			dfs(v);
		}
	}
	ans.push_back(node);
}
 
void solve() {
	cin >> n >> m;
	
	degree.resize(n + 1, 0);
	vis.resize(m, 0);
	g.resize(n + 1);
 
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		
		degree[u]++;
		degree[v]++;
 
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	
	for(int i = 1; i <= n; i++){
		if(degree[i] % 2){
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
	
	dfs(1);
	
	if(sz(ans) != m + 1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}	
	
	reverse(ans.begin(), ans.end());
	for(int i: ans)
		cout << i << " ";
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
