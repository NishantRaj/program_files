/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 04 June 2016 (Saturday) 07:50
===================================================*/
#include <bits/stdc++.h>
using namespace std;
char a[1000009] , b[1000009];
int main(){
	int t;
	scanf("%d ",&t);
	while(t--){
		scanf("%s %s",a , b);
		int len = strlen(a);
		int res[2][2];
		memset(res , 0 , sizeof res);
		int a_ones = 0, a_zeros = 0, b_ones = 0, b_zeros = 0;
		for(int i = 0 ; i < len ; i++){
			int x = -1, y =-1;
			if(a[i] == 49){
				a_ones++;
				x = 0;
			} else {
				a_zeros++;
				x = 1;
			}
			if(b[i] == 49){
				b_ones++;
				y = 0;
			} else{
				b_zeros++;
				y = 1;
			}
			res[x][y]++;
		}
		if((a_ones == 0 && b_ones != 0) || (a_zeros == 0 && b_zeros !=0)){
			printf("Unlucky Chef\n");
			continue;
		}
		printf("Lucky Chef\n%d\n", max(res[1][0] , res[0][1]));
	}
	return 0;
}