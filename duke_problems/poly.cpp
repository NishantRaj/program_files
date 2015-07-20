#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int dp[1000005];
bool flag[1000005];
long long int solve(long long int arr[],long long int k[],long long int s)
{
	if(s>=n)
		return -1*LLONG_MAX;
	if(s==n-1)
		{
			dp[s]=arr[s];
			flag[s]=true;
			return dp[s];
		}
	if(dp[s]==-1)
	{
		
		long long int a,b,c,ans=-1*LLONG_MAX;
		a=solve(arr,k,s+k[s]);
		if(flag[s+k[s]] == true)
		{
			ans=max(ans,a);
			
		}
		b=solve(arr,k,s+k[s]+1);
		if(flag[s+k[s]+1] == true)
		{
			ans=max(ans,b);
			
		}
		c=solve(arr,k,s+k[s]+2);
		if(flag[s+k[s]+2] == true)
		{
			ans=max(ans,c);
			
		}
		if(ans!=-1 ||flag[s+k[s]] == true||flag[s+k[s]+1] == true||flag[s+k[s]+1] == true)
		{
			
			flag[s]=true;
			dp[s]=ans+arr[s];
		}
		else
		dp[s]=arr[s];

	}
	return dp[s];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		long long int arr[n];
		long long int k[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=0;i<n;i++)
			cin>>k[i];
		memset(dp,-1,sizeof(dp));
		memset(flag,false,sizeof(flag));
		
		int ans=solve(arr,k,0);
		if(flag[n-1]==false)
			cout<<"-1"<<endl;
		else
		cout<<ans<<endl;
		
	}
}
