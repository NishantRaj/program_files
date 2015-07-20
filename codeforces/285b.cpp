#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int main(){
	int n;
	cin>>n;
	string old , changed;
	vector<pair<string , string> > v;
	map<string , string> m ;
	map<string , int> mark;
	map<string , string> ::iterator t , t2;
	for(int i = 0 ; i < n ; i++){
		cin>>old>>changed;
		mark[old] = 0;
		mark[changed] = 0;
		v.pb(mp(old , changed));
		m[old] = changed;
	}
	map<string , string> res;
	for(int i = 0  ; i<v.size() ; i++){
		string s = v[i].first;
		t2 = m.find(s);
		int temp;
		while( t2!=m.end() && (temp=mark[t2->first])==0){
			mark[t2->first] = 1;
			t = t2;
			t2 = m.find(t2->second);
		}
		res[s] = t->second;
	}
	cout<<res.size()<<endl;
	for(t = res.begin() ; t!=res.end() ; t++)
		cout<<t->first<<" "<<t->second<<endl;
	return 0;
}