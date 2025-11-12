#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n, k;
	cin >> n >> k;
 
	vector<pair<int, int>> p(n);
	for (pair<int, int> &val : p) {
		cin >> val.second >> val.first;
	}
	sort(p.begin(), p.end());
	
	set<pair<int, int>> st;
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		auto it = st.upper_bound({-p[i].second, -i});
		if(it == st.end() && k == 0) continue;

		if(it == st.end()){
			k--;
			ans++;
			st.insert({-p[i].first, - i});
			continue;
		}
		ans++;
		st.erase(it);
		st.insert({-p[i].first, -i});
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
