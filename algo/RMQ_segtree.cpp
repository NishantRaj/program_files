#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int minVal(int x, int y) { return (x < y)? x: y; }
 
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
int st[33554432];
int arr[10000009];
int RMQUtil( int ss, int se, int qs, int qe, int index)
{
   
    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return INT_MAX;
 
    int mid = getMid(ss, se);
    return minVal(RMQUtil( ss, mid, qs, qe, 2*index+1),
                  RMQUtil( mid+1, se, qs, qe, 2*index+2));
}
 
int RMQ( int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return RMQUtil( 0, n-1, qs, qe, 0);
}
 
int constructSTUtil( int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(ss, mid, si*2+1),
                     constructSTUtil( mid+1, se, si*2+2));
    return st[si];
}
int ans_array[10000009][2];
ll pow_mod(ll m , ll b , ll mod){
    ll a = 1 , p = m;
    while(b){
        if(b&1)
            a = (a*p)%mod;
        p = (p * p )%mod;
        b>>=1;
    }
    return a;
}
int main()
{
    int n , k ,q;
    scanf("%d%d%d\n" , &n , &k , &q);
    int a , b , c , d , e , f , r, s , t , m ;
    ll temp , temp1 , temp2;
    //cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>temp;
    scanf("%d%d%d%d%d%d%d%d%d%d%lld",&a , &b , &c , &d , &e , &f , &r ,&s , &t , &m ,&temp);
    ll L1 , La , Lc , Lm , D1 , Da , Dc , Dm;
    //cin>>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &L1 , &La , &Lc , &Lm , &D1 , &Da , &Dc , &Dm);
    arr[0] = temp;
    ll rem = t;
    int flag ;
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
        arr[i-1] = temp;
    }
    constructSTUtil(0, n-1, 0);
    ll ans = 0 , ans1 = 1, L , R , r_min;
    int cnt = 0;
    vector<pair<ll , ll> > query;
    for(int i = 1  ; i <= q ; i++){
        
        L1 = ((La*L1) + Lc);
        if(L1 >= Lm)
            L1 %= Lm;
        D1 = ((Da*D1) + Dc);
        if(D1 >= Dm)
            D1 %= Dm;
        L = L1 + 1;
        R = min(L + k -1 + D1 , (ll)n);
        r_min = RMQ( n, L-1, R - 1);
        if(i!=1 && query[0] == mp(L , R))
            break;
        else
            query.pb(mp(L , R));
        ans += r_min;
        ans1 = (ans1*r_min);
        if(ans1 >= 1000000007LL)
            ans1%=1000000007;
        ans_array[cnt][0] = ans;
        ans_array[cnt][1] = ans1;
        cnt++;
    }
    if(q > cnt){
        int count = q / cnt;
        ans *= count;
        ans1 = pow_mod(ans1 , count , 1000000007);
        if(cnt != q){
            ans+= ans_array[q - (cnt*count) - 1 ][0];
            ans1 = (ans1*ans_array[q - (cnt*count) - 1][1])%1000000007;
        }
    }
    printf("%lld %lld\n" , ans , ans1);
    //cout<<ans<<" "<<ans1<<endl;
    return 0;
}