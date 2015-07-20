#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000009
#define base 7927
int len;
ll forward_hash[100009] , backward_hash[100009] , prime_power[100009] , inverse_prime_power[100009];
ll pow_mod(ll a , ll b){
	ll res = 1 , p = a;
	while(b){
		if(b&1)
			res = (res*p)%MOD;
		p = (p*p)%MOD;
		b>>=1;
	}
	return res;
}
void calculate_prime_power(int n){
	prime_power[0] = 1;
	inverse_prime_power[0] = 1;
	for(int i = 1 ; i <= n ; i++){
		prime_power[i] = (prime_power[i-1]*base);
		if(prime_power[i] > MOD)
			prime_power[i] %= MOD;
		inverse_prime_power[i] = (pow_mod(prime_power[i] , MOD-2));
	}
}
void hashing(int n , char s[]){
	for(int i = 1 , j = n; i<= n ;j--, i++){
		forward_hash[i] = (forward_hash[i-1] + s[i]*prime_power[i]);
		if(forward_hash[i] > MOD)
			forward_hash[i]%= MOD;
		backward_hash[j] = (backward_hash[j+1] + s[j]*prime_power[i]);
		if(backward_hash[j] > MOD)
			backward_hash[j]%= MOD;
	}
}
ll getForwardHash(int leftPos , int rightPos){
	ll temp =  (forward_hash[rightPos] - forward_hash[leftPos-1]);
	if(temp < 0)
		temp+= MOD;
	if(temp > MOD)
		temp%= MOD;
	temp = (temp * inverse_prime_power[leftPos - 1]);
	if(temp > MOD)
		temp%= MOD;
	return temp;
}
ll getBackwardHash(int l , int r){
	ll temp= (backward_hash[l] - backward_hash[r+1]);
	if(temp < 0)
		temp+= MOD;
	if(temp > MOD)
		temp%= MOD;
	temp = (temp * inverse_prime_power[len - r]);
	if(temp > MOD)
		temp%= MOD;
	return temp;
}
int main(){
	char s[100009];
	scanf("%s" , s+1);
	len = strlen(s+1);
	int q;
	scanf("%d" , &q);
	calculate_prime_power(len);
	hashing(len , s);
	while(q--){
		int i , j , k , l;
		scanf("%d%d%d%d" , &i , &j , &k , &l);
		ll hash1 , hash2 ;
		if((i == k && j == l) || (j < k) || (i > l) ) {
			//cout<<0<<endl;
			hash1 = getForwardHash(k , l);
			hash2 = getBackwardHash(k , l);
			
		}else if((i<= k && j>= l)){ 
			hash1 = getForwardHash(i+j -l , i+j-k);
			hash2 = getBackwardHash(j+i - l  , j +i - k);
		} else if( i>= k && j<= l){
			//cout<<1<<endl;
			//cout<<getForwardHash(k , i-1)<<" "<<getBackwardHash(i , j)<<" "<<getForwardHash(j+1 , l)<<endl;
			hash1 = (getForwardHash(k , i-1) + (getBackwardHash(i , j)*prime_power[i-k])%MOD + (getForwardHash(j+1 , l)*prime_power[j-k+1])%MOD);
			if(hash1 > MOD)
				hash1%= MOD;
			hash2 = (getBackwardHash(j+1 , l) + (getForwardHash(i , j)*prime_power[l-j])%MOD + (getBackwardHash(k  , i-1) * prime_power[l - i+1])%MOD);
			if(hash2 > MOD)
				hash2 %= MOD;

		} else if(i < k && j >= k && j < l){
			//cout<<2<<endl;
			hash1 = (getBackwardHash(i , i - k + j) + (getForwardHash(j+1 , l)*prime_power[j-k+1])%MOD);
			if(hash1 > MOD)
				hash1%= MOD;
			hash2 = (getBackwardHash(j+1 , l) + (getForwardHash(i , i- k + j)*prime_power[l-j])%MOD);
			if(hash2 > MOD)
				hash2 %= MOD;
		} else if(i > k && i <= l && j >= k){
			hash1 = (getForwardHash(k , i-1) + (getBackwardHash(j - (l - i) , j)*prime_power[i-k])%MOD );
			if(hash1 > MOD)
				hash1%= MOD;
			hash2 = (getForwardHash( j - (l-i) , j) + getBackwardHash(k , i-1)*prime_power[l-i+1]);
			if(hash2 > MOD)
				hash2 %= MOD;
		}
		if(hash1 == hash2){
			printf("Yes\n");
		} else printf("No\n");
	}
	return 0;
}