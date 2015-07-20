#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
struct data
{
	int a,b,c;
	data(){}
	data(int p,int q,int r)
	{
		a=p;
		b=q;
		c=r;
	}
};
vector<data> coq(int arr[][109],int n,int m,int part)
{
	vector<data> v;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<part;j++)
		{
			if(arr[i][j] == 0)
			{
				int p =i;
				v.push_back(data(i,j,1));
				while(p<n && arr[p][j]!=1)
					arr[p][j] = 1;
				while(p>=0 && arr[p][j]!=1)
					arr[p][j] = 1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j = part;j<m;j++)
		{
			if(arr[i][j] == 0)
			{
				int p=j;
				v.push_back(data(i,j,0));
				while(p<m && arr[i][p]!=1)
					arr[i][p] = 1;
				while(p>=0 && arr[i][p]!=1)
					arr[i][p] = 1;
			}
		}
	}
	return v;
}
vector<data> roq(int arr[][109],int n,int m,int part)
{
	vector<data> v;
	for(int i=0;i<part;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j] == 0)
			{
				int p=j;
				v.push_back(data(i,j,0));
				while(p<m && arr[i][p]!=1)
					arr[i][p] = 1;
				while(p>=0 && arr[i][p]!=1)
					arr[i][p] = 1;
			}
		}
	}
	for(int i = part;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(arr[i][j] ==0)
			{
				int p =i;
				v.push_back(data(i,j,1));
				while(p<n && arr[p][j]!=1)
					arr[p][j] = 1;
				while(p>=0 && arr[p][j]!=1)
					arr[p][j] = 1;
			}
		}
	}
	return v;
}
vector<data>  bfs(int arr[][109],int che,int n,int m,int &count)
{
	vector<data> v;
	count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j] == 0)
			{
				count++;
				v.push_back(data(i+1,j+1,che));
				if(che)
				{
					int temp = i;
					while(temp < n && arr[temp][j] == 0){
						arr[temp][j] = 1;
						temp++;
					}
				}
				else
				{
					int temp = j;
					while(temp < m && arr[i][temp] == 0){
						arr[i][temp] = 1;
						temp++;
					}
				}
			}
		}
	}
	return v;
}
vector<data> bfs1(int arr[][109],int n,int m,int &count)
{
	vector<data> v;
	count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j] == 0)
			{
				int l=0,r=0,u=0,d=0;
				int p,q;
				p = i;
				q = j;
				while(q>=0 && arr[i][q]==0)
				{
					l++;
					q--;
				}
				q = j+1;
				while(q<m && arr[i][q]==0)
				{
					r++;
					q++;
				}
				while(p>=0 && arr[p][j]==0)
				{
					u++;
					p--;
				}
				p = i+1;
				while(p<n && arr[p][j] == 0)
				{
					d++;
					p++;
				}
				if((l+r) > (u+d) )
				{
					count++;
					v.push_back(data(i+1,j+1,0));
					q = j-1;
					while(q>=0 && arr[i][q] == 0)
						arr[i][q] =1 , q--;
					q = j;
					while(q<m && arr[i][q] == 0)
						arr[i][q] = 1,q++;
				}
				else
				{
					count++;
					v.push_back(data(i+1,j+1,1));
					p = i;
					while(p>=0 && arr[p][j] == 0)
						arr[p][j] = 1, p--;
					p = i+1;
					while(p<n && arr[p][j] == 0)
						arr[p][j] = 1, p++;
				}
			}
		}
	}
	return v;
}
int color[101][101];
int wt[101][101][2];
int checkNS(int x, int y, int n)
{
	int count = 0;
	for(int i = x; i>0 && color[i][y]==0; ++count, i--);
	for(int i = x+1; i<=n && color[i][y]==0; ++count, i++);
	return count;
}
int checkEW(int x, int y, int m)
{
	int count = 0;
	for(int i = y; i>0 && color[x][i]==0; ++count, i--);
	for(int i = y+1; i<=m && color[x][i]==0; ++count, i++);
	return count;
}
void setNS(int x, int y, int n)
{
	for(int i = x; i>0 && color[i][y]==0; color[i][y] = 2, i--);
	for(int i = x+1; i<=n && color[i][y]==0; color[i][y] = 2, i++);
}
void setEW(int x, int y, int m)
{
	for(int i = y; i>0 && color[x][i]==0; color[x][i] = 2, i--);
	for(int i = y+1; i<=m && color[x][i]==0; color[x][i] = 2, i++);
}
pair<pair<int, int>, int> calc(int x, int y, int n, int m){
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(!color[i][j]){
				wt[i][j][0] = checkEW(i, j, m);
				wt[i][j][1] = checkNS(i, j, n);
			}
		}
	}
	int xx=0, yy=0, dd=-1, W = 0;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			for(int k = 0; k<=1; k++){
				if(!color[i][j] && W < wt[i][j][k]){
					W = wt[i][j][k];
					xx = i; yy = j; dd = k;
				}
			}
		}
	}
	return MP(MP(xx, yy), dd);
}
vector <data > solve(int n,int m)
{
	int k, x, y;
	vector <data > res;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			pair<pair<int, int>, int> p = calc(i, j, n, m);
			if(p.second == 0){
				setEW(p.first.first, p.first.second, m);
				res.push_back(data(p.first.first, p.first.second, p.second));
			}
			else if(p.second == 1){
				setNS(p.first.first, p.first.second, n);
				res.push_back(data(p.first.first, p.first.second, p.second));
			}
		}
	}
	return res;
}
vector<data> v[10];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int arr1[109][109],arr2[109][109],arr3[109][109],arr[109][109],hold[109][109];
	memset(arr1,0,sizeof(arr1[0][0])*(n+1)*(m+1));
	memset(arr2,0,sizeof(arr2[0][0])*(n+1)*(m+1));
	memset(arr3,0,sizeof(arr3[0][0])*(n+1)*(m+1));
	memset(arr,0,sizeof(arr3[0][0])*(n+1)*(m+1));
	memset(hold,0,sizeof(arr3[0][0])*(n+1)*(m+1));
	for(int i = 0; i<m; i++) color[0][i] = 1;
	for(int i = 0; i<n; i++) color[i][0] = 1;
	int row,column,count_row=0,count_column = 0;
	for(int i=0;i<k;i++)
	{
		cin>>row>>column;
		hold[row-1][column-1] = 1;
		arr1[row-1][column-1] = 1;
		arr2[row-1][column-1] = 1;
		arr3[row-1][column-1] = 1;
		color[row][column] = 1;
	}
	int c1=0,c2=0,c3=0,c4=0;
	//vector<data> v1,v2,v3;
	vector<pair<int,int> > tmpa;
	v[0] =  bfs(arr1,1,n,m,c1);
	tmpa.push_back(MP(c1,0));
	v[1] = bfs(arr2,0,n,m,c2);
	tmpa.push_back(MP(c2,1));
	v[2] = bfs1(arr3,n,m,c3);
	tmpa.push_back(MP(c3,2));
	v[3] = solve(n,m);
	c4 = v[3].size();
	tmpa.push_back(MP(c4,3));
	int bf = 4,lp = 4;
	for(int i = 1;i<=m;i++){
		memset(arr,0,sizeof(arr3[0][0])*(n+1)*(m+1));
		for(int k=0;k<n;k++)
			for(int j=0;j<m;j++)
				arr[k][j] = hold[k][j];
		v[bf] = coq(arr,n,m,i);
		int sx = v[bf].size();
		tmpa.push_back(MP(sx,lp));
		bf++;
		lp++;
	}
	for(int i=1;i<=n;i++)
	{
		memset(arr,0,sizeof(arr3[0][0])*(n+1)*(m+1));
		for(int k=0;k<n;k++)
			for(int j=0;j<m;j++)
				arr[k][j] = hold[k][j];
		v[bf] = roq(arr,n,m,i);
		int sx = v[bf].size();
		tmpa.push_back(MP(sx,lp));
		bf++;
		lp++;
	}
	sort(tmpa.begin(),tmpa.end());
	cout<<tmpa[0].first<<endl;
	for(int i=0;i<tmpa[0].first;i++)
		cout<<v[tmpa[0].second][i].a<<" "<<v[tmpa[0].second][i].b<<" "<<v[tmpa[0].second][i].c<<endl;
	return 0;
}