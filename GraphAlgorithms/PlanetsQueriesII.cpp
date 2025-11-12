#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void dfs(int node, vector<int>& a, vector<int>& len){
	if(len[node] != -1) return;
	len[node] = 0;

	dfs(a[node], a, len);

	len[node] = 1 + len[a[node]];
}

int kth_ancestor(int x, int k, vector<vector<int>>& ancestor){
	if(k < 0) return -1;
	for(int i = 20; i >= 0; i--){
		if(k & (1 << i)) 
			x = ancestor[i][x];

		if(x == -1) break;
	}
	return x;
}

void solve() {
	int n, q;
	cin >> n >> q;
	int maxN = 21;

	vector<int> a(n + 1), len(n + 1, -1);
	vector<vector<int>> ancestor(maxN, vector<int>(n + 1, -1));

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ancestor[0][i] = a[i];
	}
	for(int i = 1; i <= n; i++){
		if(len[i] == -1){
			dfs(i, a, len);
		}
	}
	cout << endl;
	for(int j = 1; j < maxN; j++)
		for(int i = 1; i <= n; i++)
			ancestor[j][i] = ancestor[j - 1][ancestor[j - 1][i]];
	
	
	stringstream output;
	while(q--){
		int x, y;
		cin >> x >> y;

		int cycle = kth_ancestor(x, len[x], ancestor);

		if(kth_ancestor(x, len[x] - len[y], ancestor) == y){
			output << len[x] - len[y] << endl;
		}else if(kth_ancestor(x, len[x] + len[cycle] - len[y], ancestor) == y){
			output << len[x] + len[cycle] - len[y] << endl;
		}else
			output << -1 << endl;
	}
	cout << output.str();
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
