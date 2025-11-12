#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n;
	cin >> n;

	stack<pair<int, int>> st;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		while(!st.empty() && st.top().first >= x) st.pop();

		cout << (st.empty() ? 0 : st.top().second) << " ";

		st.push({x, i + 1});
	}

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
