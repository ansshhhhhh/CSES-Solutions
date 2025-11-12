#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n;
	cin >> n;

	vector<int> dp(n + 1, INF);
	
	dp[0] = 0;

	for(int i = 1; i <= n; i++){
		int x = i;
		while(x){
			int bck = x % 10;
			if(bck <= i) dp[i] = min(dp[i], dp[i - bck] + 1);
			x /= 10;
		}
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
