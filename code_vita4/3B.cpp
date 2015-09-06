/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 27 August 2015 (Thursday) 17:51
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
int x_c[8] = {-1 , -1 , -1 , 0 , 0 , 1, 1 , 1};
int y_c[8] = {-1 , 0 , 1 , -1 , 1 , -1, 0 , 1};
int main(){
	while(1){
		int n , m;
		scanf("%d",&n);
		if(n == -1)
			return 0;
		scanf("%d ", &m);
		char arr[n+9][m+9];
		pii start , end;
		for(int i = 0 ; i < n ; i++){
			string s;
			fflush(stdin);
			getline(cin , s);
			fflush(stdin);
			istringstream iss(s);
			char c;
			int j = 0;
			while(iss >> c){
				arr[i][j] = c;
				if(c == 's')
					start = mp(i , j);
				if(c == 'd')
					end = mp(i , j);
				j++;
			}
		}
		int dist[n+9][m+9] , mark[n+9][m+9];
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ;  j < m ; j++)
				dist[i][j] = INT_MAX;
		}
		memset(mark , 0 , sizeof mark);
		queue<pii > q;
		q.push(start);
		map<pii , pii > path;
		mark[start.first][start.second] = 1;
		dist[start.first][start.second] = 0;
		path[start] = mp(-1 , -1);
		while(!q.empty()){
			pii x = q.front();
			q.pop();
			if(arr[x.first][x.second] == 'd'){
				break;
			}
			for(int i = 0 ; i < 8 ; i++){
				int p  = x.first + x_c[i] , qq = x.second + y_c[i];
				if(p >=0 && p < n && qq >=0 && qq < m && arr[p][qq] != 'w' &&  !mark[p][qq] && (dist[p][qq] > dist[x.first][x.second] + 1)){
					q.push(mp(p , qq));
					dist[p][qq] = dist[x.first][x.second] + 1;
					path[mp(p , qq)] = mp(x.first , x.second);
					mark[p][qq] = 1;
				}
			}
		}
		arr[start.first][start.second] = 'a';
		end = path[end];
		while(path[end] != mp(-1 , -1)){
			arr[end.first][end.second] = 'a';
			end = path[end];
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}