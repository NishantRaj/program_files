/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 02 August 2015 (Sunday) 04:30
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
int main(){
	
	int q;
	cin>>q;
	map<int , int> mp;
	map<int , int> ::iterator it;
	while(q--){
		string s;
		int n;
		cin>>s>>n;
		if(s == "add"){
			mp[n]+=1;
		} else if(s == "del"){
			it = mp.find(n);
			if(it->second == 1)
				mp.erase(it);
			else
				it->second--;
		} else if(s == "cnt"){
			int count=0;
			for(it=mp.begin() ;it!= mp.end() ; it++){
				//cout<<it->first<<endl;
				//cout<<((it->first)&n)<<endl;
				if(((it->first)&n) == it->first)
					count += it->second;
			}
			cout<<count<<endl;
			//print(root);
		}
	}
	return 0;
}