#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

bool connected(vector<vector<pair<int, int>>>& g){
	int n = g.size() - 1;
	vector<int> vis(n + 1, 0);
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	int cnt = 1;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto [v, w]: g[node]){
			if(vis[v] == 0){
				vis[v] = 1;
				q.push(v);
				cnt++;
			}
		}
	}

	return n == cnt;
}

int minimumSpaningTree(vector<vector<pair<int, int>>>& g){
	int n = g.size() - 1;
	priority_queue<pair<int, int>> pq;
	pq.push({0, 1});
	vector<int> vis(n + 1, 0);
	
	int weightSum = 0;
	
	while(!pq.empty()){
		auto [W, node] = pq.top();
		pq.pop();
		
		if(vis[node] == 1) continue;
		vis[node] = 1;
		weightSum -= W;

		for(auto [v, w]: g[node]){
			if(vis[v] == 0){
				pq.push({-w, v});
			}
		}
	}
	return weightSum;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
	
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	
	if(!connected(g)){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	cout << minimumSpaningTree(g) << endl;
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
