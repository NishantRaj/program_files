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
#define gc getchar_unlocked
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
		for(int i = left_most ;i< left_most+size ; i++){
			for(int j=1;j<=26;j++)
				if(tree[i].arr[j]){
					cout<<char(j+96);
					break;
				}
		}
	}
	void print(){
		for(int i = 0 ; i <= right_most ; i++){
			cout<< i << " -> " ;
			for(int j = 0 ; j < tree[i].arr.size() ; j++)
				cout<<tree[i].arr[j]<<" ";
			cout<<" "<<tree[i].ans<<endl;
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
		//tree[root].split(tree[l_child] , tree[r_child]);
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
		//tree[root].split(tree[l_child] , tree[r_child]);
		T l_node  , r_node , temp;
		if(l <= mid) l_node = range_query(l_child , left_most , mid , l , r );
		if(r > mid) r_node = range_query(r_child , mid+1 , right_most , l , r );
		//tree[root].merge(tree[l_child] , tree[r_child]);
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
	vector<int> arr;
	long long ans;
	void merge(node &a , node &b){
		int x , y;
		x = a.arr.size() , y = b.arr.size();
		arr.clear();
		int i = 0 , j = 0;
		ans = 0;
		long long k = 1;
		while(i < x && j < y){
			if(a.arr[i] < b.arr[j]){
				if(arr.size() > 0 && arr[arr.size() -1] != a.arr[i]){
					arr.push_back(a.arr[i]);
					ans = ans + k*a.arr[i];
					k++;
				} else if(arr.size() == 0){
					arr.push_back(a.arr[i]);
					ans = ans + k*a.arr[i];
					k++;
				}
				i++;
			} else{
				if(arr.size() > 0 && arr[arr.size() -1] != b.arr[j]){
					arr.push_back(b.arr[j]);
					ans = ans + k*b.arr[j];
					k++;
				} else if(arr.size() == 0){
					arr.push_back(b.arr[j]);
					ans = ans + k*b.arr[j];
					k++;
				}
				j++;
			}
		}
		while(i < x){
			if(arr.size() > 0 && arr[arr.size()-1] != a.arr[i]){
				arr.push_back(a.arr[i]);
				ans = ans + k*a.arr[i];
				k++;
			}
			else if(arr.size() == 0){
				arr.push_back(a.arr[i]);
				ans = ans + k*a.arr[i];
				k++;
			}
			i++;
		}
		while(j < y ){
			if(arr.size() > 0 && arr[arr.size()-1] != b.arr[j]){
				arr.push_back(b.arr[j]);
				ans = ans + k*b.arr[j];
				k++;
			}
			else if(arr.size() == 0){
				arr.push_back(b.arr[j]);
				ans = ans + k*b.arr[j];
				k++;
			}
			j++;
		}
		// for(int i = 0 ;  i < arr.size() ; i++){
		// 	ans = ans + (ll)arr[i]*(i+1);
		// }
	}
	void split(node &a , node &b){
	}
	void update(node &a){
	}
	node(){
		arr.clear();
		ans = 0;
	}
	node(int a){ 
		ans = a;
		arr.push_back(a);
	}
};
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main(){
	int t;
	scanint(t);
	while(t--){
		int n;
		scanint(n);
		node arr[n+9];
		segmentTree<node> s(n);
		int temp;
		for(int i = 0 ; i < n ; i++){
			scanint(temp);
			arr[i] = node(temp);
		}
		s.init(arr);
		//s.print();
		int m;
		scanint(m);
		while(m--){
			int l,r;
			scanint(l);
			scanint(r);
			l--,r--;
			node temp = s.Query(l,r);
			printf("%lld\n",temp.ans);
		}
	}
	return 0;
}