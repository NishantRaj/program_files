#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int , int >
#define node pair<pair<int , int > ,  int>
int n;
struct cmp{
	bool operator()(const node &a , const node &b){
		return a.second > b.second;
	}
};
bool valid(int x , int y){
	if(x>= 0 && x < n && y>=0 && y<n)
		return true;
	return false;
}
const int px[4] = {1 , -1 , 0 , 0};
const int py[4] = {0 , 0 , -1 , 1};
int main(){
	cin>>n;
	int arr[n+9][n+9];
	pii source;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++){
			cin>>arr[i][j];
			if(arr[i][j] == -2)
				source = mp(i , j);
		}
	ll dist[109][109];
	int check[109][109];
	memset(check , 0 , sizeof check);
	for(int i = 0 ; i <= 100 ; i++)
		for(int j = 0 ; j <= 100 ; j++)
			dist[i][j] = INT_MAX;
	dist[source.first][source.second] = 0;
	priority_queue<node , vector<node> , cmp> pq;
	pq.push(mp(source , 0));
	while(!pq.empty()){
		int x = pq.top().first.first;
		int y = pq.top().first.second;
		int d = pq.top().second;
		pq.pop();
		for(int k = 0 ; k < 4 ; k++){
			int i = x + px[k] , j = y + py[k];
			if(valid(i , j) && (check[i][j] == 0)){
				dist[i][j] = min(dist[i][j] , dist[x][y] + (arr[i][j] ==-1 ? INT_MAX : arr[i][j]));
				pq.push(mp(mp(i , j ) , dist[i][j]));
				check[i][j] = 1;
			}
		}
		check[x][y] = 1;
	}
	ll  total = 0;
	memset(check , 0 , sizeof check);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(!check[i][j] && arr[i][j] == -1){
				ll res = INT_MAX;
				int save_x , save_y;
				queue<pii> qu;
				qu.push(mp(i , j));
				while(!qu.empty()){
					int x = qu.front().first;
					int y = qu.front().second;
					qu.pop();
					for(int k = 0 ; k < 4 ; k++){
						int p = x + px[k] , q = y + py[k];
						if(valid(p , q))
							res = min(dist[p][q] , res);
						if(valid(p , q) && (!check[p][q]) && arr[p][q] == -1){
							qu.push(mp(p , q)) ;
							check[p][q] = 1;
							}
					}
					check[x][y] = 1;
				}
				total += res;
			}
		}
	}
	cout<<total<<endl;
	return 0;
}
