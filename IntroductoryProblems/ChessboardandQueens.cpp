#include <bits/stdc++.h>
 
using namespace std;
 
string b[8];
int ans = 0;
 
bool check(int x, int y){
	if(b[x][y] == '*') return false;
 
	for(int i = x - 1; i >= 0; i--) if(b[i][y] == '@') return false;
	int i = x, j = y;
 
	while(i-- && j--){
		if(b[i][j] == '@') return false;
	}
 
	i = x, j = y;
 
	while(i-- && j++ < 7){
		if(b[i][j] == '@') return false;
	}
 
	return true;
}
 
void f(int idx){
	if(idx == 8){
		ans++;
		return;
	}
 
	for(int i = 0; i < 8; i++){
		if(check(idx, i)){
			b[idx][i] = '@';
 
			f(idx + 1);
 
			b[idx][i] = '.';
		}
	}
}
 
 
void solve() {
	for(int i = 0; i < 8; i++)
		cin >> b[i];
	
	f(0);
	
	cout << ans;
}
 
 
int main(){
	int t = 1;
	//cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
