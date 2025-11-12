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
	int n, m;
	cin >> n >> m;

	vector<int> p(n + 1, n + 1);
	
	vector<int> a(n + 1);

	for (int i = 1; i < n + 1; i++) {
		int x;
		cin >> x;
		a[i] = x;
		p[x] = i;
	}
	int ans = 0;

	for(int i = 1; i <= n; i++){
		ans += p[i - 1] > p[i];	
	}
	
	while(m--){
		int x, y;
		cin >> x >> y;
		
		int n1 = a[x], n2 = a[y];
		
		ans -= p[n1 - 1] > p[n1];
		ans -= p[n2 - 1] > p[n2];
		
		if(n1 < n && n1 + 1 != n2) ans -= p[n1] > p[n1 + 1];
		if(n2 < n && n2 + 1 != n1) ans -= p[n2] > p[n2 + 1];

		swap(a[x], a[y]);
		swap(p[n1], p[n2]);

		ans += p[n1 - 1] > p[n1];
		ans += p[n2 - 1] > p[n2];

		if(n1 < n &&  n1 + 1 != n2) ans += p[n1] > p[n1 + 1];
      if(n2 < n && n2 + 1 != n1) ans += p[n2] > p[n2 + 1];
		cout << ans << endl;
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
