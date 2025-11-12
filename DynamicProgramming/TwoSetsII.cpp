#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

int modpow ( int a , int b ) {
	long long res = 1;
	a %= mod ;
	while ( b > 0) {
		if ( b & 1) res = ( res * a ) % mod ;
		a = ( a * a ) % mod ;
		b >>= 1;
	}
	return res ;
}

int modinv ( int q ) {
	return modpow (q , mod - 2) ;
}

void solve() {
	int n;
	cin >> n;	
	int lim = n * (n + 1) / 2;
	
	vector<int> prev(2 * lim + 1, 0), curr(2 * lim + 1, 0);
	
	prev[lim] = 1;

	for(int i = 1; i < n; i++){
		for(int j = i - lim; j <= lim - i; j++){
			curr[lim + j] = prev[lim + j - i] + prev[lim + i + j];
			curr[lim + j] %= mod;
		}
		
		prev = curr;
	}

	int inv2 = (mod + 1) / 2;	
	int ans = (curr[lim] * inv2) % mod;
	cout << curr[lim] << endl;
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
