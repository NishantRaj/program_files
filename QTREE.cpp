/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 20 October 2015 (Tuesday) 22:20
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define N 10100
#define MAX 10009
#define LOGMAX 15
int L[MAX] ,p[MAX][LOGMAX];
vector <int> graph[N], costs[N], Index[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int otherEnd[N], subsize[N];
template<class T>
class segmentTree{
public:
	segmentTree(){
		height = 1;
		left_most = 1<<height;
		right_most = (left_most<<1) - 1; 
		tree = new T[right_most];
	}
	segmentTree(int s){ 
		size=s;
		height = ceil(log2(s));
		left_most = 1<<height;
		right_most = (left_most<<1) - 1;
		tree = new T[right_most+9];
	}
	void init(T * arr){
		build(arr);
	}
	void fill_ans(){
		initalize(1,left_most,right_most);
		for(int i = left_most ;i< left_most+size ; i++){
			for(int j=1;j<=26;j++)
				if(tree[i].arr[j]){
					cout<<char(j+96);
					break;
				}
		}
	}
	void Update(int pos , T val){
		point_update(1 , left_most , right_most , left_most+pos , val);
	}
	void Update(int l , int r , T val){
		range_update(1 , left_most , right_most , left_most+l , left_most+r , val);
	}
	T Query(int pos){
		return point_query(1 , left_most , right_most , left_most+pos);
	}
	T Query(int l ,int r){
		return range_query(1 , left_most , right_most , left_most+l , left_most+r);
	}
private:
	T *tree;
	int size , left_most , right_most , height;
	void build(T * arr){
		for(int i = 0 ; i < size ; i++)
			tree[left_most+i] = arr[i];
		initalize(1 , left_most , right_most); 
	}
	void initalize(int root , int left_most , int right_most){
		if(left_most == right_most) return;
		int mid = (left_most + right_most)>>1 , l_child = (root<<1)  , r_child = (root<<1)+1;
		tree[root].split(tree[l_child] , tree[r_child]);
		initalize(l_child , left_most , mid);
		initalize(r_child , mid+1 , right_most);
		tree[root].merge(tree[l_child] , tree[r_child]);
	}
	void point_update(int root , int left_most , int right_most , int pos , T val){
		if(left_most == right_most && root == pos) { tree[root].update(val); return ;}
		int mid = (left_most + right_most)>>1 , l_child = root<<1 , r_child = (root<<1)+1;
		tree[root].split(tree[l_child] , tree[r_child]);
		if(pos <= mid) point_update(l_child , left_most , mid , pos , val);
		else point_update(r_child , mid+1 , right_most , pos , val);
		tree[root].merge(tree[l_child] , tree[r_child]);
	}
	void range_update(int root , int left_most , int right_most , int l , int r , T val){
		if(l <= left_most && r >= right_most){ tree[root].update(val);return;}
		int mid = (left_most + right_most)>>1 , l_child = root<<1 , r_child = (root<<1)+1;
		tree[root].split(tree[l_child] , tree[r_child]);
		if(l <= mid) range_update(l_child , left_most , mid, l , r , val);
		if(r > mid) range_update(r_child , mid+1 , right_most , l , r , val);
		tree[root].merge(tree[l_child] , tree[r_child]);
	}
	T range_query(int root , int left_most ,int right_most ,int l , int r){
		if( l <= left_most && r >= right_most )
			return tree[root];
		int mid = (left_most + right_most)>>1 , l_child = root<<1 , r_child = (root<<1)+1;
		tree[root].split(tree[l_child] , tree[r_child]);
		T l_node  , r_node , temp;
		if(l <= mid) l_node = range_query(l_child , left_most , mid , l , r );
		if(r > mid) r_node = range_query(r_child , mid+1 , right_most , l , r );
		tree[root].merge(tree[l_child] , tree[r_child]);
		temp.merge(l_node , r_node);
		return temp;
	}
	T point_query(int root , int left_most , int right_most , int pos){
		if(left_most == right_most && root == pos) return tree[root];
		int mid = (left_most + right_most)>>1 , l_child = root<<1 , r_child = (root<<1)+1;
		T temp;
		tree[root].split(tree[l_child] , tree[r_child]);
		if(pos <= mid) temp = point_query(l_child , left_most , mid , pos);
		else temp = point_query(r_child , mid+1 , right_most , pos);
		tree[root].merge(tree[l_child] , tree[r_child]);
		return temp;
	}
};
class node{
public:
	int val;
	void merge(node &a , node &b){
		val = max(a.val , b.val);
	}
	void split(node &a , node &b){
	}
	void update(node &a){
		val = a.val;
	}
	node(){
		val = -1;
	}
	node(int a){ 
		val = a;
	}
};
void lcaPrecomputation(){
	for(int j = 1 ; (1 << j) <= MAX	 ; j++){
		for(int i = 0 ; i < MAX ; i++)
			if(p[i][j-1] != -1)
				p[i][j] = p[p[i][j-1]][j-1];
	}
}
int lca(int u , int v){
	if(L[u] < L[v])
		swap(u , v);
	// cout<<L[u]<<" "<<L[v]<<endl;
	int log_u = floor(log(L[u]));
	// cout<<log_u<<endl;
	for(int i = log_u ; i>=0 ; i--)
		if(L[u] - (1<<i) >= L[v]){
			u = p[u][i];
			// cout<<u<<endl;
		}
	// cout<<u<<" "<<v<<endl;
	if(u == v)
		return u;
	for(int i = log_u ; i>=0 ; i --)
		if(p[u][i] != -1 && p[u][i] != p[v][i])
			u = p[u][i] , v = p[v][i];
	// cout<<"par "<<u<<endl;
	return p[u][0];
}
void dfs(int curNode , int prev , int depth){
	p[curNode][0] = prev;
	L[curNode] = depth;
	subsize[curNode] = 1;
	for(int i = 0 ; i < graph[curNode].size() ; i++){
		if(graph[curNode][i] != prev){
			otherEnd[Index[curNode][i]] = graph[curNode][i];
			dfs(graph[curNode][i] , curNode , depth + 1);
			subsize[curNode] += subsize[graph[curNode][i]];
		}
	}
}
void HLD(int curNode , int cost , int prev){
	if(chainHead[chainNo] == -1) chainHead[chainNo] = curNode;
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr;
	baseArray[ptr++] = cost;
	int sc = -1 , max_cost ;
	for(int i = 0 ; i < graph[curNode].size() ; i++){
		if(graph[curNode][i] != prev){
			if(sc == -1 || subsize[sc] < subsize[graph[curNode][i]]){
				sc = graph[curNode][i];
				max_cost = costs[curNode][i];
			}
		}
	}
	if(sc != -1){
		HLD(sc , max_cost , curNode);
	}
	for(int i = 0 ; i < graph[curNode].size() ; i++){
		if(graph[curNode][i] != prev && graph[curNode][i] != sc){
			chainNo++;
			HLD(graph[curNode][i] , costs[curNode][i] , curNode);
		}
	}
}
int query_up(int u , int v , segmentTree<node> &s){
	if(u == v) return 0;
	int uchain, vchain = chainInd[v] , ans = -1;
	while(true){
		uchain = chainInd[u];
		// cout<<uchain<<" "<<vchain<<" "<<u<<" "<<v<<endl;
		if(uchain == vchain){
			if(u == v) break;
			node temp = s.Query(posInBase[v], posInBase[u]);
			if(temp.val > ans){
				ans = temp.val;
			}
			break;
		}
		node temp = s.Query(posInBase[chainHead[uchain]], posInBase[u]+1);
		if(temp.val > ans) ans = temp.val;
		u = chainHead[uchain];
		// cout<<"l "<<u<<endl;
		u = p[u][0];
		// cout<<"r "<<u<<endl;
	}
	return ans;
}
int query(int u , int v , segmentTree<node> &s){
	int LCA = lca(u , v);
	// cout<<"LCA -> "<<LCA<<endl;
	int ans = query_up(u, LCA , s);
	// cout<<"1-> "<<ans<<endl;
	ans = max(ans , query_up(v , LCA , s));
	// cout<<"2-> "<<ans<<endl;
	//printf("%d\n", ans);
	return ans;
}
int update(int i , int val , segmentTree<node> &s){
	int u = otherEnd[i];
	//cout<<"base pos  "<<u<<" "<<posInBase[u]<<endl;
	s.Update(posInBase[u]-1 , val);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ptr = 0;
		int n;
		scanf("%d",&n);
		for(int i = 0 ; i < n ; i++){
			graph[i].clear();
			costs[i].clear();
			Index[i].clear();
			chainHead[i] = -1;
			for(int j = 0 ; j < LOGMAX ; j++) p[i][j] = -1;
		}
		int u , v , cost;
		for(int i = 1 ; i < n ; i++){
			scanf("%d%d%d", &u , &v , &cost);
			graph[u].pb(v);
			costs[u].pb(cost);
			Index[u].pb(i-1);
			graph[v].pb(u);
			costs[v].pb(cost);
			Index[v].pb(i-1);
		}
		chainNo = 0;
		dfs(1 , -1 , 0);
		HLD(1 , -1 , -1);
		lcaPrecomputation();
		segmentTree<node> s(n-1);
		node st[n+9];
		for(int i = 0 ; i < n ; i++){
			st[i] = node(baseArray[i]);
		}
		s.init(st);
		char qur[10];
		// for(int i = 0 ; i <= n ;i++)
		// 	cout<<i<<" -> "<<posInBase[i]<<endl;
		// cout<<endl;
		// for(int i = 0 ; i <= n ; i++)
		// 	cout<<i<<" -> "<<otherEnd[i]<<endl;
		// for(int i = 0 ; i <= n ; i++)
		// 	cout<<i<<" "<<posInBase[i]<<" -> "<<baseArray[i]<<" "<<chainHead[i]<<endl;
		while(1){
			scanf("%s",qur);
			if(qur[0] == 'D')
				break;
			if(qur[0] == 'Q'){
				int x , y;
				scanf("%d%d",&x , &y);
				printf("%d\n" , query(x , y , s));
			} else if(qur[0] == 'C'){
				int x , y , sv;
				scanf("%d%d",&x,&y);
				update(x-1 , y , s);
			}
		}
	}
	return 0;
}