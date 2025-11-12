#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n + 1);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector from(n + 1, -1);
	queue<int> q;
	from[1] = -2;
	q.push(1);

	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(int v: g[node]){
			if(from[v] == -1){
				from[v] = node;
				q.push(v);
			}
		}
	}

	if(from[n] == -1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	vector<int> path = {n};
	int idx = n; 
	while(from[idx] != -2){
		path.push_back(from[idx]);
		idx = from[idx];
	}

	reverse(path.begin(), path.end());

	cout << path.size() << endl;
	for(int i: path)
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
