#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	string s1, s2;
	cin >> s1 >> s2;

	int n = s1.size(), m = s2.size();

	vector dp(n + 1, vector<int>(m + 1, 0LL));

	for(int i = 0; i <= m; i++) dp[0][i] = i;

	for(int j = 1; j <= n; j++) dp[j][0] = INF;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char c1 = s1[i - 1], c2 = s2[j - 1];
			dp[i][j] = dp[i - 1][j - 1] + (c1 != c2);
			dp[i][j] = min({dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j]});
		}
	}

	cout << dp[n][m] << endl;
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
