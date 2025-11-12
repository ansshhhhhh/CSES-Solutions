#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;


bool check(int x, int n){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(x & 1){
			if(cnt == 1) return false;
			cnt = 0;
		}else{
			cnt = (cnt + 1) % 2;
		}
		x >>= 1;
	}
	
	return cnt != 1;
}

int f(int n, int m, int last, vector<vector<int>>& dp){
	if(m == 0){
		return last == 0;
	}

	if(dp[m][last] != -1) return dp[m][last];

	int cand = 0; 
	for(int i = 0; i < (1 << n); i++){
		if((i & last) != last || !check(i, n)) continue;
		
		cand = (cand + f(n, m - 1, i - last, dp)) % mod;
	}
	dp[m][last] = cand;
	return dp[m][last];
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector dp(m + 1, vector<int>(1 << n, -1));
	int ans = f(n, m, 0, dp);
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
