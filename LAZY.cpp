#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define MOD 1000000007
const int N = 444444;
struct Node{
	ll n, sq, lazy;
	int w;
	Node(){
		n = sq = lazy = 0;
		w = 1;
	}
	Node(ll _n, ll _sq, int _w){
		n = _n;
		sq = _sq;
		lazy = 0; w = _w;
	}
	void merge(Node &a, Node &b){
		w = a.w + b.w;
		n = a.n + b.n;
		sq = a.sq + b.sq;
		lazy = 0;
	}
	void split(Node &a, Node &b){
		a.sq += lazy * lazy * (ll)a.w + 2LL * lazy * a.n;
		b.sq += lazy * lazy * (ll)b.w + 2LL * lazy * b.n;
		a.n += lazy * a.w;
		b.n += lazy * b.w;
		a.lazy += lazy;
		b.lazy += lazy;
		lazy = 0;
	}
	void update(ll val){
		lazy += val;
		sq = sq + lazy * lazy * (ll)w + 2LL * lazy * n;
		n += lazy * w;
	}
	void print(char c = '.'){
		printf("%lld %c %lld %c %lld\n", n, c, sq, c, lazy);
	}
};

Node tree[N];

int init(vector<int> a){
	int n = a.size();
	int h = (int)ceil(log((double)n) / log(2.0));
	int sz = 1<<h;
	for (int i = 0; i < n; i++)
		tree[sz + i] = Node(a[i], a[i] * a[i], 1);
	return sz;
}

void makeTree(int root, int sz){
	if (root < sz){
		int lchild = root << 1, rchild = lchild | 1;
		makeTree(lchild, sz);
		makeTree(rchild, sz);
		tree[root].merge(tree[lchild], tree[rchild]);
	}
}

void mergeup(int root){
	root >>= 1;
	while (root){
		int lchild = root << 1, rchild = lchild | 1;
		tree[root].split(tree[lchild], tree[rchild]);
		tree[root].merge(tree[lchild], tree[rchild]);
		root = root >> 1;
	}
}

void point_update(int root, int L, int R, int pos, int val){
	if (root == pos){
		tree[root].update(val);
		return ;
	}
	int lchild = root << 1, rchild = lchild | 1, mid = (L + R) >> 1;
	tree[root].split(tree[lchild], tree[rchild]);
	if (pos <= mid) point_update(lchild, L, mid, pos, val);
	else point_update(rchild, mid + 1, R, pos, val);
	tree[root].merge(tree[lchild], tree[rchild]);
}

Node point_query(int root, int L, int R, int pos){
	if (root == pos)
		return tree[root];
	int lchild = root << 1, rchild = lchild | 1, mid = (L + R) >> 1;
	tree[root].split(tree[lchild], tree[rchild]);
	Node q = Node();
	if (pos <= mid) q = point_query(lchild, L, mid, pos);
	else q = point_query(rchild, mid + 1, R, pos);
	tree[root].merge(tree[lchild], tree[rchild]);
	return q;
}

void range_update(int root, int L, int R, int l, int r, int val){
	if (l <= L && R <= r){
		tree[root].print('_');
		tree[root].update(val);
		tree[root].print('_');
		return;
	}
	int lchild = root << 1, rchild = lchild | 1, mid = (L + R) >> 1;
	tree[root].split(tree[lchild], tree[rchild]);
	if (l <= mid) range_update(lchild, L, mid, l, r, val);
	if (r > mid) range_update(rchild, mid + 1, R, l, r, val);
	tree[root].merge(tree[lchild], tree[rchild]);
}

Node range_query(int root, int L, int R, int l, int r){
	if (l <= L && R <= r){
		return tree[root];
	}
	int lchild = root << 1, rchild = lchild | 1, mid = (L + R) >> 1;
	tree[root].split(tree[lchild], tree[rchild]);
	tree[root].print();
	Node lq = Node(), rq = Node();
	if (l <= mid) lq = range_query(lchild, L, mid, l, r);
	if (r > mid) rq = range_query(rchild, mid + 1, R, l, r);
	tree[root].merge(tree[lchild], tree[rchild]);
	tree[root].print();
	lq.merge(lq, rq);
	return lq;
}
void solve(int test){
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < N; i++)
		tree[i] = Node();
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int sz = init(a);
	makeTree(1, sz);
	for (int qq = 1; qq <= q; qq++){
		int type, l, r, x;
		scanf("%d %d %d", &type, &l, &r);
		if (type == 2){
			Node res = range_query(1, 1, sz, l, r);
			// res.print();
			// res.sq = res.sq + res.n * res.lazy * res.lazy + 2LL * res.lazy * res.n;
			printf("%lld\n", res.sq);
		}
		else{
			scanf("%d", &x);
			range_update(1, 1, sz, l, r, x);
			for (int i = 1; i < sz * 2; i++)
				tree[i].print();
		}
	}
}
int main()
{	
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
		solve(i);
	return 0;
}