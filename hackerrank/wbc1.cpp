#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
#define MP make_pair
#define LL long long 
LL *back;
LL *front;
LL read(LL idx,LL a[])
{
    long long val = 0;
    while(idx)
    {
        val += a[idx] ;
        idx -=(idx & -idx);
    }
    return val;
}
void update(LL idx ,LL val,LL a[])
{
    while(idx<=MAX)
    {
        a[idx] +=val;
        idx+=(idx & -idx);
    }
}
void update1(LL idx,LL val,LL a[])
{
    while(idx)
    {
        a[idx]+=val;
        idx-=(idx & -idx);
    }
}
LL read1(LL idx,LL a[])
{
    LL val=0;
    while(idx<=MAX)
    {
        val += a[idx];
        idx+=(idx & -idx);
    }
    return val;
}
class q
{
public:
    LL small,big;
    q(){}
    q(LL a , LL b){small = a , big = b;}
}*actual;
vector<q> query;
class ans 
{
public:
    LL a,b,c,d;
    ans()
    {
        a=b=c=d = 0;
    }
}*final;
vector<pair<LL,LL> > check1[500009],check2[500009];
void mallocator(){
    back = new LL[500009];
    front = new LL[500009];
    actual = new q[5000009];
    // query = new q[5000009];
    final = new ans[5000009];
}
vector<LL>  result(LL indx[] , LL n , LL m)
{
    LL res=0;
    LL p,q;
    for(LL i=0;i<m;i++)
    {
        check1[query[i].small].push_back(MP(query[i].big,i));
        check2[query[i].big].push_back(MP(query[i].small,i));
    }
    for(LL i=n-1;i>=0;i--)
    {
        for(LL j= 0 ;j<check2[i+1].size();j++)
        {
            LL x = read(indx[check2[i+1][j].first-1] - 1,back);
            final[check2[i+1][j].second].b = x;
        }
        for(LL j= 0 ;j<check1[i+1].size();j++)
        {
            LL x = read(indx[check1[i+1][j].first-1] - 1,back);
            final[check1[i+1][j].second].d = x;
        }
        LL x = read(indx[i] - 1,back);
        actual[i+1].big = x; 
        res += x;
        update(indx[i],1,back);
    }
    for(LL i=0;i<n;i++)
    {
        for(LL j = 0;j<check1[i+1].size();j++)
        {
            LL x = read1(indx[check1[i+1][j].first-1],front);
            final[check1[i+1][j].second].c = x;
        }
        for(LL j = 0;j<check2[i+1].size();j++)
        {
            LL x = read1(indx[check2[i+1][j].first-1],front);
            final[check2[i+1][j].second].a = x;
        }
        LL x = read1(indx[i],front);
        actual[i+1].small = x;
        update1(indx[i]-1,1,front);
    }
    vector<LL> ans;
    for(LL i=0;i<m;i++)
    {
        if(indx[query[i].small-1] < indx[query[i].big - 1])
            final[i].c += 1;
        else if(indx[query[i].small-1] > indx[query[i].big - 1])
            final[i].d +=1;
        LL temp=final[i].d + final[i].c - actual[query[i].big].small - actual[query[i].big].big;
        LL temp1 = final[i].b + final[i].a - actual[query[i].small].small - actual[query[i].small].big;
        LL total = res + (temp+temp1);
        //printf("%lld\n",total);
        ans.push_back(total);
    }
    return ans;
}
void update_own(LL arr[],LL pos,LL val,LL Max)
{
    while(pos<=Max)
    {
        arr[pos] += val;
        pos += (pos & -pos);
    }
}
LL read_own(LL arr[],LL pos)
{
    LL sum = 0;
    while(pos)
    { 
        sum += arr[pos];
        pos -= (pos & -pos);
    }
    return sum;
}
void update_own1(LL idx,LL val,LL a[])
{
    while(idx)
    {
        a[idx]+=val;
        idx-=(idx & -idx);
    }
}
LL read_own1(LL idx,LL a[] , LL Max)
{
    LL val=0;
    while(idx<=Max)
    {
        val += a[idx];
        idx+=(idx & -idx);
    }
    return val;
}
struct sdc{
    LL  bb , cc;
    LL aa;
    sdc(){}
    sdc(LL x , LL y , LL z){
        aa = x , bb = y , cc = z;
    }
};
bool compare(const sdc &a , const sdc &b){
    return a.aa == b.aa ? (a.bb == b.bb ? a.cc < b.cc : a.bb < b.bb ) : a.aa < b.aa;
}
struct cmp{
    bool operator()(const q &a , const q &b){
        return a.small == b.small ? a.big < b.big : a.small < b.small;
    }
};
map<q , int , cmp> qr;
int main()
{
    LL n;
    mallocator();
    scanf("%lld",&n);
    LL hold[n+9];
    for(LL i=0;i<n;i++){
        scanf("%lld",&hold[i]);
    }
    LL total = 0;
    LL tree[n+9];
    memset(tree,0,sizeof(tree));
    LL mi = INT_MAX , ind = n-1 , start , ans = INT_MIN , end;
    vector<LL> start_pos , start_pos1;
    vector<pair<LL , LL> > save , save1;
    int h1[n+9] , h2[n+9];
    for(LL i = n - 1 ; i>=0 ; i--)
    {
        LL temp = 0;
        temp = read_own(tree,hold[i]-1);
        h1[i] = temp;
        // cout<<hold[i]<<" "<<temp<<endl;
        if(temp >= ans){
            start = i , end = ind;
            save.push_back(MP(temp , start));
            ans = temp;
        } 
        if(mi > hold[i]){
            mi = hold[i] , ind = i;
        }
        total += temp;
        update_own(tree,hold[i] , 1LL , n+9);
    }
    memset(tree,0,sizeof(tree));
    for(LL i = 0 ; i < n ; i++){
        LL temp = 0;
        temp = read_own1(hold[i] ,tree , n+9);
        h2[i] = temp;
        // cout<<hold[i]<<" "<<temp<<endl;
        // cout<<"here";
        if(temp >= ans){
            save1.push_back(MP(temp , i));
            ans = temp;
        }
        update_own1(hold[i], 1 , tree);
        
    }
    if(total == 0){
        printf("Cool Array\n");
        return 0;
    }
    int flag = 0;
    sort(save.begin() , save.end());
    sort(save1.begin() , save1.end());
    for(LL i = save.size() - 1 ; i>= 0 ; i--){
        if(save[i].first == save.back().first)
            start_pos.push_back(save[i].second);
        else
            break;
    }
    for(LL i = save1.size() - 1 ; i>= 0 ; i--){
        if(save1[i].first == save1.back().first)
            start_pos1.push_back(save1[i].second);
        else
            break;
    }
    LL  k = 0;
    flag = 1;
    if(flag = 1){
        sort(start_pos.begin() , start_pos.end());
        for(int i = 0 ; i < start_pos.size() ; i++){
            start = start_pos[i];
            if(qr.size() >= 5000000) break;
            for(int i = start + 1 ; i< n ; i++){
                qr[q(start+1 , i+1)] = 1;
            }
            for(int i = 0 ; i < start - 1 ; i++){
                qr[q(i+1 , start+1)] = 1;
            }
        }
    }
    vector<LL> res;
    k = qr.size();
    int p = 0;
    for(auto it: qr){
        query.push_back(q(it.first.small ,it.first.big ));
        p++;
    }
    res = result(hold , n , k);
    LL tt = INT_MAX;
    start = 0 , end = 0;
    sdc  final_ans(LLONG_MAX , INT_MAX , INT_MAX);
    for(LL i = 0 ; i < k ; i++){
        if(res[i] - total <= tt){
            tt = res[i] - total;
            start = query[i].small;
            end = query[i].big;
            if(compare( sdc(tt , start , end) , final_ans)){
                final_ans = sdc(tt , start , end);
            }
        } 
    }
    printf("%lld %lld\n",final_ans.bb ,final_ans.cc);
    return 0;
} 