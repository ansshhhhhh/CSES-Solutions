#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

int dp[20][11][2][2];

int func(string& s, int idx, int prev, bool tight, bool lz){
	if(idx == (int)(s.size())) return 1;

	if(dp[idx][prev][tight][lz] != -1) return dp[idx][prev][tight][lz];

	int st = 0;
	int end = tight ? (s[idx] - '0') : 9;
	
	int res = 0;
	for(int i = st; i <= end; i++){
		if(i == prev && !lz) continue;

		res += func(s, idx + 1, i, tight && i == (s[idx] - '0'), lz && i == 0);
	}

	return dp[idx][prev][tight][lz] = res;
}


int f(int x){
	memset(dp, -1, sizeof(dp));
	cout << sizeof(dp) << endl;
	cout << 20 * 11 * 2 * 2 * 8<< endl;
	auto s1 = to_string(x);
	return func(s1, 0, 10, 1, 1);
}

void solve() {
	int a, b;
	cin >> a >> b;
	int ans = f(b) - f(a - 1);

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
