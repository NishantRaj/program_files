#include <bits/stdc++.h>
using namespace std;
#define PDD pair<double,double>
#define MP make_pair
double distan(PDD a,PDD b)
{
	double dist;
	dist = sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
	return dist;
}
double slp(PDD a,PDD b)
{
	double slope;
	if(a.first != b.first)
	{
		slope =(b.second - a.second)/(b.first - a.first);
		return slope;
	}
	else 
		return INT_MAX;
}
int main()
{
	int n,p,q;
	scanf("%d",&n);
	set< PDD > s;
	set< PDD >::iterator t,k,temp1,temp,ch;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p,&q);
		s.insert(MP((double)p,(double)q));
	}
	int flag = 2;
	for(t = s.begin();t!=s.end();t++)
	{
		for(k = s.begin();k!=s.end();k++)
		{
			PDD first,second;
			first = (*t);
			second = (*k);
			if(first != second){
				double dist = distan(first,second);
				double xc,yc,xd,yd,x3,y3,x4,y4;
				xc = (first.first + second.first)/2.0;
				yc = (first.second + second.second)/2.0;
				xd = (first.first - second.first)/2.0;
				yd = (first.second - second.second)/2.0;
				x3 = xc - yd;
				y3 = yc + xd;
				x4 = xc + yd;
				y4 = yc - xd;
				temp = s.find(MP(x3,y3));
				temp1 = s.find(MP(x4,y4));
				if(temp != s.end() && temp1 != s.end()){
					flag = 0;
					break;
				}
				else if(temp1!= s.end() || temp!=s.end())
					flag = 1;
			}
		}
		if(flag == 0)
			break;
	}
	int length = s.size();
	if(length==0)
		printf("4\n");
	else if(length == 1)
		printf("3\n");
	else if(length==2)
		printf("2\n");
	else
		printf("%d\n",flag);
	return 0;
}