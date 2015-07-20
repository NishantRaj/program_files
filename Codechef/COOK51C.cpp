#include <bits/stdc++.h>
using namespace std;
long long fact(int a)
{
	long long res=  1;
	if(a==0)
		return 1;
	for(int i = 0 ; i< a ; i ++)
		res *= res;
	return res;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[(1<<n) + 9];
		map<int,int> mp;
		map<int,int>::iterator t;
		for(int i = 0; i < (1<<n) ; i++){
			cin>>arr[i];
			mp[arr[i]] +=1;
		}
		sort(arr,arr+(1<<n));
		int count = mp[0],save;
		for(int i = 0 ; i <= 15 ; i ++)
		{
			if(count == (1<<i)){
				save = i;
				break;
			}
		}
		int j = 0;
		for(int i = 0; i < save ; i++){
			j++;
			cout<<0<<" ";
		}
		vector<int> v;
		int hold = (1<<save);
		int i = (1<<save) + 1, k = 0 ,total = 1 , flag  = 0 , f = 1;
		v.push_back(arr[i]);
		while(total < n)
		{
			if(arr[i] == v[total] ){
				while(arr[i] == v[total - 1] )
				{
					if(f == 1){
						v.push_back(arr[i]);
						total++;
						if(total>=n)
						{
							flag = 1;
							break;
						}
					}
					i++;
				}
				f = 0;
			}
			cout<<i<<" h "<<hold<<endl;
			/*if(i - hold == 1)
			{
				v.push_back(arr[i]);
				total++;
				if(total >= n)
				{
					flag = 1;
					break;
				}
				i++;
			}*/
			for(int l = 2 , m = 0; m < i - hold ; m++,l++)
			{
				cout<<i - hold<<endl;;
				t = mp.find(arr[i-1]*l);
				int diff = t->second - fact(n)/(fact(n-l)*fact(l));
				cout<<t->second<<" "<<diff<<endl;
				if(diff > 0 && total < n)
				{
					while(diff >=0){
						v.push_back(arr[i-1]*l);
						total++;
						if(total >=n)
						{
							flag = 1;
							break;
						}
						diff--;
					}
				}
				if(flag)
					break;
			}
			cout<<total<<" "<<i<<endl;
			hold = i - 1;
			if(flag)
				break;
		}
		for(int i = 0; i < n ; i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;
}