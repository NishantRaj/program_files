#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n , m;
		cin>>n>>m;
		int arr[m+9];
		for(int i = 0; i < m ;i ++)
			cin>>arr[i];
		sort(arr,arr+m);
		int j = m-1;
		vector<int> v;
		int i = 0,k=0;
		while( i<n && abs(arr[m-1] - i) >= abs(arr[0] - i )){
			v.push_back(abs(arr[j] - i));
			i++;
		}
		while(i<n && abs(arr[m-1] - i) <= abs(arr[0] - i ))
		{
			v.push_back(abs(arr[k] - i ));
			i++;
		}
		for(int i = 0; i< n ; i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;
}