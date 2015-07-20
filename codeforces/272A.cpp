#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int min_step;
	min_step = n/2;
	if(n&1)
		min_step +=1;
	int max_step = n,save,flag = 0;
	for(int i = min_step;i<=max_step;i++)
		if(i%m==0)
		{
			save = i;
			flag = 1;
			break;
		}
	if(flag == 1)
		cout<<save<<endl;
	else
		cout<<-1<<endl;
	return 0;
}