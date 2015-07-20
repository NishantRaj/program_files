#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int visited[MAX];
vector<int> v[MAX] , visited_sequence , level;
void euler_tour(int node){
	if(!visited[node]){
		visited[node] = 1;
		cout<<node<<" ";
		for(int i = 0 ; i < v[node].size() ; i++){
			euler_tour(v[node][i]);
			cout<<node<<" ";
		}
	}
}
int main(){

	int n;
	cin>>n;
	int edge;
	cin>>edge;
	for(int i = 0 ; i < edge ; i ++){

		int p , q;
		cin>>p>>q;
		v[p].push_back(q);
	}
	euler_tour(1);
	return 0;
}