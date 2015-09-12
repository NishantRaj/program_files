/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 12 September 2015 (Saturday) 21:04
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
class data{
public:
	ll val_a , val_b;
	int low , high;
	data():val_a(0) , val_b(0) , low(0) , high(0){}
	data(ll a , ll v , int b , int c){val_a = a, val_b = v , low = b , high = c;}
};
struct cmp{
	bool operator()(const data &a , const data &b){
		return a.low == b.low ? (a.high == b.high ? a.val < b.val : a.high < b.high) : a.low < b.low;
	}
};
int main(){
	
	int n , q;
	cin>>n>>q;
	set<data , cmp> s;
	while(q--){
		int type;
		cin>>type;
		if(type == 1){
			int l , r , c;
			cin>>l>>r>>c;

		} else if(type == 2){
			int l , r , c;
			cin>>l>>r>>c;

		} else {
			int l , r;
			cin>>l>>r;
		}
	}
	
	return 0;
}