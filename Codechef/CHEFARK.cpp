/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 04 June 2016 (Saturday) 17:49
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007LL
ll fact[100009] , inv[100009];
inline ll inv_mod(ll x, ll p){
	ll a = 1 , n = x;
	while(p){
		if(p&1)
			a = (a*n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return a;
}
void pre(){
	fact[0] = 1;
	inv[0] = inv_mod(fact[0] , MOD-2);
	for(int i = 1 ; i<= 100000 ; i++){
		fact[i] = (fact[i-1]*i)%MOD;
		inv[i] = inv_mod(fact[i] , MOD-2);
	}
}
inline void scanint(int &a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    a=0;
    while (c>33)
    {
        a=a*10+c-'0';
        c=getchar_unlocked();
    }
}
ll ncr(int n , int r){
	ll ans;
	ans = (fact[n]*inv[n-r])%MOD;
	ans = (ans * inv[r])%MOD;
	return ans;
}
int main(){
	pre();
	int t;
	scanint(t);
	while(t--){
		int n , k;
		scanint(n);
		scanint(k);
		int effective_length = n;
		int use_less_except_0;
		for(int i = 0 ; i< n ; i++){
			scanint(use_less_except_0);
			if(use_less_except_0 == 0)
				effective_length--;
		}
		if(effective_length < n)
			n = effective_length + 1;
		if(k >= n-1){
			printf("%lld\n", inv_mod(2 , n-1));
		} else {
			ll ans_array[k+9];
			ans_array[0] = 1;
			ans_array[1] = n;
			for(int i = 2 ; i <=k ; i++){
				ans_array[i] = (ncr(n , i) + ans_array[i-2])%MOD;
			}
			printf("%lld\n", ans_array[k]);
		}
	}
	return 0;
}