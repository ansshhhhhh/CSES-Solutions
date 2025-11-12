#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

void solve() {
	int n, x;
	cin >> n >> x;

	vector<int> a(n);
	for (int &val : a) cin >> val;
	
	map<int, vector<pair<int, int>>> mp;

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int sum = a[i] + a[j];
			if(mp.find(sum) == mp.end()){
				mp[sum].push_back({i + 1, j + 1});
			}else{
				mp[sum] = {{i + 1, j + 1}};
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int val = x - a[i] - a[j];
			if(mp.find(val) != mp.end()){
				for(auto p: mp[val]){
					if(i != p.first - 1 && j != p.second - 1 && j != p.first - 1 && i != p.second - 1){
						cout << p.first << " " << p.second << " " << i + 1 << " " << j + 1 << endl;
						return;
					}
				}
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;
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
