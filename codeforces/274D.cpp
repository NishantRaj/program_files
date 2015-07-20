#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n , l , x, y;
	cin>>n>>l>>x>>y;
	map<int,int> mp , orignal;
	map<int,int> :: iterator t , t2, t3 , t1;
	int arr[n+9];
	for(int i = 0; i < n ; i++){
		cin>>arr[i];
		if(arr[i] + x <= l)
			mp[arr[i] + x] += 1;
		if(arr[i] - y >= 0)
			mp[arr[i] - y] +=1;
		if(arr[i] - x >= 0)
			mp[arr[i] - x] +=1;
		if(arr[i] + y <= l)
			mp[arr[i] +y] +=1;
		orignal[arr[i]] = 1;
	}
	int flag = 0 , flag1 = 0;
	for(int i = 0 ;i < n ; i++)
	{
		t = orignal.find(arr[i] + x);
		if(t!=mp.end())
			flag = 1;
		t1 = orignal.find(arr[i] + y);
		if(t1!=orignal.end()){
			flag1 = 1;
		}
	}
	if(flag==1 && flag1==1)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i = 0; i < n ; i++)
	{
		t = mp.find(arr[i] + x + y);
		t1 = mp.find(arr[i] + x - y);
		t2 = mp.find(arr[i] -x + y);
		t3 = mp.find(arr[i] - x - y);
		if(t!= mp.end() || t2!=mp.end() || t3!= mp.end() || t1!=mp.end())
		{
			cout<<1<<endl;
			if(t!=mp.end())
				cout<<t->first<<endl;
			else if(t1!=mp.end())
				cout<<t1->first<<endl;
			else if(t2!=mp.end())
				cout<<t2->first<<endl;
			else if(t3!=mp.end())
				cout<<t3->first<<endl;
			return 0;
		}
	}
	cout<<2<<endl;
	cout<<x<<" "<<y<<endl;
	return 0;
}