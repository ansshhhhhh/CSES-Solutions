#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;

	ll sum = 0;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		sum += y;

		a[i] = x;
	}
	
	sort(a.begin(), a.end());

	ll sum2 = 0, last = 0;
	
	for(int i: a){
		last += i;
		sum2 += last;
	}

	cout << sum - sum2 << endl;
}

int main() {
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
