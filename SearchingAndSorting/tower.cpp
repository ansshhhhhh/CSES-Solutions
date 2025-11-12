#ifdef ONDEVI
	#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long
#define double long double
#define yesr {cout << "YES" << endl; return;}
#define nor {cout << "NO" << endl; return;}

using namespace std;

void solve() {
	int n;
	cin >> n;
	
	multiset<int> st;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		auto it = st.upper_bound(x);

		if(it != st.end()) st.erase(it);

		st.insert(x);
	}
	
	cout << st.size() << endl;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TET = 1;
	//cin >> TET;
	for (int i = 1; i <= TET; i++) {
		
		solve();
	}
	#ifdef ONDEVI
		cerr << endl << "finished in " << (double)(clock()) * 1.0 / CLOCKS_PER_SEC << " sec\n- - - - - - - - - -\nOutput:" << endl;
	#endif
}
