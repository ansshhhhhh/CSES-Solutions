#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

vector<int> topologicalSort(vector<vector<int>>& g){
	int n = g.size() - 1;
	vector<int> srt, inDegree(n + 1, 0);

	for(int u = 1; u <= n; u++)
		for(int v: g[u])
			inDegree[v]++;

	queue<int> q;

	for(int i = 1; i <= n; i++) if(inDegree[i] == 0) q.push(i);

	while(!q.empty()){
		int node = q.front(); q.pop();
		
		srt.push_back(node);

		for(int v: g[node])
			if(!--inDegree[v]) q.push(v);
	}

	if((int)srt.size() == n) return srt;
	return {};
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
	
	auto ans = topologicalSort(g);
	if(ans.empty()){
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	for(int i : ans)
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
