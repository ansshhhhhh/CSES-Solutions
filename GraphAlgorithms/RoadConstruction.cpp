#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

struct DSU {
	vector<int> pr, rnk;
	int n;
	DSU(int n) : n(n) {
		pr.resize(n);
		rnk.resize(n, 1);
		for(int i = 0; i < n; i++) pr[i] = i;
	}
	inline int find(int v) {
		return (v == pr[v] ? v : (pr[v] = find(pr[v])));
	}
	inline void join(int v, int u) {
		v = find(v);
		u = find(u);
		
		if(v == u) return;

		if (rnk[v] >= rnk[u]){
			pr[u] = v;
			rnk[v] += rnk[u];
		} else {
			pr[v] = u;
			rnk[u] += rnk[v];
		}
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	DSU dsu(n + 1);

	int cmp = n, mx = 1;
	while(m --> 0){
		int u, v;
		cin >> u >> v;
		
		int p1 = dsu.find(u), p2 = dsu.find(v);
		dsu.join(u, v);
		if(p1 != p2) cmp--;
		mx = max({mx, dsu.rnk[p1], dsu.rnk[p2]});

		cout << cmp << " " << mx << endl;
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
