#include <bits/stdc++.h>
using namespace std;
#define INT -1000000
int k;
struct node
{
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

void initalize()
{
	for(int i=0;i< (1<<(k+1)) ;i++)
		tree[i] = node();
}
void create(int pos)
{
	pos>>=1;
	while(pos!=0)
	{
		tree[pos].merge(tree[pos*2],tree[pos*2 + 1]);
		pos>>=1;
	}
}
void range_update(int root,int left_most ,int right_most , int l,int r,int val)
{
	if(l <= left_most && r >= right_most){
		tree[root].val+= val*tree[root].child;
		tree[root].lazy+=val;
		return ;
	}
	int l_child = (root<<1) , r_child = l_child + 1 , mid = (left_most + right_most)>>1;
	tree[root].split(tree[l_child],tree[r_child]);
	if(l <= mid)
		range_update(l_child , left_most , mid , l , r , val);
	if(r > mid)
		range_update(r_child , mid+1 , right_most , l , r , val);
	tree[root].merge(tree[l_child] , tree[r_child]);
}
node range_query(int root , int left_most , int right_most , int l ,int r)
{
	if( l <= left_most && r >= right_most )
		return tree[root];

	int l_child = (root<<1) , r_child = l_child + 1 , mid = (left_most + right_most )>>1 ;

	tree[root].split(tree[l_child],tree[r_child]);

	node l_node = node() , r_node = node();

	if(l <= mid)
		l_node = range_query(l_child , left_most , mid , l , r);
	if(r > mid)
		r_node = range_query(r_child , mid + 1 , right_most, l , r);

	tree[root].merge(tree[l_child] , tree[r_child]);

	node temp = node();
	temp.merge(l_node,r_node);

	return temp;
}
int main()
{
	int n,temp,l,r;
	scanf("%d",&n);
	k = ceil(log(n)/log(2));
	int pos = (1<<k);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		tree[pos+i] = node(temp);
		create(pos+i);
	}
	int m,c;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d%d",&c,&l,&r);
		if(c==1)
			printf("%d\n",(range_query(1,1,pos,l,r)).result);
		else if(c==0)
		{
			tree[pos+l-1] = node(r);
			create(pos + l -1);
		}
	}
	return 0;
}
