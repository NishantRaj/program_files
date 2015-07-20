#include <bits/stdc++.h>
using namespace std;
#define ll long long
int M[24][10000001];
int A[10000001];
void Compute_ST(int N){
    int i,j;
    for(i=0;i<N;i++)
        M[0][i]=i;
    for(i=1;1<<i <=N ;i++){
        for(j=0;j+(1<<(i-1))<N;j++){
            if(A[M[i-1][j]]<=A[M[i-1][j+(1<<(i-1))]])
                M[i][j]=M[i-1][j];
            else
                M[i][j]=M[i-1][j+(1<<(i-1))];
        }
    }
}
int RMQ(int s,int e){
    int k=e-s;
    k=31-__builtin_clz(k+1); // k = log(e-s+1)
    if(A[M[k][s]]<=A[M[k][e-(1<<k)+1]])
        return A[M[k][s]];
    return A[M[k][e-(1<<k)+1]];
}
int main(){
	int n , k ,q;
	cin>>n>>k>>q;
	ll a , b , c , d , e , f , r, s , t , m , temp ,temp1;
	cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>temp;
	ll L1 , La , Lc , Lm , D1 , Da , Dc , Dm;
	cin>>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
	A[0] = temp;
	ll rem = t;
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
        A[i-1] = temp;
    }
	Compute_ST(n);
	ll ans = 0 , ans1 = 1, L , R , r_min;
	for(int i = 1  ; i <= q ; i++){
 
		L1 = ((La*L51) + Lc);
        if(L1 >= Lm)
            L1 %= Lm;
        D1 = ((Da*D1) + Dc);
        if(D1 >= Dm)
            D1 %= Dm;
        L = L1 + 1;
        R = min(L + k -1 + D1 , (ll)n);
		r_min = (ll)RMQ(L-1 , R-1);
		ans += r_min;
		ans1 = (ans1*r_min)%1000000007;
	}
	cout<<ans<<" "<<ans1%1000000007<<endl;
	return 0; 
} 