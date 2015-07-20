#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll save[100009];
void pre(){
	ll temp = 1;
	save[0] = temp-1;
	for(int i = 1 ; i <= 100000 ; i++){
		temp =(temp<<1)%MOD;
		save[i] = (temp - 1 + MOD)%MOD;
	}
}
int main(){
	pre();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll arr[n+9];
		for(int i = 0 ; i < n ; i++)
			cin>>arr[i];

		sort(arr , arr+n , [](int a , int b){return a > b ;});
		ll res = 0;
		for(int i = 0 , j = n - 1 ; i < n - 1 ; i++ , j--){
			//cout<<save[j]<<" " <<arr[i] << " " <<arr[j]<<" " <<i<<" " <<j<<endl;
			res = (res +  (save[j]*arr[i])%MOD - (save[j]*arr[j])%MOD + MOD )%MOD;
		}

		cout<<res<<endl;
	}
	return 0;
}