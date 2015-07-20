#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n+9],res[n+9];
	memset(res,0,sizeof res);
	cin>>arr[0];
	res[0] = arr[0];
	for(int i=1;i<n;i++){
		cin>>arr[i];
		res[i]= res[i-1] + arr[i];
	}
	int m;
	cin>>m;
	while(m--)
	{
		int num;
		cin>>num;
		int pos = lower_bound(res,res + n,num) - res;
		//cout<<pos<<endl;
		if(res[pos] >= num)
			cout<<pos+1<<endl;
		else
			cout<<pos+2<<endl;
	}
	return 0;
}