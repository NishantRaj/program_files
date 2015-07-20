#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	pair<int , int> arr[n+9];
	for(int i = 0; i < n ; i++)
		cin>>arr[i].first>>arr[i].second;
	sort(arr,arr+n);
	int flag = 0;
	int cur = arr[0].second;
	for(int i = 1; i < n ; i ++)
	{
		if(cur <= arr[i].second )
			cur = arr[i].second;
		else
			cur = arr[i].first;
	}
	cout<<cur<<endl;
	return 0;
}