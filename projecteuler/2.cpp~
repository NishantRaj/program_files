#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll fibo_even_sum[1000];
ll fibo[100];
int k ;
void pre(){
	ll a= 1 , b = 2 , c;
	fibo[0] = 1 , fibo_even_sum[0] = 0;
	fibo[1] = 2 , fibo_even_sum[1] = 2;
	k = 2;
	while(b <= 40000000000000000LL){
		c = a + b;
		a = b;
		b = c;
		if(!(c&1))
			fibo_even_sum[k] = fibo_even_sum[k-1] + c;
		else
			fibo_even_sum[k] = fibo_even_sum[k-1];
		fibo[k] = c;
		k++;
	}
}
int main(){
	int t;
	cin>>t;
	pre();
	while(t--){
		ll n;
		cin>>n;
		int pos = upper_bound(fibo , fibo + k , n) - fibo;
		//cout<<pos<<" " << fibo[pos-1]<<endl;
		cout<<fibo_even_sum[pos-1]<<endl;
	}
	return 0;
}
