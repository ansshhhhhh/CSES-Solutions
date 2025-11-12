#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);

	for(int &i: a) cin >> i;
	for(int &i: b) cin >> i;

	vector dp(n + 1, vector<int>(m + 1, 0));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int n1 = a[i - 1], n2 = b[j - 1];
			dp[i][j] = max({dp[i][j - 1], dp[i - 1][j] , dp[i - 1][j - 1] + (n1 == n2)});
		}
	}

	int i = n, j = m;
	vector<int> ans;
	while(i > 0 && j > 0){
		if(dp[i][j] == dp[i][j - 1])
			j--;
		else if(dp[i][j] == dp[i -1][j])
			i--;
		else{
			ans.push_back(a[i - 1]);
			i--;
			j--;
		}
	}

	reverse(ans.begin(), ans.end());
	cout << dp[n][m] << endl;
	for(int i: ans) cout << i << " ";
	cout << endl;

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
