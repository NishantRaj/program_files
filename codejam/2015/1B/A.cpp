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
int main(){
	int t;
	cin>>t;
	for(int test = 1 ; test <= t ; test ++){

		int n;
		cin>>n;
		memset(visited , 0 , sizeof visited);
		visited[1] = 1;
		queue<int> q;
		q.push(1);
		while(!q.empty()){

			int i = q.front();
			int rev = reverse(i);
			if(i == 1000000)
				break;
			if(!visited[i+1]){
				q.push(i+1);
				visited[i+1] = visited[i] + 1;
			}
			if(!visited[rev]){
				q.push(rev);
				visited[rev] = visited[i] + 1;
			}
			if(visited[i+1] != 0){
				visited[i+1] = min(visited[i+1] , visited[i]+1);
				
			}
			if(visited[rev]!=0)
				visited[rev] = min(visited[rev] , visited[i]+1);
			q.pop();
		}
		cout<<"Case #"<<test<<": "<<visited[n]<<endl;
	}
	return 0;
}