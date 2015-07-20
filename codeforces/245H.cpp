#include <bits/stdc++.h>
using namespace std;
bool isPalin[5009][5009];
int dp[5009][5009];
char s[5009];
void preProcess(){

	int n = strlen(s);

	for(int i = 0 ; i < n ; i++){
		isPalin[i][i] = 1;
		isPalin[i+1][i] = 1;
		dp[i][i] = 1;
	}

	for(int j = 2 ; j <= n ; j++){

		for(int i = 0 ; i <= n - j ; i++){

			isPalin[i][i+j-1] = isPalin[i+1][i+j-2] & (s[i] == s[i+j-1]);
			dp[i][i+j-1] = dp[i][i+j-2] + dp[i+1][i+j-1] - dp[i+1][i+j-2] + isPalin[i][i+j-1];
		}
	}
}
int main(){

	scanf("%s",s);
	preProcess();
	int q;
	scanf("%d",&q);
	while(q--){

		int l , r;
		scanf("%d%d",&l,&r);
		l-- , r--;

		cout<<dp[l][r]<<endl;
	}
}