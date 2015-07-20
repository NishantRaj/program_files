#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
int inf = 99999999;
int main(){
	int t;
	cin>>t;
	while(t--){
		int m , n , x , y , d;
		cin>>n>>m>>x>>y>>d;
		int arr[200][200];
		for(int i = 1;  i <= n ; i++)
			for(int j = 1 ; j <= m ; j++)
				cin>>arr[i][j];
		queue<pair<int , int > >q;
		int dist[200][200];
		dist[1][1] = 0;

		for(int i = 1 ; i <= 199 ; i++)
			for(int j = 1 ; j <= 199; j++)
				dist[i][j] = inf;

		dist[1][1] = 0;
		q.push(MP(1 , 1));
		int res = 0;
		bool vis[123][123];
		memset(vis, 0, sizeof(vis));
		while(!q.empty()){
			int i = q.front().first;
			int j = q.front().second;
			q.pop();
			if (vis[i][j]) continue;
			vis[i][j] = true;
			if(i+1 <= n ){
				if(abs(arr[i+1][j] - arr[i][j]) <= d){
					q.push(MP(i+1 , j));
					dist[i+1][j] =min(dist[i+1][j], dist[i][j] +1);
				}
			}
			if(i-1 >= 1){
				if(abs(arr[i-1][j] - arr[i][j] ) <= d ){
					q.push(MP(i-1 , j));
					dist[i-1][j] = min(dist[i-1][j] ,dist[i][j] +1);
				}
			}
			if(j-1 >= 1){
				if(abs(arr[i][j-1] - arr[i][j]) <= d ){
					q.push(MP(i , j - 1));
					dist[i][j-1] = min(dist[i][j-1] , dist[i][j] + 1);
				}
			}
			if(j+1 <= m)
			{
				if(abs(arr[i][j+1] - arr[i][j] ) <= d){
					q.push(MP(i , j+1));
					dist[i][j+1] =min(dist[i][j+1] , dist[i][j] +1) ;
				}
			}
		}
		if(dist[x][y] == inf)
			cout<<-1<<endl;
		else
			cout<<max(dist[x][y] - 1 , 0)<<endl;
	}
	return 0;
}