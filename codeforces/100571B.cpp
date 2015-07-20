#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long temp[100009] , arr_f[100009];
int main(){
	int n , q , f1 , f2 , a , b;
	cin>>n>>q>>f1>>f2>>a>>b;
	int arr[n+9] ;
	for(int i = 0 ; i < n ; i++)
		cin>>arr[i];
	arr_f[1] = f1;
	arr_f[2] = f2;
	for(int i = 3 ; i<= n ; i++){
		arr_f[i] = (a*arr_f[i-2] + b*arr_f[i-1])%MOD;
	}
	while(q--){
		int l , r;
		cin>>l>>r;
		temp[l] = (temp[l]+arr_f[])
	}
}