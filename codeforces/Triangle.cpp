#include <bits/stdc++.h>
#define LL long long
using namespace std;
bool check[5000]={false};
class hold
{
public:
	int b,p;
};
hold pythogras[3000];
void pre()
{
	LL temp,temp1;
	for(LL i=1;i<=1000;i++)
	{
		for(LL j=i+1;j<=1000;j++)
		{
			temp = i*i + j*j;
			temp1= sqrt(temp);
			if(temp1 * temp1 == temp){
				pythogras[temp1].b=i;
				pythogras[temp1].p=j;
				check[temp1]=true;
			}
		}
	}
}
void c(int array[],int a,int b)
{
	int d=(a*a+b*b);
	int temp=(array[0]-array[2])*(array[0]-array[2])+(array[1]-array[3])*(array[1]-array[3]);
	
	if (temp==d)
	{
		printf("YES\n");
		printf("%d %d\n",0,0);
		printf("%d %d\n",array[0],array[1]);
		printf("%d %d\n",array[2],array[3]);
		return;
	}
	printf("NO\n");
}
int main()
{
	int a,b,temp,temp1;
	pre();
	int array[4];
	/*for(int i=1;i<=1000;i++)
		if(check[i])
		cout<<i<<"   "<<pythogras[i].b<<"   "<<pythogras[i].p<<endl;*/
	scanf("%d%d",&a,&b);
	if(check[a] && check[b])
	{
		
		if(pythogras[a].b<pythogras[a].p)
			{array[0]=pythogras[a].b;array[1]=pythogras[a].p;}
		else
			{array[0]=pythogras[a].p;array[1]=pythogras[a].b;}
		if(pythogras[b].b<pythogras[b].p)
			{array[2]=-1*pythogras[b].p;array[3]=pythogras[b].b;}
		else
			{array[2]=-1*pythogras[b].b;array[3]=pythogras[b].p;}
		c(array,a,b);
	}
	else
		printf("NO\n");
	return 0;
}