/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 15 July 2015 (Wednesday) 21:27
===================================================*/
//question 312E codeforces
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
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
	int arr[27],lazy_pos,child;
	void merge(node &a , node &b){
		for(int i =1;i<=26;i++)
			arr[i]=a.arr[i]+b.arr[i];
		child = a.child + b.child;
		lazy_pos = 0;
	}
	void split(node &a , node &b){
		if(lazy_pos != 0){
			memset(b.arr , 0 , sizeof(b.arr));
			memset(a.arr , 0 , sizeof(a.arr));
			a.arr[lazy_pos]=a.child;
			b.arr[lazy_pos]=b.child;
			a.lazy_pos=lazy_pos;
			b.lazy_pos=lazy_pos;
			lazy_pos=0;
		}
	}
	void update(node &a){
		lazy_pos=a.lazy_pos;
		memset(arr,0,sizeof arr);
		arr[lazy_pos]=child;
	}
	node(){
		lazy_pos = 0;
		memset(arr,0,sizeof arr);
	}
	node(char v,int lazy){ 
		lazy_pos=lazy;
		child = 1;
		memset(arr,0,sizeof arr);
		arr[v-96] = 1 ;
	}
};
node arr[100009];
int main(){
	int n , temp ,q;
	cin>>n>>q;
	segmentTree<node> s(n);
	string str;
	cin>>str;
	for(int i =0;i<str.size();i++)
		arr[i]=node((char)str[i],0);
	s.init(arr);
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		l--,r--;
		node temp = s.Query(l,r);
		int start_pos=l;
		if(k==1){
			for(int i =1;i<=26;i++){
				if(temp.arr[i]){
					s.Update(start_pos,start_pos+temp.arr[i]-1,node(0 , i));
					start_pos+=temp.arr[i];
				}
			}
		} else{
			for(int i =26;i>=1;i--){
				if(temp.arr[i]){
					s.Update(start_pos,start_pos+temp.arr[i]-1,node(0 , i));
					start_pos+=temp.arr[i];
				}
			}
		}
	}
	s.fill_ans();
	cout<<endl;
	return 0;
}