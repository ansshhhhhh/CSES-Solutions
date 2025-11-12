#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void dijkstra(int src, int k, vector<vector<pair<int, int>>>& g){
	int n = g.size() - 1;
	vector vis(n + 1, 0LL);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({0, src});

	while(!pq.empty()){
		auto [dist, node] = pq.top();
		pq.pop();

		if(vis[node] == k) continue;
		vis[node]++;
		
		if(node == n){
			cout << dist << " ";
		}
		for(auto [v, w]: g[node]){

			if(vis[v] < k)
				pq.push({dist + w, v});
		}
	}
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> g(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
	
		g[u].push_back({v, w});
		//g[v].push_back({u, w});
	}
	dijkstra(1, k, g);		
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
