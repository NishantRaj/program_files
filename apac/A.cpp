/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 23 August 2015 (Sunday) 10:36
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	vector<ull> p_2;
	p_2.pb(1);
	p_2.pb(2);
	ull x = 2;
	for(int i = 2 ; i<= 64 ; i++){
		x = x*2;
		p_2.pb(x);
		//cout<<x<<endl;
	}
	int t;
	cin>>t;
	for(int test = 1 ; test<= t ; test++){
		ull k;
		cin>>k;
		string s = "0001";
		if(k <=3 ){
			cout<<"Case #"<<test<<": "<<s[k]<<endl;
			continue;
		}
		int pos = lower_bound(p_2.begin() , p_2.end() , k) - p_2.begin();
		if(p_2[pos] == k){
			cout<<"Case #"<<test<<": 0"<<endl;
			continue;
		}
		int count = 0 ,flag = 1;
		while(k>=3){
			//cout<<k<<endl;
			int pos = lower_bound(p_2.begin() , p_2.end() , k) - p_2.begin();
			//cout<<p_2[pos-1]<<" "<<k<<" "<<2*near - k<<endl;
			if(p_2[pos] == k){
				if(count&1)
					cout<<"Case #"<<test<<": "<<1<<endl;
				else
					cout<<"Case #"<<test<<": "<<0<<endl;
				flag = 0;
				break;
			}
			count++;
			ull near = p_2[pos-1];
			k = 2*near - k;
		}
		//cout<<k<<" "<<count<<endl;
		if(flag){
			if(count&1){
				if(s[k] == '0'){
					cout<<"Case #"<<test<<": 1"<<endl;
				} else{
					cout<<"Case #"<<test<<": 0"<<endl;
				}
			} else{
				if(s[k] == '1'){
					cout<<"Case #"<<test<<": 1"<<endl;
				} else{
					cout<<"Case #"<<test<<": 0"<<endl;
				}
			}
		}
	}
	return 0;
}