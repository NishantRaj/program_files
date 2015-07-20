#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ti;
	scanf("%d",&ti);
	while(ti--){
		char s[100009],t[100009];
		scanf("%s",s);
		scanf("%s",t);
		int m = strlen(s),n = strlen(t);
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		if(a==0)
		{
			printf("0\n");
			continue;
		}
		vector<int> v1(n+9),v2(n+9);
		if(k/a < abs(n-m))
		{
			printf("-1\n");
			continue;
		}
		int  p = ceil(0.5 * (((k+105)/a) - abs(n-m)));
		for(int i=0;i<=n;i++)
			v1[i] = i*a;
		int check = 1;
		for(int i=0;i<m;i++)
		{
			if(check==1)
				v2[0] = (i+1)*a;
			else
				v1[0] = (i+1)*a;
			if(n>=m)
			{
				for(int j = max(0,i-p);j<=min(n,i+(n-m)+p);j++)
				{
					int add ;
					if(s[i] == t[j] )
						add = 0;
					else
						add = b;
					if(check == 1)
						v2[j+1] = min(v2[j]+a,min(v1[j+1]+a,v1[j]+add));
					else
						v1[j+1] = min(v1[j]+a,min(v2[j+1]+a,v2[j]+add));
				}
			}
			else
			{
				for(int j = max(0,i+(n-m)-p);j<=min(n,i+p);j++)
				{
					int add ;
					if(s[i] == t[j] )
						add = 0;
					else
						add = b;
					if(check == 1)
						v2[j+1] = min(v2[j]+a,min(v1[j+1]+a,v1[j]+add));
					else
						v1[j+1] = min(v1[j]+a,min(v2[j+1]+a,v2[j]+add));
				}
			}
			if(check == 1)
				check = 0;
			else
				check = 1;
		}
		int ch;
		if(check == 0)
			ch = v2[n];
		else
			ch = v1[n];
		if(ch>k)
			printf("-1\n");
		else
			printf("%d\n",ch);
	}
	return 0;
}