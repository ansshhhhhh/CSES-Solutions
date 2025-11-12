#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> a(n + 1, vector<char>(m + 1, 'E'));
 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char c;
			cin >> c;
 
			set<char> st = {c, a[i - 1][j], a[i][j - 1]};
 
			for(char ch = 'D'; ch >= 'A'; ch--){
				if(st.find(ch) == st.end()){
					a[i][j] = ch;
					break;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
			cout << a[i][j];
      }
		cout << endl;
   }
}
 
 
int main(){
	int t = 1;
	//cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
