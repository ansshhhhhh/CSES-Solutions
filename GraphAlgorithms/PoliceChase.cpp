#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;
const int N = 500;
 
int d[N + 1][N + 1];
bool isEdge[N + 1][N + 1];

void solve() {
	int n, m;
	cin >> n >> m;
	memset(d, -1, sizeof(d));
 
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;
		d[v][u] = d[u][v];
		isEdge[u][v] = 1;
		isEdge[v][u] = 1;
	}	
	vector<pair<int, int>> edges;
	int ans = 0;
	int c = 1;
	while(c){
		vector<int> from(n + 1, -1);
		vector<int> p = {1};
		queue<pair<int, vector<int>>> q;
		q.push({1, {p}});
		while(!q.empty()){
			auto [node, path] = q.front();
			q.pop();
			
			if(node == n){
				p = path;
				break;
			}
			for(int i = 1; i <= n; i++){
				if(d[node][i] >= c && i != from[node] && from[i] == -1){
					from[i] = node;
					path.push_back(i);
					q.push({i, path});
					path.pop_back();
				}
			}
		}
		if(from[n] == -1){
			c /= 2;
			continue;
		}
		int mn = INF;
		int sz = p.size();
		for(int i = 1; i < sz; i++){
			int u = p[i - 1];
			int v = p[i];
			mn = min(mn, d[u][v]);
		}
		for(int i = 1; i < sz; i++){
			int u = p[i - 1];
			int v = p[i];
			d[u][v] -= mn;
			d[v][u] += mn;
		}
		ans += mn;
	}
	cout << ans << endl;
	vector<int> canReach(n + 1, 0);
	canReach[1] = 1;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(int i = 1; i <= n; i++){
			if(d[node][i] > 0 && canReach[i] == 0){
				canReach[i] = 1;
				q.push(i);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		if(canReach[i]){
			for(int j = 1; j <= n; j++){
				if(!canReach[j] && isEdge[i][j]){
					edges.push_back({i, j});
				}
			}
		}
	}
	for(auto [u, v]:edges){
		cout << u << " " << v << endl;
	}
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
