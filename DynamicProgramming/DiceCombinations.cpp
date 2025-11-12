#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;


void solve() {
	int n;
	cin >> n;

	vector<int> dp(n + 1, 0);
	
	dp[0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 6; j++)
			if(i >= j) dp[i] += dp[i - j];

		dp[i] %= mod;
	}

	cout << dp[n] << endl;
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
