#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n;
	cin >> n;
	set<int> st = {0};
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;

		set<int> st1;
		for(int j: st)
			st1.insert(j + x);

		for(int j: st1)
			st.insert(j);
	}

	st.erase(0);
	
	cout << st.size() << endl;
	for(int i: st)
		cout << i << " ";
	cout << endl;
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
