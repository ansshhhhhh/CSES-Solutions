#include <bits/stdc++.h>
 
using namespace std;
 
 
const int mod = 1e9 + 7;
 
int binExp(int a, int b){
	
	long long ans = 1;
	
	if(!b) return ans;
 
	if(b % 2)
		ans = (binExp(a, b - 1) * a) % mod;
	else{
		long long temp = binExp(a, b / 2);
		ans = (temp * temp) % mod;
	}
 
	return ans;
}
 
void solve() {
	int n;
	cin >> n;
 
	cout << binExp(2, n);
}
 
 
int main(){
	int t = 1;
//	cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
