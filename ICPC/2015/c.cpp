/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 11 October 2015 (Sunday) 19:05
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	int t;
	scanf("%d",&t);
	while(t--){
		int n , k;
		scanf("%d%d" , &n , &k);
		if(k > n/2){
			printf("-1\n");
			continue;
		} else{
			int arr[n+9] , l = 0;
			memset(arr , 0 , sizeof arr);
			for(int i = 1 ; i<= n ; i++){
				if(i + k <= n)
					arr[l] = i+k;
				else
					arr[l] = (i+k)%n;
				l++;
			}
			if(k == 0){
				for(int i = 0 ; i < n ; i++)
					printf("%d ", arr[i]);
				printf("\n");
			} else{
				for(int i = 0 , j = n-k ; i < k ;j++, i++){
					if(abs(arr[i+k] - (j+1)) >= k && abs(arr[j] - i+k) >= k && arr[j] < arr[i+k])
						swap(arr[i+k] , arr[j]);
				}
				for(int i = 0 ; i < n ; i++)
					printf("%d ", arr[i]);
				printf("\n");
			}
			continue;
		}
	}
	return 0;
}