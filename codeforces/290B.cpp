#include <bits/stdc++.h>
using namespace std;
string grid[100];
int check[59][59] , n ,m;
const int px[4] = {1 , -1 , 0 , 0};
const int py[4] = {0 , 0 , -1 , 1};
bool valid(int i , int j){
	if(i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false;
}
int hld = 0;
void dfs(int i , int j , int start_x , int start_y , int count){
	check[i][j] = 1;
	if(count >= 2)
		check[start_x][start_y] = 0;
	for(int k = 0 ; k < 4 ; k++){
		int x = i + px[k] , y = j + py[k];
		if(valid(x , y) && !check[x][y] && grid[x][y] == grid[i][j]){
			cout<<x<<" "<<y<<" "<<start_x<<" "<<start_y<<endl;
			if(x == start_x && y== start_y && hld == 0){
				hld = 1;
				return ;
			}
			check[x][y] = 1;
			dfs(x , y , start_x , start_y);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++)
		cin>>grid[i];
	int flag = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			for(char k = 'A' ; k<= 'Z' ; k++){
				memset(check , 0 , sizeof check);
				if(grid[i][j] == k){
					hld = 0;
					dfs(i , j , i , j);
					if(hld){
						flag = 1;
						break;
					}
				}
			}
			if(flag == 1)
				break;
		}
		if(flag)
			break;
	}
	if(flag)
		cout<<"Yes\n";
	else 
		cout<<"No\n";
	return 0;
}
