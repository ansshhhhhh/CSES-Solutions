#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int &val : a) cin >> val;
	
	int l = 0, ans = 0, sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		while(l < n && sum >= x){
			ans += sum == x;
			sum -= a[l];
			l++;
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
