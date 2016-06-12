/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 03 June 2016 (Friday) 19:19
===================================================*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n , q;
	scanf("%d%d",&n,&q);
	int arr[n+9];
	int mi = INT_MAX , ma = INT_MIN;
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&arr[i]);
		mi = min(mi , arr[i]);
		ma = max(ma , arr[i]);
	}
	while(q--){
		int t;
		scanf("%d",&t);
		if(t >= mi && t<= ma)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}