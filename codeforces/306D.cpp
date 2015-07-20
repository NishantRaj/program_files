#include <bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin>>k;
	if(k == 1){
		cout<<"YES\n";
		cout<<2<<" "<<1<<endl;
		cout<<1<<" "<<2<<endl;
		return 0;
	}
	if(k&1){
		int node = (k+2)*2;
		int arr[node+9];
		memset(arr , 0 , sizeof arr);
		vector<int> graph[node+9];
		for(int i = 2 ; i <= k ; i++){
			graph[1].push_back(i);
			arr[1]++;
			arr[i]++;
		}
		for(int i = 2 ; i <= 2*k - 1 ; i++){
			while(arr[i] < k){
				//cout<<arr[i]<<" ";
				for(int j = i+1 ; j <= k+2 ; j++){
					auto it = find(graph[i].begin() , graph[i].end() , j);
					if(i!=j && arr[i] < k && arr[j] < k && it == graph[i].end()){
						graph[i].push_back(j);
						arr[j]++;
						arr[i]++;
					}
				}
			}
		}
		cout<<"YES\n";
		cout<<4*k-2<<" "<<(k-1)/2 + ((k+1)*k)/2<<endl;
		graph[1].push_back(k+2);
		for(int i = 1 ; i<= k+2 ; i++){
			for(int j = 0 ; j < graph[i].size() ; j++){
				cout<<i<<" "<<graph[i][j]<<endl;
			}
		}
		for(int i = 1 ; i<= k+2 ; i++){
			for(int j = 0 ; j < graph[i].size() ; j++){
				cout<<i+k+2<<" "<<graph[i][j]+k+2<<endl;
			}
		}
		cout<<k+2 <<" " <<(k+2)*2<<endl;
	}
	else
		cout<<"NO\n";
	return 0;
}