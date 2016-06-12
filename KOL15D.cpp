/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 31 October 2015 (Saturday) 16:26
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair < ll , ll >
#define pb push_back
#define mp make_pair
#define mod 1000000009
struct cmp{
	bool operator()(const pll &a , const pll &b){
		if(a.second - a.first == b.second - b.first){
			return a.first < b.first;
		} else return a.second - a.first < b.second - b.first;
	}
};
int main(){
	
	ll n , q;
	cin>>n>>q;

	
	return 0;
}