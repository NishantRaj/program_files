/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 22 July 2015 (Wednesday) 19:46
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
	int arr[n+9] , mi = INT_MAX;
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
		mi = min(arr[i] , mi);
	}
	if(mi==1){
		cout<<"-1"<<endl;
	} else
		cout<<1<<endl;
	return 0;
}