#include <bits/stdc++.h>
using namespace std;
int n , arr[1009];
bool check_array(){
	for(int i = 0 ; i <n ; i++){
		if(arr[i] != i)
			return false;
	}
	return true;
}
int main(){
	scanf("%d" , &n);
	for(int i = 0; i < n ; i++)
		scanf("%d",&arr[i]);
	int flag =0;
	if(check_array())
		flag = 1;
	for(int i = 0 ; i< n && flag == 0; i++){
		for(int j = 0 ; j<n ; j++){
			if(j&1){
				arr[j] = (arr[j]-1 + n)%n;
			} else 
			arr[j] = (arr[j]+1)%n;
		}
		if(check_array())
			flag = 1;
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}