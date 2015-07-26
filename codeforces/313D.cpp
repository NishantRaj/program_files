/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 22 July 2015 (Wednesday) 20:17
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define base 125
ll hash1[200009] , hash2[200009];
ll prime[200009];
string a , b;
void prime_g(){
	prime[0] = 1;
	for(int i = 0 ; i < 200009 ; i++)
		prime[i] = (prime[i-1]*base)%mod;
}
void genrate_hash(int n){
	hash1[0]=0 , hash2[0]=0;
	for(int i = 1 ; i <= n ; i++)
		hash1[i] = (hash1[i-1] + a[i-1]*prime[i])%mod , hash2[i] = (hash2[i-1] + b[i-1]*prime[i])%mod;
}
int main(){
	cin>>a>>b;
	flag = 0;
	int n = a.size();
	if(hash1[n-1] == hash2[n-1])
		flag = 1;
	else if(n&1)
		flag =0;
	int s_a_1 , s_a_2 , e_a_1 , e_a_2 , s_b_1 , s_b_2 , e_b_1 , e_b_2;
	s_a_1 = 1 , e_a_1  = n/2 , s_b_1 = 1 , e_b_1 = n/2 ,s_a_2 = n/2+1 , e_a_2  = n , s_b_2 = n/2+1 , e_b_2 = n ; 
	while(!flag){
		ll p ,q , r , s;
		p = (hash1[e_a_1] - hash1[s_a_1-1] + mod)%mod;
		q = (hash1[e_a_2] - hash1[s_a_2 - 1] + mod)%mod;
		r = (hash2[e_b_1] - hash2[s_b_1-1]+mod)%mod;
		s = (hash2[e_b_2] - hahs2[s_b_2 - 1] + mod)%mod;
		if((p==r || p == s) && (q == r || q == s)){
			flag = 1;
			break;
		} else if((p==r || p == s)){
			if(p==r){
				s_a_1 = s_a_2 , e_a_1 = (s_a_2 + e_a_2)/2;
				s_a_2 = e_a_1 + 1;
				s_b_1 = s_
			}
		} else if((q == r || q == s)){

		} else{
			break;
		}
	}
	return 0;
}