#include <bits/stdc++.h>
using namespace std;
vector<int> v[100009];
int main(){
	int n , k , temp , inp;
	scanf("%d%d" , &n , &k);
	for(int i = 0 ; i < k ; i++){
		scanf("%d" , &temp);
		for(int j = 0 ; j < temp ; j++){
			scanf("%d" , &inp);
			v[i].push_back(inp);
		}
	}
	int total_time = 0, block_count = 0 , largest = 0;
	for(int i = 0; i < k ; i++){
		int flag = 0;
		for(int j = 0 ; j < v[i].size() && flag == 0; j++){
			if(j+1 < v[i].size() && v[i][j+1] != v[i][j]+1){
				flag = 1;
			} 
		}
		if(flag){
			block_count += v[i].size();
			total_time += v[i].size()-1;
		}
		else{
			block_count += 1;
		}

	}
	cout<<total_time + block_count - 1<<endl;
	return 0;
}