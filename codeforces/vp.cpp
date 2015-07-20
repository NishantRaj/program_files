#include <bits/stdc++.h>
using namespace std;
int main()
{
	string store[3];
	store[0] = "qwertyuiop";
	store[1] = "asdfghjkl;";
	store[2] = "zxcvbnm,./";
	char pos;
	string s;
	cin>>pos>>s;
	for(int i=0;i<s.size();i++)
	{
		if(pos == 'R')
		{
			int flag = 0;
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<store[j].size();k++)
				{
					if(store[j][k] == s[i]){
						cout<<store[j][k-1];
						flag = 1;
						break;
					}
				}
				if(flag == 1)
					break;
			}
		}
		else
		{
			int flag = 0;
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<store[j].size();k++)
				{
					if(store[j][k] == s[i]){
						cout<<store[j][k+1];
						flag = 1;
						break;
					}
				}
				if(flag == 1)
					break;
			}
		}
	}
	cout<<endl;
	return 0;
}