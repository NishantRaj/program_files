#include <bits/stdc++.h>
using namespace std;
#define ll long long
int visited[10000009];
int reverse(int n){

	char arr[10];
	int i = 0 , num = 0;
	while(n){
		arr[i] = n%10 + 48;
		n = n/10;
		i++;
	}
	int size = i;
	i = 0;
	while(arr[i] == '0')
		i++;
	for(int j = i ; j< size ; j++)
		num  = num * 10 + arr[j]  - 48;
	return num;
}
ll large(ll n){
	if(n<= 10000000)
		return visited[n];
	ll rev;
	if(n%10 != 0 )
		rev = reverse(n);
	else
		rev = n;
	if(rev < n)
	return min(large(n-1) + 1 , large(rev) + 1);
}
int main(){
	int t ; 
	visited[1] = 1;
	for(int i = 2 ; i<= 10000000 ; i++){
		int  rev , min_rev = 99999999;
		if(i%10 != 0)
			rev = reverse(i);
		else
			rev = i;
		if(visited[rev] != 0)
			min_rev = visited[rev];
		visited[i] = min(visited[i-1] + 1 , min_rev + 1);
	}
	cin>>t;
	for(int test = 1 ; test<= t ; test ++){
		ll n;
		cin>>n;
		if(n <= 10000000)
			cout<<"Case #"<<test<<": "<<visited[n]<<endl;
		else
			cout<<"Case #"<<test<<": "<<large(n)<<endl;
	}
	return 0;
}