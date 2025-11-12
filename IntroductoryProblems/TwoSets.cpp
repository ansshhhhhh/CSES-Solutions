#include <bits/stdc++.h>
 
using namespace std;
 
 
 
void solve() {
	int n;
	cin >> n;
 
	if(n % 4 == 0 || n % 4 == 3){
		cout << "YES" << endl;
 
		vector<int> st1, st2;
		int l = 1, r = n;
		if(n % 4  != 0){
			l = 4;
			st1 = {1, 2};
			st2 = {3};
		}
		
		while(l < r){
			if(l % 2){
				st1.push_back(l);
				st1.push_back(r);
			}else{
				st2.push_back(l);
            st2.push_back(r);
			}
			l++;
			r--;
		}
 
		cout << st1.size() << endl;
		for(int i: st1)
			cout << i << " ";
	
		cout << endl << st2.size() << endl;
 
		for(int i: st2)
         cout << i << " ";
	}else{
		cout << "NO";
	}
}
 
 
int main(){
	int t = 1;
//	cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
