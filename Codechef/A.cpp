#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
int main(){

	int t;
	scanf("%d",&t);
	while(t--){
		char s[100009];
		scanf("%s",s);
		int len = strlen(s);
		if(len == 1){
			int diff_from_start = s[0] - 48 ;
			int diff_from_end = 9 - (s[0] - 48);
			if((s[0] - 48)%9==0)
				cout<<0<<endl;
			else
				cout<<min(diff_from_end , diff_from_start)<<endl;
			continue;
		}
		int total = s[0]-48;
		int higher = 9 - (s[0] - 48);
		int lower = s[0] - 48 - 1;
		for(int i = 1 ; i < len ; i++){
			lower += (s[i] - 48) ;
			higher += 9 - (s[i] - 48);
			total += s[i]-48;
		}
		int lower_divisible = (total/9)*9;
		int higher_divisible = (total/9 + 1)*9;
		int lowe_diff = total - lower_divisible;
		int higher_diff = higher_divisible - total;
		int flag= 0 , flag1 = 0;
		int ans ;
		if(total % 9 == 0){
			ans = 0;
		}
		else if(lowe_diff <= lower && higher_diff <= higher)
			ans = min(lowe_diff , higher_diff);
		else if(lowe_diff > lower && higher_diff <= higher)
			ans = higher_diff;
		else if(lowe_diff <= lower && higher_diff > higher)
			ans = lowe_diff;
		printf("%d\n",ans);
	}
	return 0;
}