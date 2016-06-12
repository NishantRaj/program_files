/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 05 June 2016 (Sunday) 19:26
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1009
#define LOG_MAX 10
int P[MAX][MAX]; // contains matrix values
pair<int , int> M[MAX][MAX][LOG_MAX][LOG_MAX]; // hold the value of sparse matrix
inline pair<int , int> GetMinimum(pair<int , int> a , pair<int , int> b , pair<int , int> c , pair<int , int> d){
	// calculate the minimum value
	int mi = min(P[a.first][a.second] , min(P[b.first][b.second] , min(P[c.first][c.second] , P[d.first][d.second])));

	// check which 
	if(mi == P[a.first][a.second]) return a;
	else if(mi == P[b.first][b.second]) return b;
	else if(mi == P[c.first][c.second]) return c;
	else return d;
}
void PreProcess(int n , int m){ // calculation of sparse table

	for(int i = 0 ; (1<<i) <= n ; i++){
		for(int j =0 ; (1<<j) <= m ; j++){
			for(int x = 0 ; x + (1<<i) -1 < n ; x++){
				for(int y = 0 ; y + (1<<j) - 1 < m ; y++){
					// if sub matrix is of size one.
					if( i == 0 && j == 0){
						M[x][y][i][j] = make_pair(x , y);
					}
					// for one dimension that is row
					else if(i == 0){
						if( P[M[x][y][0][j-1].first][M[x][y][0][j-1].second] > P[M[x][y+(1<<(j-1))][0][j-1].first][M[x][y+(1<<(j-1))][0][j-1].second])
							M[x][y][i][j] = M[x][y][0][j-1];
						else
							M[x][y][i][j] = M[x][y+(1<<(j-1))][0][j-1];
					} 
					// for ont dimension that is column
					else if(j==0){
						if( P[M[x][y][i-1][0].first][M[x][y][i-1][0].second] > P[M[x+ (1<<(i-1))][y][i-1][0].first][M[x+ (1<<(i-1))][y][i-1][0].second])
							M[x][y][i][j] = M[x][y][i-1][0];
						else
							M[x][y][i][j] = M[x+ (1<<(i-1))][y][i-1][0];
					} 

					else{
						M[x][y][i][j] = GetMinimum(M[x][y][i-1][j-1] , M[x + (1<<(i-1))][y][i-1][j-1] , 
							M[x][y+(1<<(j-1))][i-1][j-1] , M[x + (1<<(i-1))][y+(1<<(j-1))][i-1][j-1]);
					}
				}
			}
		}
	}
}
int QueryMinimum(int x , int y , int x1 , int y1){
	int k  = log(x1 - x + 1), l = log(y1 - y + 1);
	pair<int , int> ans = GetMinimum(M[x][y][k][l] , M[x1 - (1<<k) + 1][y][k][l] , 
		M[x][y1 - (1<<l) + 1][k][l] , M[x1 - (1<<k) + 1][y1 - (1<<l) + 1][k][l]);
	return P[ans.first][ans.second];
}
int main(){
	int n , m;
	cin>>n>>m; // dimention of matrix input
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++)
			cin>>P[i][j]; // matrix input
	}
	PreProcess(n , m); // calculate sparse table
	int q;
	cin>>q;
	while(q--){
		int x, y , x1 , y1;
		cin>>x>>y>>x1>>y1;
		cout<<QueryMinimum(x , y , x1 , y1)<<endl;
	}
	return 0;
}