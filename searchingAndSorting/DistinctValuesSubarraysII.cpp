#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int &val : a) cin >> val;
	
	map<int, int> mp;
	int l = 0;

	int ans = 0;
	for(int i = 0; i < n; i++){
		mp[a[i]]++;

		if(mp.size() <= k) ans += (i - l + 1);

		while(l <= i && mp.size() > k){
			mp[a[l]]--;
			if(!mp[a[l]]) mp.erase(a[l]);
			l++;
			if(mp.size() <= k) ans += (i - l + 1);
		}

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
