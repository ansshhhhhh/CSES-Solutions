#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

const int mod = 1e9 + 7;
int dp[1001][1001];

void solve() {
	int n;
	cin >> n;

	vector<string> grid(n);
	
	dp[1][1] = 1;

	for(string &i: grid) cin >> i;
	

	if(grid[0][0] == '*' || grid[n - 1][n - 1] == '*'){
		cout << 0 << endl;
		return;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == 0 && j == 0) continue;

			if(grid[i][j] == '.') dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
			else dp[i + 1][j + 1] = 0;
			
			dp[i + 1][j + 1] %= mod;
		}
	}
	
	cout << dp[n][n] << endl;
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
