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
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int arr1[109][109],arr2[109][109],arr3[109][109];
	memset(arr1,0,sizeof(arr1[0][0])*(n+1)*(m+1));
	memset(arr2,0,sizeof(arr2[0][0])*(n+1)*(m+1));
	memset(arr3,0,sizeof(arr3[0][0])*(n+1)*(m+1));
	int row,column,count_row=0,count_column = 0;
	for(int i=0;i<k;i++)
	{
		cin>>row>>column;
		arr1[row-1][column-1] = 1;
		arr2[row-1][column-1] = 1;
		arr3[row-1][column-1] = 1;
	}
	int c1=0,c2=0,c3=0;
	vector<data> v1,v2,v3;
	vector<int> tmpa;
	v1 =  bfs(arr1,1,n,m,c1);
	tmpa.push_back(c1);
	v2 = bfs(arr2,0,n,m,c2);
	tmpa.push_back(c2);
	v3 = bfs1(arr3,n,m,c3);
	tmpa.push_back(c3);
	sort(tmpa.begin(),tmpa.end());
	cout<<tmpa[0]<<endl;
	if(tmpa[0] == c1){
		for(int i=0;i<v1.size();i++)
			cout<<v1[i].a<<" "<<v1[i].b<<" "<<v1[i].c<<endl;
	}
	else if(tmpa[0] == c2){
		for(int i=0;i<v2.size();i++)
			cout<<v2[i].a<<" "<<v2[i].b<<" "<<v2[i].c<<endl;
	}
	else{
		for(int i=0;i<v3.size();i++)
			cout<<v3[i].a<<" "<<v3[i].b<<" "<<v3[i].c<<endl;
	}
	return 0;
}