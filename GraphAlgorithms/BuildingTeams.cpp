#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

vector<int> bipartiteGraph(vector<vector<int>>& g){
	int n = g.size() - 1;
	vector<int> color(n + 1, -1);
	for(int i = 1; i <= n; i++){
		if(color[i] == -1){
			color[i] = 0;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int node = q.front();
				q.pop();

				for(int v: g[node]){
					if(color[v] == -1){
						color[v] = 1 - color[node];
						q.push(v);
					}else if(color[v] == color[node]){
						return {};
					}
				}
			}
		}
	}
	return color;
}


void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
	
		g[u].push_back(v);
		g[v].push_back(u);
	}
	auto ans = bipartiteGraph(g);
	if(ans.empty()){
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	for(int i = 1; i <= n; i++)
		cout << ans[i] + 1 << " ";
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
