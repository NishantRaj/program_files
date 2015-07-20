#include <bits/stdc++.h>
using namespace std;
long long dp[10000];
long long x[1009];
long long y[1009];
long long p , k , n;
long long path(int i , int side){
	if(i  < 0 )
		return 0;
	if(dp[i] != -1)
		return dp[i];
	long long mi = 99999999999999LL;
	for(int j = 1 ; j <= k ; j++){
		long long a = 0 , b  = 0;
		if(side == 1){
			long long add1 =0, add2=0;
			if(i-j >= 0){
				add1 = x[i-j];
				add2 = y[i-j] + p;
			}
			a = path(i-j , 1) + add1;
			b = path(i-j , 2) + add2;

		}
		else if(side ==2){
			long long add1 =0, add2=0;
			if(i-j >= 0){
				add1 = y[i-j];
				add2 = x[i-j] + p;
			}
			a = path(i-j , 1) + add2;
			b = path(i-j , 2) + add1;
		}
		mi = min(mi , min(a , b));
	}
	cout<<i<<" "<<mi<<endl;
	return dp[i] = mi;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i = 0 ; i<= 1000 ; i++)
			dp[i] = -1;
		cin>>n>>k>>p;
		for(int i = 0 ; i < n ; i++)
			cin>>x[i];
		for(int i = 0 ; i < n ; i++)
			cin>>y[i];
		long long res1 = path(n-1, 1) + x[n-1] , res2;
		for(int i = 0 ; i<= 1000 ; i++)
			dp[i] = -1;
		res2 = path(n-1, 2) + y[n-1];
		cout<<min(res1 , res2) <<endl;
	}
	return 0;
}