#include <bits/stdc++.h>
using namespace std;
int dp[20000][500];
int main()
{
	string s;
	int q;
	cin>>s;
	cin>>q;
	while(q--){
		int m,l;
		cin>>m>>l;
		long long *sd;
		memset(dp,0,sizeof dp);
		dp[0][(s[0]-48)%m]++;
		long long ans=dp[0][l];
		for(int i=1;i<s.size();i++)
		{
			for(int j =0 ;j<m;j++){
				dp[i][(j*10 + s[i] - 48)%m] += dp[i-1][j];
			}
			dp[i][(s[i]-48)%m]++;
			ans += dp[i][l];
		}
		cout<<ans<<endl;
	}
	return 0;
}