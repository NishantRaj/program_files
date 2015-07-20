/*
========================================
Name :- Nishant Raj
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Batch :- 2012-2016
========================================*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
vector<int> v[100009];
int range,start[100009],end_arr[100009];
bool visited[100009];
void generate_range(int node){
	if(!visited[node]){
		visited[node]=true;
		start[node]=range;
		range++;
		for(int i = 0 ;i<v[node].size();i++)
			generate_range(v[node][i]);
		end_arr[node]=range-1;
	}
}
 
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
	void print(){
		for(int i = left_most ; i<= right_most ; i++){
			for(int j=0;j<26;j++)
				if(tree[i].arr[j]){
					cout<<char(j+97);
					break;
				}
		}
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
	int awake,lazy,child;
	node(){awake=0,lazy=0,child=0;}
	node(int num,int l){awake=num,lazy=l,child=1;}
	void update(node &a){
		if(a.lazy==1){awake=child,lazy=1;}
		else if(a.lazy==2) {awake=0,lazy=2;}
	}
	void split(node &a,node &b){
		if(lazy==1){
			a.awake=a.child,a.lazy=lazy;
			b.awake=b.child,b.lazy=lazy;
		} else if(lazy==2){
			a.awake=0,a.lazy=lazy;
			b.awake=0,b.lazy=lazy;
		}
		lazy=0;
	}
	void merge(node &a,node &b){
		awake=a.awake+b.awake;
		child = a.child + b.child;
		lazy=0;
	}
};
int main(){
	int n,temp,q,root;
	cin>>n;
	node data[n+9];
	data[0]=node(0,0);
	for(int i=1;i<=n;i++){
		data[i]=node(1,0);
		cin>>temp;
		if(temp==0)
			root=i;
		else{
			v[i].pb(temp);
			v[temp].pb(i);
		}
	}
	generate_range(root);
	segmentTree<node> s(n);
	// for(int i=1;i<=n;i++)
	// 	cout<<start[i]<<" "<<end_arr[i]<<endl;
	s.init(data);
	cin>>q;
	while(q--){
		int type,id;
		cin>>type>>id;
		if(type==3){
			// cout<<start[id]<<" "<<end_arr[id]<<endl;
			if(start[id]!=end_arr[id])
				cout<<s.Query(start[id]+1,end_arr[id]).awake<<endl;
			else
				cout<<0<<endl;
		}
		else{
			// cout<<start[id]<<" "<<end_arr[id]<<" "<<type<<endl;
			if(start[id]!=end_arr[id])
				s.Update(start[id]+1,end_arr[id],node(0,type));
		}
	}
	return 0;
}