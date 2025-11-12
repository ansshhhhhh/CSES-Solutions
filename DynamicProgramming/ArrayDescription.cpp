#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

const int mod = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);

	for(int &i: a) cin >> i;

	vector<int> prev(m + 1, 1);
	vector<int> curr(m + 1, 0);
		
	if(a[0]){
		for(int i = 0; i <= m; i++){
			if(i != a[0]) prev[i] = 0;
		}
	}else{
		prev[0] = 0;
	}
	curr = prev;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i - 1]){
				if(j == a[i - 1]){
					curr[j] = prev[j - 1] + prev[j]; 
					if(j < m) curr[j] += prev[j + 1];
				}else{
					curr[j] = 0;
				}
			}else{
				curr[j] = prev[j - 1] + prev[j]; 
				if(j < m) curr[j] += prev[j + 1];
			}
			curr[j] %= mod;
		}
		prev = curr;
	}
	int ans = 0;
	if(a[n - 1]){
		ans = curr[a[n - 1]];
	}else{
		for(int i = 1; i <= m; i++) ans += curr[i];
	}
	ans %= mod;
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
