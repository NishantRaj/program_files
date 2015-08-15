/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 13 August 2015 (Thursday) 22:14
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	int n , m ;
	cin>>n>>m;
	if(n - m >= m-1){
		if(m+1 > n){
			if(m-1 <= 0 )
				cout<<m<<endl;
			else
				cout<<m-1<<endl;
		} else
			cout<<m+1<<endl;
	} else{
		if(m-1 <= 0){
			if(m+1 > n )
				cout<<m<<endl;
			else{
				cout<<m+1<<endl;
			}
		} else
			cout<<m-1<<endl;
	}
	return 0;
}