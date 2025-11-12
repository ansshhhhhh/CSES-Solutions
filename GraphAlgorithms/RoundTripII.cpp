#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

int noder = -1;

void dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& g, vector<int>& round){
	if(noder != -1) return;

	for(int v: g[node]){
		if(noder != -1) break;

		if(pathVis[v] == 1){
			round.push_back(v);
			noder = v;
			break;
		}

		if(vis[v] == 0){
			vis[v] = 1;
			pathVis[v] = 1;
			dfs(v, vis, pathVis, g, round);
			pathVis[v] = 0;
		}
	}
	if(noder > -1) round.push_back(node);
	if(noder == node){
		noder = -2;
		return;
	}
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
	vector vis(n + 1, 0LL), pathVis(n + 1, 0LL);
	vector<int> round;
	for(int i = 1; i <= n; i++){
	
		if(vis[i] == 0){ 
			vis[i] = 1;
			pathVis[i] = 1;
			dfs(i, vis, pathVis, g, round);
			pathVis[i] = 0;
		}
		if(noder != -1) break;
	}
	if(noder == -1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	cout << round.size() << endl;
	reverse(round.begin(), round.end());
	for(int i: round)
		cout << i << " ";
}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cerr << "- - - - - - - - - - - - -\nOutput:" << endl;
	int TET = 1;
	//cin >> TET;
	for (int i = 1; i <= TET; i++) {
		cerr << "Case #" << i << ": "; 
		solve();
	}
	cerr << endl << "finished in " << (double)(clock()) * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
}
