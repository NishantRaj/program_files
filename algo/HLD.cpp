/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 12 December 2015 (Saturday) 22:27
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
vector<int> graph[100];
int subtreeSize[100];
int chainHead[100] , chainPos[100] , chainSize[100] , chainInd[100];
int chainNo = 0;
int dfs(int node){
	if(graph[node].size() == 0)
		return 1;
	int res = 0;
	for(int i = 0 ; i < graph[node].size() ; i++){
		subtreeSize[graph[node][i]] = dfs(graph[node][i]);
		res += subtreeSize[graph[node][i]];
	}
	return res+1;
}
void HLD(int node){
	if(chainHead[node] == -1) chainHead[chainNo] = node;
	chainInd[node] = chainNo;
	chainPos[node] = chainSize[chainNo];
	chainSize[chainNo]++;
	int ind = -1 , sz = 0;
	for(int i = 0 ; i < graph[node].size() ; i++){
		if(sz < subtreeSize[graph[node][i]]){
			sz = subtreeSize[graph[node][i]];
			ind = i;
		}
	}
	if(ind !=-1){
		HLD(graph[node][ind]);
	}
	for(int i = 0 ; i < graph[node].size() ; i++){
		if(ind != i){
			chainNo++;
			HLD(graph[node][i]);
		}
	}
}
int main(){
	
	int n , e;
	cin>>n>>e;
	memset(chainHead, -1 , sizeof chainHead);
	for(int i = 0 ; i < e ; i++){
		int a , b;
		cin>>a>>b;
		graph[a].pb(b);
	}
	int root = 0;
	cin>>root;
	subtreeSize[root] = dfs(root);
	for(int i = 0 ; i <= n ; i++)
		cout<<i<<" -> "<<subtreeSize[i]<<endl;
	return 0;
}