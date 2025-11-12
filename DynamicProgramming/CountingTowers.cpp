#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

const int mod = 1e9 + 7;
const int N = 1e6; 

int dp[N + 1][8] = {0};

void solve() {
	int n;
	cin >> n;
	int ans = dp[n][0] + dp[n][2];

	ans %= mod;
	cout << ans << endl;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cerr << "- - - - - - - - - - - - -\nOutput:" << endl;
	int TET = 1;
	cin >> TET;
	
	dp[0][0] = 1;
	dp[0][3] = 1;
	

	for(int i = 1; i <= N; i++){
		for(int j = 0; j < 8; j++){
			if(j == 2 || j == 7 || j == 5 || j == 1 || j == 4)
				dp[i][j] = dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][4] + dp[i - 1][1];
			else
				dp[i][j] = dp[i - 1][6] + dp[i - 1][2] + dp[i - 1][0];
			dp[i][j] %= mod;
		}
	}

	for (int i = 1; i <= TET; i++) {
		cerr << "Case #" << i << ": "; 
		solve();
	}
	cerr << endl << "finished in " << (double)(clock()) * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
}
