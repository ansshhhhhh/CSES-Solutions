#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n, x;
	cin >> n >> x;
	
	vector<int> p(n), s(n);

	for(int &i: p) cin >> i;
	for(int &i: s) cin >> i;

	//vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));
	vector<int> curr(x + 1, 0);
	vector<int> prev(x + 1, 0);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= x; j++){
			curr[j] = prev[j];
			if(j >= p[i - 1]) curr[j] = max(curr[j], prev[j - p[i - 1]] + s[i - 1]);
		}
		prev = curr;
	}

	cout << curr[x] << endl;
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
