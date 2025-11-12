#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

void dfs(int node, vector<int>& vis, vector<vector<pair<int, int>>>& g, vector<int>& ans){

	while(!g[node].empty()){
		auto [v, i] = g[node].back();
		g[node].pop_back();
		if(vis[i] == 0){
			vis[i] = 1;
			dfs(v, vis, g, ans);
		}
	}
	ans.push_back(node);
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1);
	vector<int> indegree(n + 1, 0), outdegree(n + 1, 0);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		indegree[v]++;
		outdegree[u]++;
		g[u].push_back({v, i});
		//g[v].push_back(u);
	}
	int go = -1, gi = -1;
	bool var = 0;
	for(int i = 1; i <= n; i++){
		int diff = outdegree[i] - indegree[i];
		if(abs(diff) > 1){
			var = 1;
			break;
		}
		if(!diff) continue;
		if(diff == 1){
			if(go != -1) var = 1;
			go = i;
		}else{
			if(gi != -1) var = 1;
			gi = i;
		}
	}
	if(var || gi != n || go != 1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	//g[gi].push_back({go, m});
	
	vector<int> vis(m + 1, 0);
	vector<int> ans;
	
	dfs(go, vis, g, ans);
	reverse(ans.begin(), ans.end());
	
	if((int)(ans.size()) != m + 1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	//if(gi != -1) ans.pop_back();
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
