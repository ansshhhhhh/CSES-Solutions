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
	vector mz(n, vector<char>(m, '.'));

	DSU dsu(n * m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> mz[i][j];
			if(mz[i][j] == '#') continue;

			if(i > 0 && mz[i - 1][j] == '.') dsu.join(i * m + j, (i - 1) * m + j);
			if(j > 0 && mz[i][j - 1] == '.') dsu.join(i * m + j, i * m + j - 1);
		}
	int cnt = 0;
	for(int i = 0; i < n * m; i++)
		if(mz[i / m][i % m] == '.' && dsu.find(i) == i) cnt++;
	cout << cnt << endl;
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
