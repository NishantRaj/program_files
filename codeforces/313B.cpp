/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 22 July 2015 (Wednesday) 19:21
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	int a1,b1 , a2,b2,a3,b3;
	cin>>a1>>b1>>a2>>b2>>a3>>b3;
	vector<pair<int , int> > v;
	v.pb(mp(a2+a3 , max(b2,b3)));
	v.pb(mp(a2+b3 , max(b2 , a3)));
	v.pb(mp(b2+a3 , max(a2 , b3)));
	v.pb(mp(b2+b3 , max(a2 , a3)));
	int flag = 0;
	for(int i = 0;  i < 4 ; i++){
		if((a1 >= v[i].first && b1 >= v[i].second) ||(a1 >= v[i].second && b1 >= v[i].first)){
			flag = 1;
			break;
		}
	}
	if(flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}