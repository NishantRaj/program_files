#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string ans="";
		ans = ans + s[0];
		for(int i = 1 ; i < s.size() ; i++)
		{
			char c ;
			c = (s[i]-48)^(s[i-1]-48) + 48;
			ans = ans + c;
		}
		cout<<ans<<endl;
	}
	return 0;
}