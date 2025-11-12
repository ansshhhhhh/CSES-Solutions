#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

int f(int i, int j, vector<int>& a, vector<vector<int>>& dp){
	if(dp[i][j] != -1){
		return dp[i][j];
	}

	if(i == j){
		dp[i][j] = a[i];
		return dp[i][j];
	}

	dp[i][j] = max(a[j] - f(i, j - 1, a, dp), a[i] - f(i + 1, j, a, dp));

	return dp[i][j];
}

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int &i: a) cin >> i;

	vector dp(n, vector<int>(n, -1));
	
	int diff = f(0, n - 1, a, dp);
	
	int ans = (accumulate(a.begin(), a.end(), 0LL) - diff) / 2 + diff;

	
	cout << ans << endl;
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
