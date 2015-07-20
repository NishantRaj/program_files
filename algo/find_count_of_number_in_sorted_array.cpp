#include <bits/stdc++.h>
using namespace std;
int count(int arr[],int k,int n)
{
	int p=-1,q = -1;
	for(int a = n ; a>0 ; a/=2){
		while(p+a < n && arr[p+a] < k) p+=a;
		while(q+a < n && arr[q+a] <= k) q+=a;
	}
	return (q-p);
}
int main()
{
	int n;
	cin>>n;
	int arr[n+9];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	int q,k;
	cin>>q;
	while(q--)
	{
		cin>>k;
		cout<<count(arr,k,n)<<endl;
	}
	return 0;
}