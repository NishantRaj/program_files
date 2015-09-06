/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 23 August 2015 (Sunday) 11:20
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define MP make_pair
#define mod 1000000009

int main(){
	
	int t;
	cin>>t;
	for(int test = 1 ; test<= t ; test++){
		int n , m;
		cin>>n>>m;
		ll arr[109][109];
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				arr[i][j] = INT_MAX;
		int count[109][109];
		memset(count , 0 , sizeof count);
		map<pair<int , int> , int> mp;
		for(int i = 0 ; i < m ; i++){
			int x , y , c;
			cin>>x>>y>>c;
			mp[MP(x , y)] = i;
			if(c < arr[x][y]){
				arr[x][y] = c;
			}
			if(c < arr[y][x]){
				arr[y][x] = c;
			}
		}
		for(int k = 0 ; k < n ; k++){
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < n ; j++){
					ll save=arr[i][j];
					arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);
					if(save != INT_MAX && save > arr[i][j]){
						auto it = mp.find(MP(i , j));
						if(it != mp.end())
							mp.erase(it);
					}
				}
			}
		}
		cout<<"Case #"<<test<<": "<<endl;
		for(auto it:mp)
			cout<<it.second<<" ";
		cout<<endl;
	}
	
	return 0;
}