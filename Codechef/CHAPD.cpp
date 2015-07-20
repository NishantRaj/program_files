#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a , ll b){
	return b==0 ? a : gcd(b , a%b);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a , b;
		cin>>a>>b;
		//cout<<gcd(a , b)<<endl;
		int flag = 0;
		while(1){
			ll g = gcd(a , b);
			if(g == b){flag = 1 ; break ;};
			if(g == 1) break;
			b = g;
		}
		if(flag)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}