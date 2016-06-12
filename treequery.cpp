#include <bits/stdc++.h>
#include <unistd.h>
#include <ios>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define DEBUG false

#define MOD 1000000007LL
#define MAX_WIDTH 20
#define MASK ((1 << MAX_WIDTH) - 1)

const int N = (1 << 18);
const int M = 5e4 + 5;

vector<int> g[M];
vector<int> a;
bool vis[M];
int in[M], out[M], timer, val[M];

void dfs(int x){
	if (vis[x]) return ;
	vis[x] = true;
	in[x] = ++timer;
	a.pb(x);
	int child = 0;
	for (int v : g[x]){
		if (!vis[v]){
			dfs(v);
			++child;
		}
	}
	if (child){
		a.pb(x);
		out[x] = ++timer;
	}
	else out[x] = in[x];
}

struct Trie{
	Trie *next[2];
	Trie(){
		next[0] = NULL; next[1] = NULL;
	}
};

Trie *get_new_node(){
	Trie *t = new Trie();
	return t;
}

void insert(Trie *trie, int x){
	for (int i = MAX_WIDTH; i >= 0; i--){
		int dir = (x >> i) & 1;
		if (trie->next[dir] == NULL)
			trie->next[dir] = get_new_node();
		
		trie = trie->next[dir];
	}
}

int find(Trie *trie, int x){
	int res = 0;
	for (int i = MAX_WIDTH; i >= 0; i--){
		int dir = (x >> i) & 1;
		if (trie->next[dir] == NULL){
			res |= 1 << i;
			dir = 1 - dir;
		}
		trie = trie->next[dir];
	}
	return res;
}

int flip_bits(int x){
	x ^= MASK;
	return x;
}

class Node{
public:
	Trie *trie;
	Node(){
		trie = get_new_node();
	}

	void dfs_insert(Trie *t, Trie *p){
		for (int i = 0; i < 2; i++){
			if (t->next[i] != NULL){
				if (p->next[i] == NULL)
					p->next[i] = get_new_node();
				dfs_insert(t->next[i], p->next[i]);
			}
		}
	}
	void merge(Node &a, Node &b){
		dfs_insert(a.trie, trie);
		dfs_insert(b.trie, trie);
	}

	int get_max_xor_value(int k){
		k = flip_bits(k);
		int res = find(trie, k);
		res = flip_bits(res);
		return res;
	}
};

Node tree[N];

int init(){
	int n = a.size();
	int ht = (int)ceil(log(n) / log(2.0));
	int sz = 1 << ht;

	for (int i = 0; i < n; i++){
		insert(tree[sz + i].trie, val[a[i]]);
	}
	return sz;
}

void makeTree(int root, int sz){
	if (root < sz){
		int lc = root << 1, rc = lc | 1;
		makeTree(lc, sz);
		makeTree(rc, sz);
		tree[root].merge(tree[lc], tree[rc]);
	}
}

int query(int root, int L, int R, int l, int r, int k){
	if (l <= L && R <= r){
		return tree[root].get_max_xor_value(k);
	}
	int lc = root << 1, rc = lc | 1, mid = (L + R) >> 1;
	int res = 0;
	if (l <= mid) res = max(res, query(lc, L, mid, l, r, k));
	if (r > mid) res = max(res, query(rc, mid + 1, R, l, r, k));
	return res;
}
void process_mem_usage(double& vm_usage, double& resident_set)
{
   using std::ios_base;
   using std::ifstream;
   using std::string;

   vm_usage     = 0.0;
   resident_set = 0.0;

   // 'file' stat seems to give the most reliable results
   //
   ifstream stat_stream("/proc/self/stat",ios_base::in);

   // dummy vars for leading entries in stat that we don't care about
   //
   string pid, comm, state, ppid, pgrp, session, tty_nr;
   string tpgid, flags, minflt, cminflt, majflt, cmajflt;
   string utime, stime, cutime, cstime, priority, nice;
   string O, itrealvalue, starttime;

   // the two fields we want
   //
   unsigned long vsize;
   long rss;

   stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
               >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
               >> utime >> stime >> cutime >> cstime >> priority >> nice
               >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care about the rest

   stat_stream.close();

   long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
   vm_usage     = vsize / 1024.0;
   resident_set = rss * page_size_kb;
}
int main(){
	timer = 0;
	chrono::time_point<chrono::system_clock> startTime = chrono::system_clock::now();
	int n, q, u, v;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);

	for (int i = 0; i < n - 1; i++){
		scanf("%d %d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	int sz = init();
	makeTree(1, sz);

	while (q--){
		int x, y;
		scanf("%d %d", &x, &y);
		int l = in[x];
		int r = out[x];
		int res = query(1, 1, sz, l, r, y);
		// printf("%d\n", res);
	}
	chrono::time_point<chrono::system_clock> endTime = chrono::system_clock::now();
	chrono::duration<double> tt = endTime - startTime;
	printf("Time taken : %f\n", tt.count());
	double vm, rss;
   	process_mem_usage(vm, rss);
   	cout << "VM: " << vm << "; RSS: " << rss << endl;
	return 0;
}