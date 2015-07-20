#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int , int> >v;
		int a , b;
		for(int i = 0 ; i < n ; i++){
			cin>>a>>b;
			v.pb(mp(b-1 , a));
		}
		sort(v.begin() , v.end());
		int res = 0;
		for(int i = 0 ; i < n ; i++){
			int res1 = 1;
			for(int j = i+1 ; j< n ; j++){
				if(v[j].second <= v[i].first)
					res1++;
			}
			res = max(res , res1);
		}
		cout<<res<<endl;
	}
	return 0;
}vis