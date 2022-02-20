#include <bits/stdc++.h>
using namespace std;
int main () {
	int boxsize,n;
    cin>>boxsize>>n;
    vector<int> things(n);
    vector<int> dp(boxsize+1);dp[boxsize] = 1;
    for(int i = 0; i<n; i++){
        int a;cin>>a;
        things[i] = a;
    }
    for(int i = 0; i<n; i++){
		for(int j = boxsize; j>=0; j--){
			if(dp[j]&&things[i]<=j){
				dp[j-things[i]] = 1;
			}
		}
	}
    for(int i = 0; i<=boxsize; i++){
        if(dp[i]){
            cout<<i;
            break;
        }
    }
	return 0;
}