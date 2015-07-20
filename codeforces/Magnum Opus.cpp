#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	istringstream iss(s);
	int a,b[109],i=0,d;
	while(iss>>a)
	{
		b[i++]=a;
	}
	d=b[1] - b[0];
	int w[5]={1,1,2,7,4};
	cout<<w[d-1];
	return 0;
}