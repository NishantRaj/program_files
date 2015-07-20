//incomplete!!
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n , a , b;
	cin>>n>>a>>b;
	map<int , int> mp , hold;
	map<int , int> ::iterator t;
	int arr[n+9];
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
		mp[arr[i]] = 1;
	}
	int flag = 0;
	for(int i = 0 ; i < n ; i++)
	{
		flag = 0;
		if(mp[a - arr[i]] == 1) flag+=1;
		if(mp[b - arr[i]] == 1) flag+=2;
		if(flag == 0)
		{
			cout<<"NO\n";
			return 0;
		}
		else if(flag == 2 || flag == 3)
		{
			mp[b-arr[i]] = 0;
			hold[arr[i]] = 1;
			hold[b-arr[i]] = 1;
		}
		else
		{
			mp[a-arr[i]] = 0;
			hold[a-arr[i]] = 0;
			hold[arr[i]] = 0;
		}
	}
	cout<<"YES\n";
	for(int i = 0 ; i < n ; i++)
		cout<<hold[arr];
	return 0;
}