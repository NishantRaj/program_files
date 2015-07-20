#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	long long sum = (long long)(n)*(n+1)/2;
	sum += n;
	cout<<sum<<endl;
}
	return 0;
}