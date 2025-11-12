#include <bits/stdc++.h>
 
using namespace std;
 
void all(string s, vector<bool>& vis, set<string>& st, string ans){
	
	if(ans.size() == s.size()){
		st.insert(ans);
		return;
	}
 
	for(int i = 0; i < s.size(); i++){
		if(!vis[i]){
			vis[i] = true;
			all(s, vis, st, ans + s[i]);
			vis[i] = false;
		}
	}
 
}
 
 
void solve() {
	string s;
	cin >> s;
	
	int n = s.size();
 
	set<string> st;
 
	vector<bool> vis(n, false);
		
	all(s, vis, st, "");
 
	cout << st.size() << endl;
 
	for(string str: st)
		cout << str << endl;
}
 
 
int main(){
	int t = 1;
	//cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
