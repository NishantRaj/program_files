#include <bits/stdc++.h>
using namespace std;
long long dp[100009];
long long arr[100009][2];
long long n , p;
long long path(int i){
	if(i >= n ) 
		return -1LL*999999999999999LL;
	if(dp[i]!=0)
		return dp[i];
	if(i == n-1){
		p = 1;
		return 0;
	}
	long long a = 0,b = 0  ,c = 0;
	a = path(i + arr[i][1]) ;
	b = path(i + arr[i][1] + 1) ;
	c = path(i + arr[i][1] + 2) ;
	if(i + arr[i][1] < n)
		a += arr[i+arr[i][1]][0];
	if(i + arr[i][1] + 1 < n)
		b += arr[i+arr[i][1] + 1][0];
	if( i + arr[i][1] + 2 < n)
		c += arr[i + arr[i][1] + 2][0];
	return dp[i] = max( a , max(b ,  c));
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		p = 0;
		memset(dp , 0 , sizeof dp);
		for(int i = 0 ; i < n ; i++)
			cin>>arr[i][0];
		for(int i = 0 ; i < n ; i++)
			cin>>arr[i][1];
		long long val = path(0) + arr[0][0];
		if(p==0)
			cout<<-1<<endl;
		else
			cout<<val<<endl;
	}
	return 0;
}
