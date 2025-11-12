#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
	int a, b;
	cin >> a >> b;
 
	int d = abs(a - b);
 
	int mn = min(a, b);
 
	cout << (mn >= d &&  (mn - d) % 3 == 0 ? "YES" : "NO" ) <<  endl;
}
 
 
int main(){
	int t = 1;
	cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
