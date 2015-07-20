#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int main(){
	int q , k ;
	cin>>q;
	map<long long ,pair< int , int > > m;
	map<long long ,pair< int , int > >::iterator it;
	m[1] = mp(0 , 0);
	k = 1;
	while(q--){
		int t , p;
		long long n;
		cin>>t;
		if(t==1){
			cin>>n>>p;
			m[n] = mp(p , k);
			k++;
		}
		int temp = -1;
		if(t==2){
			cin>>n;
			int color = 0;
			while(n >= 1){
				it = m.find(n);
				if(it != m.end()){
					if(it->second.second > temp){
						temp = it->second.second;
						color = it->second.first;
					}
				}
				n>>=1;
			}
			cout<<color<<endl;
		}
	}
	return 0;
}
