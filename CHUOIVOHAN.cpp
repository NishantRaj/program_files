/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 01 June 2016 (Wednesday) 22:23
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll a, b, c;
	cin>>a>>b>>c;
	if(c==0){
		if(a == b) cout<<"YES\n";
		else cout<<"NO\n";
	}
	else if(c<0 && (b < a)){
		if (abs(b-a)%c == 0)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	else if(c > 0 && b > a){
		if (abs(b-a)%c == 0)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	else
		cout<<"NO\n";
	return 0;
}