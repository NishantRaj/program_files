/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 15 August 2015 (Saturday) 13:53
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
int check[1000009];
void shiev(int n){
	for(int i = 2 ; i <= n ; i++){
		if(!check[i]){
			for(int j = i ; j<= n ; j+=i)
				check[j] += i;
		}
	}
}
int main(){
	int n , k;
	cin>>n>>k;
	shiev(n);
	int ans  =0;
	for(int i = 1 ; i<= n ; i++)
		if(check[i] == k)
			ans++;
	cout<<ans<<endl;
	return 0;
}