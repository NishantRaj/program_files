#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int arr[50];
	int k = 0;
	arr[k++] = a*b*c;
	arr[k++] = a*(b+c);
	arr[k++] = (a+b)*c;
	arr[k++] = a+b+c;
	sort(arr,arr+k);
	cout<<arr[k-1]<<endl;
	return 0;
}