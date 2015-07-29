/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 29 July 2015 (Wednesday) 18:30
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	int n , m;
	cin>>n>>m;
	vector<int> v;
	for(int i = 0 ; i < m ; i++){
		int temp;
		cin>>temp;
		v.pb(temp);
	}
	sort(v.begin() , v.end());
	int mi = INT_MAX;
	for(int i = 0 ; i < m - n +1; i++){
		mi = min(mi , v[i+n-1] - v[i]);
	}
	cout<<mi<<endl;
	return 0;
}