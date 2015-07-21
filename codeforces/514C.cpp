/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 21 July 2015 (Tuesday) 13:00
===================================================*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000000007LL
#define base 4
#define ll long long
#define ull unsigned long long
ll prime_powers[600009];
void prime_generate(){
	prime_powers[0] = 1;
	for(int i = 1 ; i <= 600001 ; i++)
		prime_powers[i] = (prime_powers[i-1] * base)%mod;
}
ll get_hash(string s){
	int n = s.size();
	ull hash_val = 0;
	for(int i = 0 ; i < n ; i++)
		hash_val = (hash_val + s[i]*prime_powers[i+1])%mod;
	return hash_val;
}
		
int main(){
	prime_generate();
	int n , q;
	vector<ull> hash_array;
	cin>>n>>q;
	string s[n+9];
	for(int i = 0 ; i < n ; i++){
		cin>>s[i];
		hash_array.pb(get_hash(s[i]));
	}
	sort(hash_array.begin() , hash_array.end());
	while(q--){
		string s , temp;
		cin>>s;
		int flag = 0;
		ll save_hash = get_hash(s) , d , c;
		for(int i = 0 ; i<s.size() ; i++){
			d = (ull)s[i];
			for(char k = 'a' ; k<='c' ; k++){
				ll temp_hash = save_hash;
				c = (ull)k;
				if(c != d){
					temp_hash = (save_hash +((c-d)*prime_powers[i+1])%mod + mod)%mod;
					if(binary_search(hash_array.begin() , hash_array.end() , temp_hash)){
						flag = 1;
						break;
					}
				}
			}
			if(flag)
				break;
		}
		if(flag){
			cout<<"YES\n";
		} else 
			cout<<"NO\n";
	}
	return 0;
}