#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
	string s;
	cin >> s;
 
	int cnt[26] = {0};
	
	for(char c: s)
		cnt[c - 'A']++;
	
	char ch = ' ';
 
	for(int i = 0; i < 26; i++)
		if(cnt[i] % 2){
			if(ch == ' '){
				ch = 'A' + i;
			}else{
				cout << "NO SOLUTION" << endl;
				return;
			}
		}
	
	string ans = "";
 
	for(int i = 0; i < 26; i++)
		if(cnt[i] % 2 == 0){
			for(int j = 0; j < cnt[i] / 2; j++)
				ans += char('A' + i);
		}
 
	if(ch != ' ') 
		for(int i = 0; i < cnt[ch - 'A']; i++)
			ans += ch;
 
   for(int i = 25; i >= 0; i--)
      if(cnt[i] % 2 == 0){
         for(int j = 0; j < cnt[i] / 2; j++)
            ans += char('A' + i);
      }
	
	cout << ans << endl;
}
 
 
int main(){
	int t = 1;
	//cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
