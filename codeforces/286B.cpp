#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n , m , a , b , c;
	cin>>n>>m;
	vector<pair<int , int > > v[n+9];
	for(int i = 0 ; i < m ; i++){
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b , c));
		v[b].push_back(make_pair(a , c));
	}
	int q;
	cin>>q;
	int mark[n+9];
	while(q--){
		int u , vv;
		cin>>u>>vv;
		int count = 0;
		for(int i = 1 ; i<= m ; i++){
			memset(mark , 0 , sizeof mark);
			queue<int > que;
			que.push(u);
			while(!que.empty()){
				int x = que.front();
				if(x==vv){
					count++;
					break;
				}
				if(mark[x] == 0){
					for(int j = 0 ; j < v[x].size() ; j++){
						if(v[x][j].second == i){
							que.push(v[x][j].first) ; 
						}
					}
				}
				mark[x] = 1;
				que.pop();
			}
		}
		cout<<count<<endl;
	}
	return 0;
}