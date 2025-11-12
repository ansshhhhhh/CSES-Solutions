#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n, x;
	cin >> n >> x;

	vector<int> w(n);
	
	for(int &i:w) cin >> i;
	
	int total = 1 << n;
	vector<pair<int, int>> dp(total, {INF, INF});

	dp[0] = {1, 0};

	for(int i = 1; i < total; i++){
		for(int j = 0; j < n; j++)
			if(i & (1 << j)){
				pair<int, int> cand;
				if(dp[i - (1 << j)].second + w[j] <= x)
					cand = {dp[i - (1 << j)].first, dp[i - (1 << j)].second + w[j]};
				else
					cand = {dp[i - (1 << j)].first + 1, w[j]}, dp[i];
				dp[i] = min(dp[i], cand);
			}
	}

	cout << dp[total - 1].first << endl;
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
