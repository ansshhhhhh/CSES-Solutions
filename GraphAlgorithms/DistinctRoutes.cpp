#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

const int N = 500;
int d[N + 1][N + 1];
int flow[N + 1][N + 1] = {0};

void solve() {
	int n, m;
	cin >> n >> m;
	
	memset(d, -1, sizeof(d));

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;
		d[v][u] = max(d[v][u], 0LL);
	}

	int ans = 0;
	int c = 1;
	while(c){
		vector<int> from(n + 1, -1);
		vector<int> p = {1};
		queue<pair<int, vector<int>>> q;
		q.push({1, p});
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
		int sz = p.size();
		for(int i = 1; i < sz; i++){
			int u = p[i - 1];
			int v = p[i];
			d[u][v]--;
			d[v][u]++;
			flow[u][v]++;
			flow[v][u]--;
		}
		ans++;
	}
	cout << ans << endl;
	for(int i = 0; i < ans; i++){
		vector<int> from(n + 1, -1);
		vector<int> p = {1};
		queue<pair<int, vector<int>>> q;
		q.push({1, p});
		while(!q.empty()){
			auto [node, path] = q.front();
			q.pop();

			if(node == n){
				p = path;
				break;
			}
			for(int i = 1; i <= n; i++){
				if(flow[node][i] && i != from[node] && from[i] == -1){
					from[i] = node;
					path.push_back(i);
					q.push({i, path});
					path.pop_back();
				}
			}
		}
		int sz = p.size();
		cout << sz << endl;
		cout << p[0] << " ";
		for(int i = 1; i < sz; i++){
			int u = p[i - 1];
			int v = p[i];
			cout << v << " ";
			flow[u][v] = 0;
		}
		cout << endl;
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
