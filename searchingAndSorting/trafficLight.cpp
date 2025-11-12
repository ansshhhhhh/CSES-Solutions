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
	int x, n;
	cin >> x >> n;
	
	set<int> st = {0, x};
	map<int, int> mp;

	priority_queue<pair<int, int>> pq;
	pq.push({x, 0});
	mp[0] = x;

	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		
		auto it = st.upper_bound(p);
		int r = *it, l = *(--it);
		st.insert(p);
		pq.push({r - p, p});
		pq.push({p - l, l});

		mp[p] = r - p;
		mp[l] = p - l;
		
		while(!pq.empty()){
			auto [a, b] = pq.top();

			if(mp[b] == a){
				cout << a << " ";
				break;
			}else{
				pq.pop();
			}
		}
	}

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
