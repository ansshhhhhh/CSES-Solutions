#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;

void solve() {
	ll n, t;
	cin >> n >> t;

	vector<ll> a(n);
	for (ll &val : a) cin >> val;
	
	auto check = [&](ll m){
		ll T = 0;

		for(ll i: a)
			T += m / i;
		
		return T >= t;
	};
	
	ll ans = t * (*min_element(a.begin(), a.end()));

	ll l = 1, h = ans;
	while(l <= h){
		ll m = l + (h - l) / 2;

		if(check(m)){
			ans = m;
			h = m - 1;
		}else
			l = m + 1;
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cerr << "- - - - - - - - - - - - -\nOutput:" << endl;
	ll TET = 1;
	//cin >> TET;
	for (ll i = 1; i <= TET; i++) {
		cerr << "Case #" << i << ": "; 
		solve();
	}
	cerr << endl << "finished in " << (double)(clock()) * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
}
