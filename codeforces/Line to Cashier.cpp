#include <bits/stdc++.h>
int main()
{
	int n;
	scanf("%d",&n);
	int num[109];
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	int item[109][109],total[109]={0},temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<num[i];j++){
			scanf("%d",&temp);
			total[i] += temp * 5;
		}
		total[i]+=15*num[i];
	}
	std::sort(total,total+n);
	printf("%d\n",total[0]);
	return 0;
}