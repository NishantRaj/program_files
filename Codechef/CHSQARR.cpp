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
pii M[MAX][MAX][LOG_MAX][LOG_MAX];
inline pii GetMaximum(pii a , pii b , pii c , pii d){
	int mi = max(P[a.first][a.second] , max(P[b.first][b.second] , max(P[c.first][c.second] , P[d.first][d.second])));
	if(mi == P[a.first][a.second]) return a;
	else if(mi == P[b.first][b.second]) return b;
	else if(mi == P[c.first][c.second]) return c;
	else return d;
}
void PreProcess(int n , int m){
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			M[i][j][0][0] = mp(i, j);


	for(int i = 0 ; (1<<i) <= n ; i++){
		for(int j =0 ; (1<<j) <= m ; j++){
			for(int x = 0 ; x + (1<<i) -1 < n ; x++){
				for(int y = 0 ; y + (1<<j) - 1 < m ; y++){
					if( i == 0 && j == 0){
						M[x][y][i][j] = mp(x , y);
					} else if(i == 0){
						if( P[M[x][y][0][j-1].first][M[x][y][0][j-1].second] > P[M[x][y+(1<<(j-1))][0][j-1].first][M[x][y+(1<<(j-1))][0][j-1].second])
							M[x][y][i][j] = M[x][y][0][j-1];
						else
							M[x][y][i][j] = M[x][y+(1<<(j-1))][0][j-1];
					} else if(j==0){
						if( P[M[x][y][i-1][0].first][M[x][y][i-1][0].second] > P[M[x+ (1<<(i-1))][y][i-1][0].first][M[x+ (1<<(i-1))][y][i-1][0].second])
							M[x][y][i][j] = M[x][y][i-1][0];
						else
							M[x][y][i][j] = M[x+ (1<<(i-1))][y][i-1][0];
					} else{
						M[x][y][i][j] = GetMaximum(M[x][y][i-1][j-1], M[x + (1<<(i-1))][y][i-1][j-1], M[x][y+(1<<(j-1))][i-1][j-1], M[x + (1<<(i-1))][y+(1<<(j-1))][i-1][j-1]);
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
	pii ans = GetMaximum(M[x][y][k][l], M[x1 - (1<<k) + 1][y][k][l], M[x][y1 - (1<<l) + 1][k][l], M[x1 - (1<<k) + 1][y1 - (1<<l) + 1][k][l]);
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