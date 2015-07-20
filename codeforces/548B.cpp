#include <bits/stdc++.h>
using namespace std;
int main(){
	int n , m , q;
	cin>>n>>m>>q;
	int arr[n+9][m+9];
	int score[n+9];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++)
			cin>>arr[i][j];
	}
	int total_ans = 0;
	for(int i = 0 ; i < n ; i++){
		int sum = 0 , flag = 0;
		if(arr[i][0] == 1)
			sum = 1 , flag = 1;
		int res = -1;
		for(int j = 1 ; j < m ; j++){
			if(arr[i][j] == 1 && flag)
				sum++;
			else if(arr[i][j] == 0){
				res = max(res , sum);
				sum= 0 , flag = 0;
			}
			else if(flag == 0 && arr[i][j] == 1)
				sum = 1 , flag = 1;
		}
		res = max(res , sum);
		score[i] = res;
	}
	// for(int i = 0 ; i < n ; i++)
	// 	cout<<score[i]<<" ";
	// cout<<endl;
	while(q--){
		int p , q;
		cin>>p>>q;
		p-- , q--;
		arr[p][q] = !arr[p][q];
		int sum = 0 , flag = 0;
		if(arr[p][0] == 1)
			sum = 1 , flag = 1;
		int res = -1;
		for(int j = 1 ; j < m ; j++){
			if(arr[p][j] == 1 && flag)
				sum++;
			else if(arr[p][j] == 0){
				res = max(res , sum);
				sum= 0 , flag = 0;
			}
			else if(flag == 0 && arr[p][j] == 1)
				sum = 1 , flag = 1;
		}
		res = max(res , sum);
		score[p] = res;
		total_ans = -1;
		for(int i = 0 ; i < n ; i++){
			total_ans = max(total_ans , score[i]);
		}
		cout<<total_ans<<endl;
	}
	return 0;
}