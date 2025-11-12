#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string s;
	cin >> s;
	
	int ans = 0, cnt = 0;
	char x = ' ';
	for(char c: s){
		if(c == x){
			cnt++;
		}else{
			ans = max(ans, cnt);
			cnt = 1;
			x = c;
		}
	}
 
	ans = max(ans, cnt);
 
	cout << ans;
}
