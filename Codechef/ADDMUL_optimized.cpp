#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define mod 1000000007
#define ll long long 
struct data{
	ll val, type;
	data(){val = 0 , type = 1;}
	data(ll v , ll t){ val = v , type = t;}
};
int k;
struct node
{
	ll val , count;
	ll val_lazy , count_lazy;
	ll previous_lazy;
	bool lazy_set ;
	void split(node &a , node &b)
	{
		if(lazy_set){
			a.val = ((a.val*val_lazy)%mod + (a.count*count_lazy)%mod)%mod;
			if(a.previous_lazy ==1){
			 	a.val_lazy += val_lazy , a.count_lazy += count_lazy;
			 	a.previous_lazy = previous_lazy;
			} else if(a.previous_lazy == 2){
				a.val_lazy += val_lazy , a.count_lazy += count_lazy;
			 	a.previous_lazy = previous_lazy;
			} else if(a.previous_lazy == 0){
				a.val_lazy += val_lazy , a.count_lazy += count_lazy;
			 	a.previous_lazy = previous_lazy;
			} else{
				a.val_lazy = 0 , a.count_lazy += count_lazy;
				a.previous_lazy = 3;
			}
			if(a.val_lazy > mod)
				a.val_lazy%=mod;
			if(a.count_lazy > mod)
				a.count_lazy %= mod;
			

			// b.val_lazy += val_lazy , b.count_lazy += count_lazy;
			b.val = ((b.val*val_lazy)%mod + (b.count*count_lazy)%mod)%mod;
			if(b.previous_lazy ==1){
			 	b.val_lazy += val_lazy , b.count_lazy += count_lazy;
			 	b.previous_lazy = previous_lazy;
			} else if(b.previous_lazy == 2){
				b.val_lazy += val_lazy , b.count_lazy += count_lazy;
			 	b.previous_lazy = previous_lazy;
			} else if(b.previous_lazy == 0){
				b.val_lazy += val_lazy , b.count_lazy += count_lazy;
			 	b.previous_lazy = previous_lazy;
			} else{
				b.val_lazy = 0 , b.count_lazy += count_lazy;
				b.previous_lazy = 3;
			}
			if(b.val_lazy > mod)
				b.val_lazy%=mod;
			if(b.count_lazy > mod)
				b.count_lazy %= mod;
			a.lazy_set = true , b.lazy_set = true;
			val_lazy = 0 , count_lazy = 0 , previous_lazy = 0;
			lazy_set = false;
		}
	}
	void point_update(data check)
	{
		if(check.type == 1)
		{
			if(previous_lazy == 0 ){
				previous_lazy = 1;
				val_lazy = 1 , count_lazy += check.val;
			}
			else if(previous_lazy == 1){
				previous_lazy = 1;
				count_lazy+= check.val;
			}
			else if(previous_lazy == 2){
				previous_lazy = 1 ; 
				count_lazy += check.val;
			}
			else if(previous_lazy == 3){
				previous_lazy = 3;
				val_lazy = 0 , count_lazy += check.val;
			}
			if(val_lazy > mod)
				val_lazy%= mod;
			if(count_lazy > mod)
				count_lazy%= mod;
		}
		else if(check.type == 2)
		{
			if(previous_lazy == 0 ){
				previous_lazy = 2;
				val_lazy += check.val;
			}
			else if(previous_lazy == 1){
				previous_lazy = 2;
				val_lazy = check.val , count_lazy = (count_lazy*check.val);
			}
			else if(previous_lazy == 2){
				previous_lazy = 2;
				val_lazy += check.val , count_lazy = (count_lazy*check.val);
			}
			else if(previous_lazy == 3){
				val_lazy = 0 , count_lazy = (count_lazy*check.val);
				previous_lazy = 3;
			}
			if(val_lazy > mod)
				val_lazy%= mod;
			if(count_lazy > mod)
				count_lazy%= mod;
		}
		else if(check.type == 3)
		{
			val_lazy = 0 , count_lazy = check.val;
			previous_lazy = 3;
		}
		lazy_set = true;
	}
	void merge(node a , node b)
	{
		val = (a.val + b.val);
		count = a.count + b.count;
		if(val > mod)
			val %= mod;
		lazy_set = false;
		val_lazy = 0 , count_lazy = 0;
		a.val_lazy = a.count_lazy = 0;
		b.val_lazy = b.count_lazy = 0;
		previous_lazy = 0;
	}
	void clear_lazy(){
		val_lazy = 0 , count_lazy = 0 , lazy_set = false , previous_lazy = 0;
	}
	node()
	{
		val = 0 , count = 0 , val_lazy = 0 , count_lazy = 0 , previous_lazy = 0;
		lazy_set = false;
	}
}tree[262150];
void set_v(node &temp,int val)
{
	temp.val = (temp.val+val);
	if(temp.val  > mod)
		temp.val%=mod;
	temp.count +=1;
}
void create(int pos)
{
	pos>>=1;
	while(pos!=0)
	{
		tree[pos].merge(tree[(pos<<1)],tree[(pos<<1) + 1]);
		pos>>=1;
	}
}
void range_update(int root,int left_most ,int right_most , int l,int r,data val)
{
	if(l <= left_most && r >= right_most){
		if(val.type == 1)
			tree[root].val = ( tree[root].val + (tree[root].count*val.val)%mod)%mod;
		else if(val.type == 2)
			tree[root].val = ( tree[root].val*val.val)%mod;
		else
			tree[root].val = (val.val*tree[root].count)%mod;
		tree[root].point_update(val);
		return ;
	}
	int l_child = (root<<1) , r_child = l_child + 1 , mid = (left_most + right_most)>>1;
	if(left_most != right_most)
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
	if(left_most != right_most)
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
void print(){
	for(int i = 0 ; i <= (1<<(k+1)) ; i++){
		cout<<i<<" "<<tree[i].val<<" "<<tree[i].val_lazy<<" "<<tree[i].count_lazy<<" "
		<<tree[i].count<<" "<<tree[i].lazy_set<<" "<<tree[i].previous_lazy<<endl;
	}
	cout<<endl<<endl;
}
int main()
{
	int n,temp,l,r , m , v;
	scanf("%d%d",&n , &m);
	k = ceil(log(n)/log(2));
	int pos = (1<<k);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		set_v(tree[pos+i],temp);
		create(pos+i);
	}
	int type;
	while(m--)
	{
		scanf("%d" , &type);
		if(type == 4){
			node hold;
			scanf("%d%d" , &l , &r);
			hold = range_query(1,1,pos,l,r);
			printf("%lld\n" , hold.val%mod);
		}
		else{
			scanf("%d%d%d" , &l , &r , &v);
			range_update(1,1,pos,l,r,data(v , type));
			//print();
		}
	}
	return 0;
}