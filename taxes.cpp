// https://github.com/swapnil96/Online-Judge-Contest/tree/master/HC_June_circuit

/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 21 June 2016 (Tuesday) 09:20
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int , int>
int weight[509][509];
int main(){
	int n, m, k;
	scanf("%d%d%d",&n, &m, &k);
	for(int i = 1 ; i<= n ; i++)
		for(int j = 1 ; j<= n ; j++)
			weight[i][j] = INT_MIN;
	vector<pii > graph[n+9];
	for(int i = 0 ; i < m ; i++){
		int u , v , c;
		scanf("%d%d%d",&u, &v, &c);
		graph[u].pb(mp(v , c));
		graph[v].pb(mp(u , c));
		weight[u][v] = weight[v][u] = c;
	}
	map<pii , int , greater<pii > > cost;
	map<int , int> ans;
	for(int i = 1 ; i<= n ; i++){
		int sum = 0;
		for(auto x:graph[i]){
			sum += x.second;
		}
		weight[i][0] = sum;
		cost.insert(mp(mp(sum , i) , i));
	}

	for(int i = 0 ; i < k ; i++){
		auto it = cost.begin();
		if(it->first.first <= 0)
			break;
		int ind = it->first.second;
		ans[ind] = 1;
		cost.erase(it);
		// cout<<"ans -> "<<ind<<endl;
		for(auto x: graph[ind]){
			if(ans.find(x.first) != ans.end())
				continue;
			// cout<<x.first<<" " <<x.second<<endl;
			cost.erase(mp(weight[x.first][0] , x.first));
			weight[x.first][0] -= x.second;
			cost.insert(mp(mp(weight[x.first][0] , x.first) , x.first));
		}
		// for(auto it:cost)
		// 	cout<<"map  -> "<<it.first.second<<" "<<it.first.first<<endl;
		// cout<<"_______________________________________________________________________________"<<endl;
	}
	printf("%d\n", (int)ans.size());
	for(auto it:ans)
		printf("%d ", it.first);
	return 0;
}