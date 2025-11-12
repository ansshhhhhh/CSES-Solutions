#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vector d(n + 1, vector<int>(n + 1, INF));

	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		d[u][v] = min(d[u][v], w);
		d[v][u] = min(d[v][u], w);
	}
	
	for(int i = 1; i <= n; i++) d[i][i] = 0;

	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	
	while(q--){
		int u, v;
		cin >> u >> v;
		cout << (d[u][v] < INF ? d[u][v] : -1) << endl;
	}
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
