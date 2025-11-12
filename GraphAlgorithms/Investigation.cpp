#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

void dijkstra(int src, vector<vector<pair<int, int>>>& g){
	int n = g.size() - 1;
	vector d(n + 1, INF), cnt(n + 1, 0LL), mn(n + 1, INF), mx(n + 1, -INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({0, src});
	
	d[src] = 0;
	cnt[src] = 1;
	
	mn[1] = 0;
	mx[1] = 0;

	while(!pq.empty()){
		auto [dist, node] = pq.top();
		pq.pop();

		if(dist > d[node]) continue;

		for(auto [v, w]: g[node]){
			int cand = dist + w;

			if(cand < d[v]){
				mn[v] = mn[node] + 1;
				mx[v] = mx[node] + 1;
				d[v] = cand;
				cnt[v] = cnt[node];
				pq.push({cand, v});
			}else if(cand == d[v]){
				cnt[v] = (cnt[v] + cnt[node]) % mod;
				mn[v] = min(mn[node] + 1, mn[v]);
				mx[v] = max(mx[node] + 1, mx[v]);
			}
		}
	}
	
	cout << d[n] << " " << cnt[n] << " " << mn[n] << " " << mx[n] << endl;

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
	dijkstra(1, g);
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
