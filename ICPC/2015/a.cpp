/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 11 October 2015 (Sunday) 16:47
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	int n;
	scanf("%d",&n);
	int arr[n+9];
	for(int i = 0 ; i < n ; i++)
		scanf("%d" , &arr[i]);
	sort(arr , arr+n);
	int cum[n+9];
	memset(cum , 0 , sizeof cum);
	for(int i = 1 ; i <= n ; i++){
		cum[i] = cum[i-1] + arr[i-1];
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int k;
		scanf("%d",&k);
		int sum_till = 0;
		if(k == 0){
			sum_till = n;
		} else{
			sum_till = ceil((double)n/(double)(k+1));
		}
		printf("%d\n", cum[sum_till]);
	}
	return 0;
}