#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
const int N = 123456;
unordered_map<ll, ll> m;
vector<int> g[N], w[N];
ll Hash(int x, int y){
	ll g = (ll)x *  1000000000LL + (ll)y;
	return g;
}
ll dist[N];
bool vis[N];
void dfs(int x){
	vis[x] = true;
	for (int i = 0; i<g[x].size(); i++){
		if (!vis[g[x][i]]){
			dist[g[x][i]] = dist[x] + w[x][i];
			dfs(g[x][i]);
		}
	}
}
int main(){
	
	int n, t;
	scanf("%d %d", &n, &t);

	for (int i = 0; i<n - 1; i++){
		int u, v, ww;
		scanf("%d %d %d", &u, &v, &ww);
		g[u].pb(v); w[u].pb(ww);
		g[v].pb(u); w[v].pb(ww);
	}
	for (int i = 0; i<t; i++){
		int k;
		scanf("%d", &k);
		vector<int> node(k);
		for (int j = 0; j<k; j++)
			scanf("%d", &node[j]);

		ll res = 0;
		for (int j = 0; j<k; j++){
			bool ok = false;
			for (int l = j + 1; l < k; l++){
				if (m.find(Hash(node[j], node[l])) != m.end()){
					res += m.find(Hash(node[j], node[l]))->second;
				}
				else if (!ok){
					memset(vis, 0, sizeof(vis));
					memset(dist, 0, sizeof(dist));
					dfs(node[j]);
					for (int d = 1; d <= n; d++){ishant
						nishant
						nkjsdnksjdlksdjlfdskjfljskl    dssda
						m.insert(mp(Hash(node[j], d), dist[d]));
						m.insert(mp(Hash(d, node[j]), dist[d]));
					}
					ok = true;
					res += m.find(Hash(node[j], node[l]))->second;
				}
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}