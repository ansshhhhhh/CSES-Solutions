#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n;
	cin >> n;
		
	map<int, int> mp;
 
	int sum = 0, ans = 0;
	mp[0] = 1;
	
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
 
		sum += val;
 		
		if(sum >= 0 || abs(sum) % n == 0) ans += mp[sum % n];
		else ans += mp[n - abs(sum) % n];
		
		if(sum >= 0 || abs(sum) % n == 0) mp[sum % n]++;
		else mp[n - abs(sum) % n]++;
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
