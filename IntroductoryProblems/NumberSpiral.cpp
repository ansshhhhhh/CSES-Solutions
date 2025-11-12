#include <bits/stdc++.h>
 
using namespace std;
 
 
 
void solve() {
	int y, x;
	cin >> y >> x;
 
	int n = max(x, y);
 
	long long ans = (n - 1) * 1LL * (n - 1);
	
	if(n % 2){
		ans += x + (n - y);
	}else{
		ans += y + (n - x);
	}
	
	cout << ans << endl;
}
 
 
int main(){
	int t = 1;
	cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
