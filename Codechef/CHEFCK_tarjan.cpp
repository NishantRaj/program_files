#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 10000009;
const int MAXN = 10000009;
vector<int> g, query[MAXN] ;
int dsu[MAXN], ancestor[MAXN];
bool u[MAXN];
ll ans , ans1 = 1;
struct node
{
	int left, right, index;
	node(){
		left = right = -1;
		index = -1;
	}
};
node tree[N];
int build(vector <int> a)
{
	node root = node();
	stack <node> s;
	for (int i = 0; i<a.size(); i++){
		node last = node();
		while (!s.empty() && a[s.top().index] > a[i]){
			last = s.top();
			s.pop();
		}
		
		tree[i].index = i;
		tree[i].left = last.index;

		if (s.empty()) root = tree[i];
		else tree[s.top().index].right = tree[i].index;

		
		s.push(tree[i]);
	}
	return root.index;
}
int dsu_get (int v) {
	return v == dsu[v] ? v : dsu[v] = dsu_get (dsu[v]);
}
 
void dsu_unite (int a, int b, int new_ancestor) {
	a = dsu_get (a),  b = dsu_get (b);
	if (rand() & 1)  swap (a, b);
	dsu[a] = b,  ancestor[b] = new_ancestor;
}
map<pair<int , int >,ll> qr_mp;
void dfs (int v) {
	dsu[v] = v,  ancestor[v] = v;
	u[v] = true;
	// for (size_t i=0; i<g[v].size(); ++i)
	if(tree[v].left!= -1)
		if (!u[tree[v].left]) {
			dfs (tree[v].left );
			dsu_unite (v, tree[v].left, v);
		}
	if(tree[v].right!=-1)
		if (!u[tree[v].right]) {
			dfs (tree[v].right );
			dsu_unite (v, tree[v].right, v);
		}
	for (size_t i=0; i<query[v].size(); ++i)
		if (u[query[v][i]]) {
			// printf ("%d %d -> %d\n", v+1, query[v][i]+1,g[ancestor[ dsu_get(query[v][i]) ]]);
			ll temp = g[ancestor[ dsu_get(query[v][i]) ]];
			//cout<<temp<<endl;
			qr_mp[mp(query[v][i] , v)] = temp;
			ans += temp;
			ans1 = (ans1*temp)%1000000007;
		}
}
int main()
{

	int n , k ,q;
	cin>>n>>k>>q;
	ll a , b , c , d , e , f , r, s , t , m , temp , temp1;
	cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>temp;
	ll L1 , La , Lc , Lm , D1 , Da , Dc , Dm;
	cin>>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
	ll rem = t;
	vector <int> vec;
	g.pb(temp);
	for(int i = 2 ; i <= n ; i++)
    {
        rem = (rem*t);
        if(rem >=s )
            rem%=s;
        if(rem <= r){
            temp1 = a*temp;
            if(temp1 >= m)
                temp1%=m;
            temp1+=b;
            temp1*=temp;
            if(temp1 >= m)
                temp1%=m;
            temp1+=c;
            if(temp1 >= m)
                temp1%=m;
            temp = temp1;
        }
        else{
            temp1 = d*temp;
            if(temp1 >= m)
                temp1%=m;
            temp1+=e;
            temp1*=temp;
            if(temp1 >= m)
                temp1%=m;
            temp1+=f;
            if(temp1 >= m)
                temp1%=m;
            temp = temp1;
        }
        g.pb(temp);
    }
	int root = build(g);
	/*ll  L , R , r_min;
	for(int i = 1  ; i <= q ; i++){
		L1 = ((La*L1) + Lc)%Lm;
		D1 = ((Da*D1) + Dc)%Dm;
		L = L1 + 1;
		R = min(L + k -1 + D1 , (ll)n);
		L-- , R--;
		//query[L].push_back(R);
		query[R].push_back(L);
	}*/
	ll L , R;
	int cnt = 0;
    vector<pair<ll , ll> > qur;
    for(int i = 1  ; i <= q ; i++){
        
        L1 = ((La*L1) + Lc);
        if(L1 >= Lm)
            L1 %= Lm;
        D1 = ((Da*D1) + Dc);
        if(D1 >= Dm)
            D1 %= Dm;
        L = L1 + 1;
        R = min(L + k -1 + D1 , (ll)n);
        L-- , R--;
        query[R].pb(L);
        if(i!=1 && qur[0] == mp(L , R))
            break;
        else
            qur.pb(mp(L , R));
        cnt++;
    }
	dfs(root);
	if(cnt!=0){
		int count = q / cnt;
		ans *= count;
		ans1 = (ans1*count)%1000000007;
		for(int i = 0 ; i < q - (cnt*count) ; i++){
			int temptemp = qr_mp[qur[i]];
			ans += temptemp , ans1 = (ans1*temptemp)%1000000007;
		}
	}
	cout<<ans<<" "<<ans1<<endl;
	return 0;
}