#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define LOGMAX 20
int L[MAX] , tree[MAX] , p[MAX][LOGMAX];
void lcaPrecomputation(){

	memset(p , -1 , sizeof p);
	for(int i = 0 ; i < MAX ; i++)
		p[i][0] = tree[i];

	for(int j = 1 ; (1 << j) <= MAX	 ; j++){
		for(int i = 0 ; i < MAX ; i++)
			if(p[i][j-1] != -1)
				p[i][j] = p[p[i][j-1]][j-1];
	}
}
int lca(int u , int v){

	if(L[u] < L[v])
		swap(u , v);

	int log_u = floor(log(L[u]);

	for(int i = log_u ; i>=0 ; i--)
		if(L[u] - (1<<i) >= L[v])
			u = p[u][i];

	if(u == v)
		return u;

	for(int i = log_u ; i>=0 ; i --)
		if(p[u][i] != -1 && p[u][i] != p[v][i])
			u = p[u][i] , v = p[v][i];

	return tree[u];
}
int main(){

	int node;
	cin>>node;
	int edge;
	cin>>edge;
	for(int i = 0 ; i < edge ; i++){
		int parent , child;
		cin>>parent>>child;
		tree[child] = parent;
		L[child] = L[parent] + 1;
	}
	lcaPrecomputation();
	/*for(int i = 0; i <= node ; i++){
		cout<<i<<" ";
		for(int j = 0 ; (1<<j) <= node ; j++){
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}*/

	int q;
	cin>>q;
	while(q--){

		int i , j ;
		cin>>i>>j;
		cout<<lca(i , j)<<endl;
	}
	return 0;
}