#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	long long res = 0;
	res = (6*(n-1) + 5)*k;
	cout<<res<<endl;
	for(int i = 0;i<n;i++)
		cout<<(6*i + 1)*k<<" "<<(6*i+2)*k<<" "<<(6*i + 3)*k<<" "<<(6*i + 5)*k<<endl;
	return 0;
}