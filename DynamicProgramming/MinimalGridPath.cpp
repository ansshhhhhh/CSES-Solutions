#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n;
	cin >> n;
	
	vector<string> grid(n);

	for(string &s: grid) cin >> s;
	
	string ans = "";
	ans += grid[0][0];
	//cout << ans << endl;
	vector dp(n, vector<bool>(n, 0));
	dp[0][0] = true;
	
	for(int k = 1; k < n; k++){
		int i = k, j = 0;
		char c = 'Z';
		while(i >= 0){
			bool cons = false;
			if(i - 1 >= 0) cons = dp[i - 1][j];
			if(j - 1 >= 0) cons = cons || dp[i][j - 1];
			//if(cons) cout << grid[i][j] << " ";
			if(cons) c = c > grid[i][j] ? grid[i][j] : c;
			i--; j++;
		}
		ans += c;
		i = k, j = 0;
		while(i >= 0){
			bool cons = false;
			if(i - 1 >= 0) cons = dp[i - 1][j];
			if(j - 1 >= 0) cons = cons || dp[i][j - 1];

			if(cons && c == grid[i][j]) dp[i][j] = true;
			i--; j++;
		}
		//cout << endl;
	}
	for(int k = 1; k < n; k++){
		int i = n - 1, j = k;
		char c = 'Z';
		while(j < n){
			bool cons = false;
			if(i - 1 >= 0) cons = dp[i - 1][j];
			if(j - 1 >= 0) cons = cons || dp[i][j - 1];
			//if(cons) cout << grid[i][j] << " ";
			if(cons) c = c > grid[i][j] ? grid[i][j] : c;
			i--; j++;
		}
		ans += c;
		i = n - 1, j = k;
		while(j < n){
			bool cons = false;
			if(i - 1 >= 0) cons = dp[i - 1][j];
			if(j - 1 >= 0) cons = cons || dp[i][j - 1];

			if(cons && c == grid[i][j]) dp[i][j] = true;
			i--; j++;
		}
		//cout << endl;
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
