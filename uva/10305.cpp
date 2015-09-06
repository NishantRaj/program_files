/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 03 September 2015 (Thursday) 00:10
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
vector<int>ans;
vector<int> graph[109];
void dfs(int node , int check[]){
	check[node] = 1;
	for(int i = 0 ; i < graph[node].size() ; i++){
		if(!check[graph[node][i]])
			dfs(graph[node][i] , check);
	}
	ans.pb(node);
}
int main(){
	
	int n , m;
	while(true){
		cin>>n>>m;
		ans.clear();
		if(n == 0 && m == 0)
			return 0;
		for(int i = 0 ; i <= n ; i++)
			graph[i].clear();
		for(int i = 0 ; i < m ; i++){
			int p , q;
			cin>>p>>q;
			graph[p].pb(q);
		}
		int check[n+9];
		memset(check , 0 , sizeof check);
		for(int i = 1 ; i<= n ; i++){
			if(!check[i])
				dfs(i , check);
		}
		reverse(ans.begin() , ans.end());
		for(auto it:ans)
			cout<<it<<" ";
		cout<<endl;
	}
	
	return 0;
}