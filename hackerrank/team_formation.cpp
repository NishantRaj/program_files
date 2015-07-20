#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n+9];
		for(int i = 0 ; i < n ; i++)
			cin>>arr[i];
		sort(arr , arr + n );
		int i = 0  , count = 0 , mi = 999999999;
		while(i < n-1)
		{
			if(arr[i+1] - arr[i] == 1)
			{
				i++;
				count++;
			}
			else
			{
				
			}
		}
	}
}