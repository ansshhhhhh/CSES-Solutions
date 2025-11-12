#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;

	vector<int> c(n);
	for (int &val : c) cin >> val;
	
	vector<int> preSum(n + 1, 0);
	
	preSum[1] = c[0];

	for(int i = 1; i < n; i++)
		preSum[i + 1] = preSum[i] + c[i];
	
	set<pair<int, int>> st;
	for(int i = a; i < b; i++)
		st.insert({preSum[i], i});
	
	int ans = -INF;
	for(int i = 0; i < n - a + 1; i++){
		if(i < n - b + 1) st.insert({preSum[i + b], i + b});

		int mx = (*st.rbegin()).first;

		ans = max(ans, mx - preSum[i]);

		st.erase({preSum[i + a], i + a});
	}
	
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
