#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void bellmanFord(int src, vector<vector<pair<int, int>>>& g){
	int n = g.size() - 1;
	vector d(n + 1, INF), from(n + 1, -1LL);
	d[src] = 0;
	
	int x = -1;
	for(int k = 1; k <= n; k++){
		x = -1;
		for (int i = 0; i <= n; i++) {
			for (auto [v, w]: g[i]){
				if(d[v] > d[i] + w && d[i] != INF){
					from[v] = i;
					d[v] = d[i] + w;
					x = v;
				}
			}
		}
	}
	
	if(x == -1){
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;

	for(int i = 0; i <= n; i++)
		x = from[x];

	vector<int> cycle = {x};

	int start = x;
	x = from[x];
	while(x != start){
		cycle.push_back(x);
		x = from[x];
	}
	cycle.push_back(x);

	reverse(cycle.begin(), cycle.end());

	for(int i: cycle)
		cout << i << " ";
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1);

	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
	
		g[u].push_back({v, w});
		//g[v].push_back({u, w});
	}
	
	for(int i = 1; i <= n; i++) g[0].push_back({i, 0});

	bellmanFord(0, g);
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
