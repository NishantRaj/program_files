/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 03 June 2016 (Friday) 19:46
====================================================*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(n%6 == 0)
			printf("Misha\n");
		else
			printf("Chef\n");
	}
	return 0;
}