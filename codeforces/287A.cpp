#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
#define MOD 1000000007
int main(){

	int n , k;
	cin>>n>>k;
	vector<pair<int , int> > v;
	int temp;
	for(int i = 0 ; i < n ; i++){
		cin>>temp;
		v.pb(mp(temp , i+1));
	}
	sort(v.begin() , v.end());
	int sum = v[0].first;
	int i = 1;
	vector<int> save;
	save.pb(v[0].second);
	int flag = 0;
	while(sum<= k && i < n){
		sum+=v[i].first;
		flag = 1;
		save.pb(v[i].second);
		i++;
	}
	if(!flag){
		cout<<0<<endl;
	}
	else{
		cout<<save.size()<<endl;
		for(int i = 0 ; i< save.size() ; i++)
			cout<<save[i]<<" ";
	}
	return 0;
}