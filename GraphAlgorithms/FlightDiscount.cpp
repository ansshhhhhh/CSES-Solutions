#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

vector<int> dijkstra(int src, vector<vector<pair<int, int>>>& g){
	int n = g.size() - 1;
	vector d(n + 1, INF), vis(n + 1, 0LL);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({0, src});
	d[src] = 0;

	while(!pq.empty()){
		auto [dist, node] = pq.top();
		pq.pop();

		if(vis[node] == 1) continue;
		vis[node] = 1;

		for(auto [v, w]: g[node]){
			d[v] = min(d[v], d[node] + w);

			if(vis[v] == 0)
				pq.push({d[v], v});
		}
	}

	return d;
}


void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1), rg(n + 1);

	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		
		g[u].push_back({v, w});
		rg[v].push_back({u, w});
	}
	
	auto d1 = dijkstra(1, g);
	auto d2 = dijkstra(n, rg);

	int ans = INF;
	for(int u = 1; u <= n; u++){
		for(auto [v, w]: g[u]){
			ans = min(ans, d1[u] + d2[v] + w / 2);
		}
	}
	cout << ans << endl;
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
