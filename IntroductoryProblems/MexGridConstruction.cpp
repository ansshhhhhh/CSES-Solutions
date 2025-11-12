#include <bits/stdc++.h>
 
using namespace std;
 
int a[100][100];
 
int findMex(int ii, int jj){
	int f[201] = {0};
 
	for(int i = ii - 1; i >= 0; i--) f[a[i][jj]] = 1;
	for(int i = jj - 1; i >= 0; i--) f[a[ii][i]] = 1;
 
	for(int i = 0; i <= 200; i++)
		if(f[i] == 0) return i;
	
	return 201;
}
 
void solve() {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = findMex(i, j);
 
			cout << a[i][j] << " ";
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
