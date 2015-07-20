#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int main(){
	int t;
	cin>>t;
	while(t--){
		int n , m , x , y , d;
		cin>>n>>m>>x>>y>>d;
		int arr[n+9][m+9];
		for(int i = 0;  i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				cin>>arr[i][j];
		int check[n+9][m+9];
		memset(check , 0 ,sizeof check);
		queue<pair<int , pair<int , int > > >q;
		q.push(mp(0 , mp(0 , 0)));
		int res = 0;
		int px[4] = {1 , -1 , 0 , 0};
		int py[4] = { 0 , 0 , -1 , 1};
		int flag = 0;
		while(!q.empty()){
			int i , j , dist;
			i = q.front().second.first;
			j = q.front().second.second;
			dist = q.front().first;
			if(i == x -1 && j == y-1){
				flag = 1;
				res = dist;
				break;
			}
			for(int k = 0 ; k < 4 ; k++){
				int u , v;
				u = i + px[k];
				v = j + py[k];
				if(u >= 0 && u < n && v >= 0 && v < m && !check[u][v] && (arr[u][v] - arr[i][j]) <= d )
					q.push(mp(dist + 1 , mp(u , v)));
			}
			check[i][j] = 1;
			q.pop();
		}
		if(flag == 1)
			cout<<max(0 ,res - 1)<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}