#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int a, b;
	cin >> a >> b;

	vector dp(a + 1, vector<int>(b + 1, 0));

	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			int lim = min(i, j);
			int cnt = i * j;
			dp[i][j] = i * j;
			for(int k = 0; k <= lim; k++){
				cnt = min({cnt, dp[i - k][j] + dp[k][j - k] + 1, dp[i][j - k] + dp[i - k][k] + 1});
			}
			dp[i][j] = cnt;
			//cout << cnt <<" ";
		}
		//cout << endl;
	}

	cout << dp[a][b] - 1<< endl;
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
