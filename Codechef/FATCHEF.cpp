#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,pos;
		scanf("%d%d",&n,&m);
		char c;
		int check[n+9];
		memset(check,0,sizeof(check));
		for(int i=0;i<m;i++)
		{
			scanf(" %c%d",&c,&pos);
			check[pos] = int(c);
		}
		long long total = 1;
		int i=1,save=0;
		while(check[i]==0){
			i++;
			save = i;
		}
		for(int j = save+1 ;j<=n;j++)
		{
			if(check[j] != 0)
			{
				if(check[save] != check[j] )
					total = (total*(j-save))%MOD;
				save = j;
			}
		}
		printf("%lld\n",total);
	}
	return 0;
}