/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 29 July 2015 (Wednesday) 18:51
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
	cin>>n;
	int arr[n+9];
	long long hash[100009];
	memset(hash , 0 , sizeof hash);
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
		hash[arr[i]]++;
	}
	hash[2] = max(2*hash[2] , hash[1]);
	for(long long i = 3 ; i<= 100000 ; i++){
		hash[i] = max(i*hash[i] , max(hash[i-2] + i*hash[i], hash[i-1]));
	}
	cout<<hash[100000]<<endl;
	return 0;
}