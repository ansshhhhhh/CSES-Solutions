#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

struct DSU {
	vector<int> pr, rnk;
	int n;
	DSU(int n) : n(n) {
		pr.resize(n);
		rnk.resize(n, 0);
		for(int i = 0; i < n; i++) pr[i] = i;
	}
	inline int find(int v) {
		return (v == pr[v] ? v : (pr[v] = find(pr[v])));
	}
	inline void join(int v, int u) {
		v = find(v);
		u = find(u);
		if (rnk[v] >= rnk[u]){
			pr[u] = v;
			rnk[v] += rnk[v] == rnk[u];
		} else 
			pr[v] = u;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	
	DSU dsu(n + 1);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		dsu.join(u, v);
	}
	vector<int> parents;
	for(int i = 1; i <= n; i++){
		if(dsu.find(i) == i) parents.push_back(i);
	}
	int nm = parents.size();
	cout << nm - 1 << endl;
	for(int i = 1; i < nm; i++)
		cout << parents[i] << " " << parents[i - 1] << endl;
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
