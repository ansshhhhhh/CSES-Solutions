#include <bits/stdc++.h>
using namespace std;
 
 
void solve();
 
int main(){
	int t = 1;
	//cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
 
 
void solve(){
	string s;
	cin >> s;
	
	int n = s.size();
 
	
	int cnt[26] = {0};
	
	int mx = 0;
	char ch = s[0];
 
	for(char c: s){
		mx = max(mx, ++cnt[c - 'A']);
 
		if(cnt[c - 'A'] == mx) ch = c;
	}
 
	if(2 * mx > n + 1){
		cout << -1 << endl;
		return;
	}
	//for(char chr = 'A'; chr <= 'Z'; chr++){
   //	cout << chr << cnt[chr - 'A'] << endl;      
   //}	
	//return;
	int rem = n;
	string ans = "";
	while(rem){
 
		char last = ans.size() ? ans.back() : '-';
		mx = 0;
		for(char chr = 'A'; chr <= 'Z'; chr++){
			if(cnt[chr - 'A'] > mx){
				mx = cnt[chr - 'A'];
				ch = chr;
			}
		}
 
		if(rem + 1 <= 2 * mx && ch != last && cnt[ch - 'A']){
			mx--;
 
			ans += ch;
 
			cnt[ch - 'A']--;
			rem--;
			continue;
		}
 
 
		for(char chr = 'A'; chr <= 'Z'; chr++){
			if(cnt[chr - 'A'] && chr != last){
				ans += chr;
				cnt[chr - 'A']--;
				rem--;
				break;
			}
		}
		
	}
 
	cout << ans;
}
