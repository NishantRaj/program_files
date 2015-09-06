/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 23 August 2015 (Sunday) 13:10
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int s , n , m;
		cin>>s>>n>>m;
		int arr[109][109];
		for(int i = 1 ;i <=100 ; i++){
			for(int j = 1 ; j <= 100 ; j++)
				if((i+j)&1)
					arr[i][j] = 1;
				else
					arr[i][j] = 0;
		}
		char moves[2009];
		for(int i = 0 ; i < m ; i++){
			int s;
			char c;
			cin>>s>>c;
			moves[s] = c;
		}
		queue<pair<int , int> > q;
		char dir = 'R' , prev = 'U';
		for(int i = 1 ; i<= m ;i++){
			if(dir == 'R' && prev == 'R'){
				prev
				j = (j%m) + 1;
			}
			if(dir == 'L' && prev == 'L')
		}
	}
	
	return 0;
}