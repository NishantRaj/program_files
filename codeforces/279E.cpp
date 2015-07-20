//Not complete!!!!
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s[n+9];
	for(int i = 0 ; i < n ; i++)
		cin>>s[i];
	if(s[0][0] == '?')
		s[0][0] = '1';
	for(int i = 1 ; i < s[0].size() ; i++)
	{
		if(s[0][i] == '?' && i)
			s[0][i] = '0';
	}
	for(int i = 1 ; i < n ; i ++)
	{
		if(s[i].size() == s[i-1].size())
		{
			for(int j = 0 ; j < s[i].size() ; j++){
				if(s[i][j] == '?'){
					char c = min(s[i-1][j] - 48 +1 , 9) + 48;
					s[i][j] = c;
				}
			}
			if( s[i] < s[i-1])
			{
				cout<<"NO\n";
				return 0;
			}
		}
		else if(s[i].size() < s[i-1].size() )
		{
			cout<<"NO\n";
			return 0;
		}
		else if(s[i].size() > s[i-1].size())
		{
			if(s[i][0] == '?')
				s[i][0] = '1';
			for(int j = 1 ; j < s[i].size() ; j++){
				if(s[i][0] == '?')
					s[i][j] = '0';
			}
		}
	}
	cout<<"YES\n";
	for(int i = 0 ; i < n ; i++)
		cout<<s[i]<<endl;
	return 0;
}