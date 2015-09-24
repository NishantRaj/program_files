/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 14 September 2015 (Monday) 00:18
===================================================*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000007
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
	~segmentTree(){
		delete [] tree;
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
	void print(){
		for(int i = 0 ; i <= right_most ; i++)
			cout<<i<<" -> "<<tree[i].res<<" "<<tree[i].a<<" "<<tree[i].b<<" "<<tree[i].lazy_a <<" "<<tree[i].lazy_b<<" "<<tree[i].sz<<endl;
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
	int res , a , b , lazy_a , lazy_b , sz;
	void merge(node &left , node &right){
		a = (left.a + right.a)%mod;
		b = (left.b + right.b)%mod;
		res = (left.res + right.res)%mod;
		sz = left.sz + right.sz;
	}
	void split(node &left , node &right){
		if(lazy_a!=0){
			left.a = (left.a + ((ll)left.sz*lazy_a)%mod)%mod;
			right.a = (right.a + ((ll)right.sz*lazy_a)%mod)%mod;
			left.lazy_a = (left.lazy_a + lazy_a)%mod;
			right.lazy_a = (right.lazy_a + lazy_a)%mod;
			left.res = (left.res + ((ll)lazy_a*left.b)%mod)%mod;
			right.res = (right.res + ((ll)lazy_a*right.b)%mod)%mod;
			lazy_a = 0;
		}
		if(lazy_b!=0){
			left.b = (left.b + ((ll)left.sz*lazy_b)%mod)%mod;
			right.b = (right.b + ((ll)right.sz*lazy_b)%mod)%mod;
			left.lazy_b = (left.lazy_b + lazy_b)%mod;
			right.lazy_b = (right.lazy_b + lazy_b)%mod;
			left.res = (left.res + ((ll)lazy_b*left.a)%mod)%mod;
			right.res = (right.res + ((ll)lazy_b*right.a)%mod)%mod;
			lazy_b = 0;
		}
	}
	void update(node &upd){
		int c = upd.res , type = upd.a;
		if(type==2){
			b = (b + ((ll)c*sz)%mod)%mod;
			lazy_b = (lazy_b + c)%mod;
			res = (res + ((ll)c*a)%mod)%mod;
		} else{
			a = (a + ((ll)c*sz)%mod)%mod;
			lazy_a = (lazy_a + c)%mod;
			res = (res + ((ll)c*b))%mod;
		}
	}
	node(){
		res = a = b = lazy_a = lazy_b =  sz = 0;
	}
	node(int _res , int aa , int bb , int lazy_aa , int lazy_bb , int _sz){
		res = _res , a = aa , b = bb , lazy_a = lazy_aa , lazy_b = lazy_bb , sz = _sz;
	}
};
node *arr;
int main(){
	int n , q;
	cin>>n>>q;
	vector< tuple<int , int , int , int> >query;
	vector<int> range;
	for(int i = 0 ; i < q ; i++){
		int type , l , r , c=0;
		cin>>type>>l>>r;
		r++;
		if(type !=3 )
			cin>>c;
		query.pb(make_tuple(type , l , r , c));
		range.pb(l);
		range.pb(r);
	}
	sort(range.begin() , range.end());
	range.resize(unique(range.begin() , range.end()) - range.begin());
	arr = new node[range.size()];
	for(int i = 1 ; i < range.size() ; i++){
		arr[i] = node(0 , 0 , 0 , 0 , 0 , range[i] - range[i-1]);
	}
	segmentTree<node> s(range.size()+1);
	s.init(arr);
	delete [] arr;
	int pos = 0;
	while(q--){
		int type , l , r , c;
		type = get<0>(query[pos]);
		l = lower_bound(range.begin() , range.end() , get<1>(query[pos])) - range.begin()+1;
		r = lower_bound(range.begin() , range.end() , get<2>(query[pos])) - range.begin();
		if(type == 3){
			cout<<s.Query(l , r).res<<endl;
		} else if(type == 2){
			c = get<3>(query[pos]);
			node x = node(c , 2 , 0 , 0 , 0 , 0);
			s.Update(l , r , x);
		} else if(type == 1){
			c = get<3>(query[pos]);
			node x = node(c , 1 , 0 , 0 , 0 , 0);
			s.Update(l , r , x);
		}
		pos++;
	}
	return 0;
}