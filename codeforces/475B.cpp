#include <bits/stdc++.h>
using namespace std ;
int check[30][30];
int main()
{
	int n , m;
	cin>>n>>m;
	string sh , sv;
	cin>>sh>>sv;
	int flag = 0;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++){
			queue<pair<int , int > > q;
			q.push(make_pair(i , j));
			flag = 0;
			memset(check , 0 , sizeof check);
			while(!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				if(!check[x][y])
				{
					if(sh[x] == '>' && y < m-1)
						q.push(make_pair(x , y+1));
					else if(sh[x] == '<' && y > 0 )
						q.push(make_pair(x , y-1));
					if(sv[y] == '^' && x > 0)
						q.push(make_pair(x-1 , y));
					else if(sv[y] == 'v' && x < n-1)
						q.push(make_pair(x + 1 , y ));
				}
				q.pop();
				check[x][y] = 1;
			}
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < m ; j++)
				{
					if(check[i][j] == 0)
					{
						flag = 1 ; 
						break;
					}
				}
				if(flag == 1)
					break;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			break;
	}
	if(flag)
		cout<<"NO\n";
	else
		cout<<"YES\n";
	return 0;
}