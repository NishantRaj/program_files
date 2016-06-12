/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 03 June 2016 (Friday) 21:54
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
char res[5] = {'0' , '2' , '4' , '6' , '8'};
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll num;
		scanf("%lld",&num);
		num--;
		if(num == 0){
			printf("0\n");
			continue;
		}
		vector<char> v;
		while(num){
			v.pb(res[num%5]);
			num/=5;
		}
		for(int i = v.size()-1 ; i>=0 ; i--)
			printf("%c",v[i]);
		printf("\n");
	}
	return 0;
}