/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 21 July 2015 (Tuesday) 14:50
===================================================*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	string a , b , s="";
	cin>>a>>b;
	int flag = 0;
	for(int i = 0 ; i < a.size() ; i++){
		s = s + a[i];
		if(a[i]+1 < b[i]){
			flag = 1;
			s[i] = a[i]+1;
		}
	}
	if(flag){
		cout<<s<<endl;
	} else 
		cout<<"No such string\n";
	return 0;
}