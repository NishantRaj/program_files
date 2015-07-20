#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define MU 1000000009
#define MOD 1003162739
ULL hash[200009];
void preHash(int arr[] , int n )
{
	hash[n] = 0;
	for(int i = n -1 ; i >= 0 ; i--)
		hash[i] = (hash[i+1]*MU + arr[i] + MOD)%MOD;
}
void solve(int text[] , int pattern[] , int n , int m){
	ULL phv = 0 , multiplier = 1;
	for(int i = m - 1  ; i >= 0 ; i --){
		phv = (phv*MU + pattern[i] + MOD)%MOD;
		multiplier =(multiplier * MU)%MOD;
	}
	preHash(text , n);
	int count = 0 ;
	for(int i = 0 ; i < n - m + 1 ; i++)
	{
		if((hash[i] - (multiplier*hash[i+m])%MOD + MOD)%MOD == phv){
			count++;
		}
	}
	cout<<count<<endl;
}
int main()
{
	int n , m;
	cin>>n>>m;
	int a[n+9] , b[m+9];
	for(int i = 0 ; i < n ; i++)
		cin>>a[i];
	for(int i = 0 ; i < m ; i++)
		cin>>b[i];
	int text[n+9] , pattern[m+9];
	for(int i = 1 ; i < n ; i++)
		text[i-1] = a[i] - a[i-1];
	for(int i = 1 ; i < m ; i++)
		pattern[i-1] = b[i] - b[i-1];
	n--;
	m--;
	solve(text , pattern , n , m);
	return 0;
}