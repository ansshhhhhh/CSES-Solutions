#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

const int N = 1 << 20;
int n, m;
int dp[21][N + 1];
int ans = 0;

int f(int node, vector<vector<int>>& g, int vis){
	if(dp[node][vis] != -1) return dp[node][vis];
	
	if(node == n && vis > (1LL << (n - 1))){
		return dp[node][vis] = 0;
	}

	vis ^= (1 << (node - 1));
	int cnt = 0;
	for(int i : g[node]){
		if(vis & (1LL << (i - 1))){
			cnt = (f(i, g, vis) + cnt) % mod;
		}
	}
	vis ^= (1LL << (node - 1));
	return dp[node][vis] = cnt;
}

void solve() {
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
	
		g[u].push_back(v);
		//g[v].push_back(u);
	}
	
	dp[n][(1 << (n - 1))] = 1;

	int ans = f(1, g, (1 << n) - 1);
	cout << ans << endl;
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
