/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 22 July 2015 (Wednesday) 20:05
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
ll tri[1009];
int triangle(){
	tri[1] = 1;
	for(int i = 2 ; i <=1000 ; i++){
		tri[i] = tri[i-1] + 2*i - 1;
		// cout<<tri[i]<< " ";
	}
}
int main(){
	
	triangle();
	int arr[10];
	long long ans = 0;
	int count=0 , mi = INT_MAX , ma = -1;
	for(int i = 0 ; i < 6 ; i++){
		cin>>arr[i];
		mi = min(arr[i] , mi);
		ma = max(ma , arr[i]);
	}
	ll a  = ma , b = mi;
	ma += 2*mi;
	ll total = tri[ma];
	total -= 3 * tri[mi];
	cout<<total<<endl;
	return 0;
}