#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
class node{
public:
	int x , y;
	node(){}
	node(int i , int j){
		x = i;
		y = j;
	}
};
node Hash[1000009];
int main(){
	int n;
	cin>>n;
	int table[n+9][n+9];
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++){
			cin>>table[i][j];
			Hash[table[i][j]] = node(i , j);
		}
	int diff_table[n+9][n+9];
	node p;
	long long res = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++){
			cin>>diff_table[i][j];
			p = Hash[diff_table[i][j]];
			res+= (p.x - i)*(p.x - i) + (p.y - j)*(p.y - j);
		}
	cout<<res<<endl;
	return 0;
}