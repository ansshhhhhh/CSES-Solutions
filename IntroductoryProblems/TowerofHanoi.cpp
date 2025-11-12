#include <bits/stdc++.h>
 
using namespace std;
 
void TOH(int l, int r, int m, int n){
	if(n == 1){
		cout << l << " " << r << endl;
		return;
	}
 
	TOH(l, m, r, n - 1);
	TOH(l, r, m, 1);
	TOH(m, r, l, n - 1);
}
 
void solve() {
	int n;
	cin >> n;
 
	int l = 1;
 
	for(int i = 2; i <= n; i++)
		l = 2 * l + 1;
	
	cout << l << endl;
 
	TOH(1, 3, 2, n);
}
 
 
int main(){
	int t = 1;
	//cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}

