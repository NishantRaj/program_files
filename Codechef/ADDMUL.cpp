#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define mod 1000000007
#define ll long long 
struct data{
	int val, type;
	data(){val = 0 , type = 1;}
	data(int v , int t){ val = v , type = t;}
};
int k;
struct node
{
    ll val , count;
    vector<data> lazy ;
    void split(node &a , node &b)
    {
        for(int i=0;i<lazy.size();i++)
        {
            if(lazy[i].type == 1)
            {
                ll temp = a.count*lazy[i].val;
                if(temp > mod)
                    temp %= mod;
                temp += a.val;
                if(temp > mod)
                    temp%=mod;
                a.val = temp;
                temp = b.count*lazy[i].val;
                if(temp > mod)
                    temp %= mod;
                temp += b.val;
                if(temp > mod)
                    temp%=mod;
                b.val = temp;
                a.lazy.PB(data(lazy[i].val , 1));
                b.lazy.PB(data(lazy[i].val , 1));
            }
            else if(lazy[i].type == 2)
            {
                ll temp = a.val*lazy[i].val;
                if(temp > mod) temp%=mod;
                a.val = temp;
                temp = b.val*lazy[i].val;
                if(temp > mod) temp%=mod;
                b.val = temp;
                a.lazy.PB(data(lazy[i].val , 2));
                b.lazy.PB(data(lazy[i].val , 2));
            }
            else if(lazy[i].type == 3)
            {
                ll temp = lazy[i].val*a.count;
                if(temp > mod) temp %= mod;
                a.val = temp;
                temp = lazy[i].val*b.count;
                if(temp > mod) temp %= mod;
                b.val = temp;
                a.lazy.PB(data(lazy[i].val , 3));
                b.lazy.PB(data(lazy[i].val , 3));
            }
        }
        lazy.clear();
    }
    void point_update(data check)
    {
        if(check.type == 1)
        {
            ll temp = count*check.val;
            if(temp > mod)
                temp %= mod;
            temp += val;
            if(temp > mod)
                temp%=mod;
            val = temp;
            lazy.PB(data(check.val , 1));
        }
        else if(check.type == 2)
        {
            ll temp = val * check.val;
            if(temp > mod)
                temp%= mod;
            val = temp;
            lazy.PB(data(check.val , 2));
        }
        else if(check.type == 3)
        {
            val = check.val;
            lazy.PB(data(check.val , 3));
        }
    }
    void merge(node a , node b)
    {
        val = (a.val + b.val);
        if(val > mod)
            val %= mod;
    }
    node()
    {
        val = 0 , count = 0;
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
        tree[root].point_update(val);
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
            printf("%lld\n" , hold.val);
        }
        else{
        	scanf("%d%d%d" , &l , &r , &v);
            range_update(1,1,pos,l,r,data(v , type));
        }
    }
    return 0;
}