#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[1009],m[1009];
	scanf("%s",s);
	scanf("%s",m);
	int lens=strlen(s),lenm=strlen(m);
	int a[30]={0},b[30]={0};
	for(int i=0;i<lens;i++)
		a[s[i] - 97]++;
	for(int i=0;i<lenm;i++)
		b[m[i]-97]++;
	int sum=0,temp;
	for(int i=0;i<26;i++)
	{
		if(a[i])
		{
			temp=min(a[i] , b[i]);
			sum+=temp;
		}
		else if(a[i]==0 && b[i]!=0)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",sum);
	return 0;

}