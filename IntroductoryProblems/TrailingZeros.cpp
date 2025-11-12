#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	
	int ans = 0;
 
	for(int i = 5; i <= n; i *= 5)
		ans += (n / i);
	
	cout << ans << endl;	
}
 
 
int main(){
	int t = 1;
	//cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
