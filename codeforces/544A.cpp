#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int k;
	string q;
	cin>>k>>q;
	int hash[26];
	memset(hash , 0 , sizeof hash);
	int total = 0;
	vector<int> index;
	for(int i = 0 ; i < q.size() ; i++)
		if(!hash[q[i]-97]){
			hash[q[i]-97] = 1;
			total++;
			index.pb(i);
		}
	int len; 
	if(total < k)
		cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		for(int i = 1 ; i<=k ; i++){
			if(i == k)
				len = q.size();
			else
				len = index[i];
			for(int j = index[i-1] ; j< len ; j++)
				cout<<q[j];
			cout<<endl;
		}
	}
	return 0;
}