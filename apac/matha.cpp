/*
  Beautiful Codes are MUCH better than 'Shorter' ones !
user  : triveni
date  : 22/08/2015
time  : 17:57:22
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           std::make_pair(a,b)
#define      pb(a)             std::push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second

typedef long long LL;
LL MOD = 1000000007;
LL INF = MOD * MOD;

LL DP[101][101];

struct edge{
	int u, v, c;
};

void solve(){
	int n, m;
	cin >> n >> m;
	vector<edge> E(m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			DP[i][j] = (i != j ? INF : 0);


	rep(i, m){
		cin >> E[i].u >> E[i].v >> E[i].c;
		DP[E[i].u][E[i].v] = DP[E[i].v][E[i].u] = E[i].c;
	}

	rep(k, n){
		rep(i, n)
		rep(j, n)
		DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
	}
	rep(k, m){
		bool flag = 0;
		int u = E[k].u, v = E[k].v, c =E[k].c;
		rep(i, n)
		rep(j, n)
		{
			if(i!=j){
				if(DP[i][u] + c + DP[v][j] <= DP[i][j]) flag = true;
			}
		}
		if(!flag) cout << k <<endl;
	}
}

int main()
{
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc){
		cout << "Case #" << tc << ":\n";
		solve();
	}
	return 0;
}
