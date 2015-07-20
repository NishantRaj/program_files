#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){

	int t;
	cin>>t;
	for(int test = 1 ; test <= t ; test++){

		int d , temp , res = INT_MAX;
		vector<int> v;
		cin>>d;
		for(int i = 0 ; i < d ; i++)
		{
			cin>>temp;
			v.pb(temp);
		}
		for(int i = 1 ; i<= 1000 ; i++){
			int ans = 0;
			for(int j = 0 ; j < d ; j++){
				ans += (v[j]/i) - (v[j]%i == 0 ? 1 : 0); 
			}
			ans += i;
			res = min(ans , res);
		}
		cout<<"Case #"<<test<<": "<<res<<endl;
	}
	return 0;
}