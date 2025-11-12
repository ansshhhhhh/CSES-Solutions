#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n, x;
	cin >> n >> x;

	vector<int> c(n);
	for (int &val : c) cin >> val;
	
	//vector<vector<int>> dp(x + 1, vector<int>(n + 1, INF));
	
	sort(c.begin(), c.end());
	
	//for(int i = 0; i <= n; i++) dp[0][i] = 0;

	vector<int> prev(x + 1, INF), curr(x + 1, 0);
	
	prev[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			curr[j] = prev[j];
			if(j >= c[i - 1]) curr[j] = min(curr[j - c[i - 1]] + 1, curr[j]);
			
		}
		prev = curr;
	}
	
	cout << (curr[x] == INF ? -1 : curr[x]) << endl;
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
