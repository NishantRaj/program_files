/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 05 June 2016 (Sunday) 09:28
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1009
#define LOG_MAX 10
#define pii pair<int , int>
#define mp make_pair
int sum[MAX][MAX];
int P[MAX][MAX];
pii M[LOG_MAX][LOG_MAX][MAX][MAX];
inline pii GetMaximum(pii &a , pii &b , pii &c , pii &d){
	int mi = max(P[a.first][a.second] , max(P[b.first][b.second] , max(P[c.first][c.second] , P[d.first][d.second])));
	if(mi == P[a.first][a.second]) return a;
	else if(mi == P[b.first][b.second]) return b;
	else if(mi == P[c.first][c.second]) return c;
	else return d;
}
void PreProcess(int n , int m){

	for(int i = 0 ; (1<<i) <= n ; i++){
		for(int j =0 ; (1<<j) <= m ; j++){
			for(int x = 0 ; x + (1<<i) -1 < n ; x++){
				for(int y = 0 ; y + (1<<j) - 1 < m ; y++){
					if( i == 0 && j == 0){
						M[i][j][x][y] = mp(x , y);
					} else if(i == 0){
						if( P[M[0][j-1][x][y].first][M[0][j-1][x][y].second] > P[M[0][j-1][x][y+(1<<(j-1))].first][M[0][j-1][x][y+(1<<(j-1))].second])
							M[i][j][x][y] = M[0][j-1][x][y];
						else
							M[i][j][x][y] = M[0][j-1][x][y+(1<<(j-1))];
					} else if(j==0){
						if( P[M[i-1][0][x][y].first][M[i-1][0][x][y].second] > P[M[i-1][0][x+ (1<<(i-1))][y].first][M[i-1][0][x+ (1<<(i-1))][y].second])
							M[i][j][x][y] = M[i-1][0][x][y];
						else
							M[i][j][x][y] = M[i-1][0][x+ (1<<(i-1))][y];
					} else{
						M[i][j][x][y] = GetMaximum(M[i-1][j-1][x][y], M[i-1][j-1][x + (1<<(i-1))][y] , 
							M[i-1][j-1][x][y+(1<<(j-1))] , M[i-1][j-1][x + (1<<(i-1))][y+(1<<(j-1))]);
					}
				}
			}
		}
	}
}
int QueryMaximum(int x , int y , int x1 , int y1){
	int k  = x1 - x , l = y1 - y;
	k = 31-__builtin_clz(k+1);
	l = 31-__builtin_clz(l+1);
	// cout<<k<<" "<<l<<endl;
	pii ans = GetMaximum(M[k][l][x][y] , M[k][l][x1 - (1<<k) + 1][y] , 
		M[k][l][x][y1 - (1<<l) + 1] , M[k][l][x1 - (1<<k) + 1][y1 - (1<<l) + 1]);
	// cout<<ans.first<<"  "<<ans.second<<endl;
	return P[ans.first][ans.second];
}

inline void scanint(int &a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    a=0;
    while (c>33)
    {
        a=a*10+c-'0';
        c=getchar_unlocked();
    }
}

inline void calcSum(int n , int m){
	for(int i = 1 ; i<= n ; i++)
		for(int j = 1; j<= m ; j++)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] + P[i-1][j-1] - sum[i-1][j-1];
}
inline int getSum(int x , int y , int x1 , int y1){
	return sum[x1][y1] - sum[x1][y-1] - sum[x-1][y1] + sum[x-1][y-1];
}
int main(){
	int n , m;
	scanint(n);
	scanint(m);
	for(int i = 1 ; i<= n ; i++)
		for(int j = 1 ; j<= m ; j++)
			scanint(P[i-1][j-1]);
	PreProcess(n , m);
	calcSum(n , m);
	int q;
	scanint(q);
	while(q--){
		int xSize , ySize;
		scanint(xSize);
		scanint(ySize);
		if(xSize == 1 && ySize == 1){
			printf("0\n");
			continue;
		}
		int ans = INT_MAX;
		for(int i = xSize ; i<= n ; i++){
			for(int j = ySize ; j<= m ; j++){
				int x = i - xSize + 1;
				int y = j - ySize + 1;
				int sum = getSum(x , y , i , j);
				int mx = QueryMaximum(x-1, y-1, i-1, j-1);
				int mx_sum = mx*xSize*ySize;
				int rs = mx_sum - sum;
				if(rs < ans)
					ans = rs;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}