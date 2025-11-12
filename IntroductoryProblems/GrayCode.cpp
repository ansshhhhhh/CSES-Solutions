#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
	int n;
	cin >> n;
 
	stack<string> q;
	
	string s = "";
 
	for(int i = 0; i < n; i++) s += '0';
 
	q.push(s);
	unordered_set<string> st;
	st.insert(s);
 
	while(!q.empty()){
		string top = q.top();
		q.pop();
 
		cout << top << endl;
 
		for(int i = 0; i < n; i++){
			char prev = top[i];
			top[i] = prev == '0' ? '1' : '0';
			if(st.find(top) == st.end()){
				st.insert(top);
				q.push(top);
				break;
			}
 
			top[i] = prev;
		}
	}
}
 
 
int main(){
	int t = 1;
	//cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
