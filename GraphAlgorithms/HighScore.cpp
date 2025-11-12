#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

vector<int> bellmanFord(int src, vector<vector<pair<int, int>>>& g){
	int n = g.size() - 1;
	vector d(n + 1, INF);
	d[src] = 0;
	set<int> negativeCycle;

	for(int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++) {
			for (auto [v, w]: g[i]){
				if(d[v] > d[i] + w && d[i] != INF){
					if(k == n) negativeCycle.insert(v);
					d[v] = d[i] + w;
				}
			}
		}
	}
	
	// BFS for the reachability from a negative cycle
	queue<int> q;
	for(int node: negativeCycle){
		q.push(node);
		d[node] = -INF;
	}

	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto [v, w]: g[node]){
			if(d[v] != -INF){
				q.push(v);
				d[v] = -INF;
			}
		}
	}

	return d;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		w = - w;
		g[u].push_back({v, w});
		//g[v].push_back({u, w});
	}
	
	auto d = bellmanFord(1, g);

	cout << (d[n] == -INF ? -1 : -d[n]) << endl;
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
