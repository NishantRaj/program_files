#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
int M[100000];
int A[10000001];
int size_m = 0;
struct cmp{
	bool operator()(const pair<int , int > &a , const pair<int , int > &b){
		return a.first == b.first ? a.second < b.second : a.first < b.first;
	}
};
void RMQ_SPLIT(int N){
    size_m =0;
    for(int i=0;i<N;){
        int minindex = i;
        for(int j=0;j<(int)sqrt(N) && i<N;j++){
            if(A[i]<A[minindex])
                minindex=i;
            i++;
        }
        M[size_m++]=minindex;
    }
}
int RMQ(int s,int e,int N){
    int start = s/(int)sqrt(N); // this will compute the starting index of the M array 
    int ans = A[s]; 
    int end = e/(int)sqrt(N); // ending index of the M array
    for(int i=s;i<(start+1)*sqrt(N);i++)
      if(A[i]<ans)
        ans = A[i];
    for(int i=start+1;i<end;i++){
        if(A[M[i]]<ans)
            ans=A[M[i]];
    }
    for(int i=end*sqrt(N);i<=e;i++){
        if(A[i]<ans)
            ans = A[i];
    }
    return ans;
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
int main(){
	int n , k ,q;
	cin>>n>>k>>q;
	ll a , b , c , d , e , f , r, s , t , m , temp ;
	cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>temp;
	ll L1 , La , Lc , Lm , D1 , Da , Dc , Dm;
	cin>>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
	A[0] = temp;
	ll rem = t;
	for(int i = 2 ; i <= n ; i++)
	{
		rem = (rem*t)%s;
		if(rem <= r)
			temp = ((temp*((a*temp)%m + b))%m + c)%m;
		else
			temp = ((temp*((d*temp)%m + e))%m + f)%m;
		A[i-1] = temp;
	}
	//Compute_ST(n);
	RMQ_SPLIT(n);
	ll ans = 0 , ans1 = 1, L , R , r_min;
 
	vector<pair<ll , ll> > qur;
	int cnt = 0;
	for(int i = 1  ; i <= q ; i++){
 
		L1 = ((La*L1) + Lc)%Lm;
		D1 = ((Da*D1) + Dc)%Dm;
		L = L1 + 1;
		R = min(L + k -1 + D1 , (ll)n);
		r_min = RMQ((int)(L-1) , (int)(R-1) , n);
		if(i!=1 && qur[0] == mp(L , R))
			break;
		else
			qur.pb(mp(L , R));
		ans += r_min;
		ans1 = (ans1*r_min)%1000000007;
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
	// for(int i = 0 ; i < q - (cnt*count) ; i++)
	// 	ans += ans_array[i] , ans1 = (ans1*(ans_array[i]))%1000000007;
	cout<<ans<<" "<<ans1<<endl;
	return 0; 
} 