/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 06 June 2016 (Monday) 19:15
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define pii pair<int , int>
#define pdd pair<double , long long>
#define MOD 1000000007
long double power10[10] = {1.000000000, 10.000000000, 100.000000000, 1000.000000000, 10000.000000000, 100000.000000000, 1000000.000000000, 10000000.000000000, 100000000.000000000, 1000000000.000000000};
pair<ld , ll> ans[1700000];
vector<long long> v;
inline ll inv_mod(ll x, ll p){
	ll a = 1 , n = x;
	while(p){
		if(p&1)
			a = (a*n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return a;
}
inline ld GetFraction(ll number){
	int len = log10(number);
	ld y = (ld) number /power10[len];
	return y;
}
pii FindFirstDigit(vector<long long> &arr, int n){
	long double x = 1.0;
	long long ans = 1;
	for(int i = 0 ; i < n ; i++){
		// int len = to_string(arr[i]).length();
		// int len = log10(arr[i])+1;
		ans = (ans*arr[i])%MOD;
		// len--;
		// long double y = (long double)arr[i] / (long double)power10[len];
		ld y = GetFraction(arr[i]);
		x *= y;
		if(x >= 10.00){
			x /= 10;
		}
	}
	int first = (int) x;
	int second = (int) ans;
	return mp(first , second) ;
}
void PreCompute(){
	int n = v.size()-1;
	ans[0] = mp(GetFraction(v[1]) , v[1]%MOD);
	for(int i = 1 ; i<= n; i++){
		long double x = 1.0;
		long long mul = 1;
		for(int j = 1 ; 1 + j*i <= n ; j++){
			int pos = 1 + i*j;
			mul = (mul*v[pos])%MOD;
			ld y = GetFraction(v[pos]);
			x *= y;
			if(x >=10.000000000)
				x/=10.000000000;
		}
		ans[i] = mp(x , mul);
		// cout<<i<<" "<<ans[i].first<<" "<<ans[i].second<<endl;
	}

}
void Update(int pos , ll val){
	if(pos == 1){
		ans[0] = mp(GetFraction(val) , val);
	}
	int temp = pos-1;
	for(int i = 1 ; i*i <= temp ; i++){
		if(temp%i==0){
			pdd previous = ans[i];
			ld a = previous.first * GetFraction(val);
			a /= GetFraction(v[pos]);
			if(a < 1.000000000)
				a*=10;
			if(a >= 10.000000000)
				a/=10;
			ll b = previous.second*inv_mod(v[pos] , MOD-2);
			b = b%MOD;
			b = (b*val)%MOD;
			ans[i] = mp(a , b);

			int grp = temp/i;
			if(grp != i){
				pdd previous = ans[grp];
				ld a = previous.first * GetFraction(val);
				a /= GetFraction(v[pos]);
				if(a < 1.000000000)
					a*=10;
				if(a >= 10.000000000)
					a/=10;
				ll b = previous.second*inv_mod(v[pos] , MOD-2);
				b = b%MOD;
				b = (b*val)%MOD;
				ans[grp] = mp(a , b);
			}
		}
	}
	v[pos] = val;
	// int n = v.size()-1;
	// for(int i = 1 ; i <= n*log2(n) ; i++)
	// 	cout<<i<<" "<<ans[i].first<<" "<<ans[i].second<<endl;
}
void BruteForce(int q , int n){
	while(q--){
		int qType;
		scanf("%d",&qType);
		if(qType==1){
			int pos , frnd;
			scanf("%d%d",&pos , &frnd);
			v[pos] = frnd;
		} else{
			int interval;
			scanf("%d",&interval);
			vector<long long> vv;
			for(int i = 0 ; 1 + i*interval <= n ; i++){
				int pos = 1 + i*interval;
				vv.pb(v[pos]);
			}
			pii an = FindFirstDigit(vv , vv.size());
			printf("%d %d\n",an.first , an.second);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	v.pb(1);
	for(int i = 1 ; i <= n ; i++){
		int inp;
		scanf("%d",&inp);
		v.pb(inp);
	}
	int q;
	scanf("%d",&q);
	int ter=0;
	int quer[q+9][3];
	for(int i = 0 ; i < q ; i++){
		scanf("%d",&quer[i][0]);
		if(quer[i][0] == 1){
			scanf("%d%d",&quer[i][1] , &quer[i][2]);
			if(quer[i][1] >= 10000)
				ter++;
		} else
			scanf("%d",&quer[i][1]);
	}
	if(n<= 1000 || ter >= 10000){
		int i = 0;
		while(q--){
			int qType = quer[i][0];
			if(qType==1){
				int pos , frnd;
				pos = quer[i][1];
				frnd = quer[i][2];
				v[pos] = frnd;
			} else{
				int interval = quer[i][1];
				vector<long long> vv;
				for(int i = 0 ; 1 + i*interval <= n ; i++){
					int pos = 1 + i*interval;
					vv.pb(v[pos]);
				}
				pii an = FindFirstDigit(vv , vv.size());
				printf("%d %d\n",an.first , an.second);
			}
			i++;
		}
	} else{
		PreCompute();
		int i = 0;
		while(q--){
			int qType = quer[i][0];
			if(qType==1){
				int pos ;
				ll frnd;
				pos = quer[i][1];
				frnd = (ll)quer[i][2];
				Update(pos ,frnd);
			} else{
				int interval = quer[i][1];
				pdd frst = ans[0];
				pdd x = ans[interval];
				ld frc = x.first*frst.first;
				if(frc >= 10.000000000)
					frc/=10.000000000;
				ll md = (x.second*frst.second)%MOD;
				printf("%d %lld\n",(int)frc , md);
			}
			i++;
		}
	}
	return 0;
} 