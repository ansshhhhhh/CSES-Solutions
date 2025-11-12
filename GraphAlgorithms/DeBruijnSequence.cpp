#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

string find_next(string s, int x){
	int n = s.size();
	string next = s;
	for(int i = 0; i < n - 1; i++){
		next[i] = s[i + 1];
	}
	next[n - 1] = '0' + x;
	return next;
}

void dfs(string node, vector<int>& vis, map<string, vector<pair<string, int>>>& g, vector<string>& ans){

	while(!g[node].empty()){
		auto [v, i] = g[node].back();
		g[node].pop_back();
		if(vis[i] == 0){
			vis[i] = 1;
			dfs(v, vis, g, ans);
		}
	}
	ans.push_back(node);
}


void solve() {
	int n;
	cin >> n;
	
	if(n == 1){
		cout << "01" << endl;
		return;
	}	

	map<string, vector<pair<string,int>>> g;
	
	int all = 1LL << (n - 1);
	int id = 0;
	for(int p = 0; p < all; p++){
		string curr;
		for(int i = n - 2; i >= 0; i--)
			if(p & (1 << i))
				curr += '1';
			else
				curr += '0';
		string next = find_next(curr, 0);
		g[curr].push_back({next, id});
		id++;
		//cout << curr << " " << next << endl;
		next = find_next(curr, 1);
		//cout << curr << " " << next << endl;
		g[curr].push_back({next, id});
		id++;
	}
	
	vector<int> vis(id, 0);
	string start = "";
	vector<string> ans;

	for(int i = 1; i < n; i++) start += '0';
	
	dfs(start, vis, g, ans);
	reverse(ans.begin(), ans.end());
	cout << ans[0];
		
	int sz = ans.size();
	for(int i = 1; i < sz; i++){
		cout << ans[i][n - 2];
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cerr << "\nOutput:\n- - - - - - - - - - - - -" << endl;
	int TET = 1;
	//cin >> TET;
	for (int i = 1; i <= TET; i++) {
		cerr << "Case #" << i << ": "; 
		solve();
	}
	cerr << endl << "finished in " << (double)(clock()) * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
}
