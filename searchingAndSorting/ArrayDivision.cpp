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
	
	auto check = [&](int m){
		int K = 1, ct = m;
		for(int i: a)
			if(ct >= i)
				ct -= i;
			else{
				K++;
				ct = m - i;
			}
		return K <= k;
	};
	
	int l = *max_element( a.begin(), a.end()), h = accumulate( a.begin(), a.end(), 0LL);
	int ans = h;
	while(l <= h){
		int m = l + (h - l) / 2;
		if(check(m)){
			ans = m;
			h = m - 1;
		}else
			l = m + 1;
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
