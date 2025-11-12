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

	set<int> st;
	

	for (int i = 1; i <= n; i++) 
		st.insert(i);

	int i = 0;
	
	while(st.size()){
		auto it = st.upper_bound(i);
		if(it == st.end()) it = st.begin();
		
		it++;
		
		if(it == st.end()) it = st.begin();

		cout << *it << " ";
		i = *it;
		st.erase(it);
	}	
	
	cout << endl;
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
