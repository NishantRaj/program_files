#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
int main()
{
	int n,k,temp;
	cin>>n>>k;
	pair<int,int> arr[n+9];
	for(int i = 0; i < n ; i++){
		cin>>temp;
		arr[i] = MP(temp,i+1);
	}
	vector<pair<int ,int > > v;
	int res, stp = 0 , flag = 0 ,save;
	while(k--)
	{
		sort(arr,arr+n);
		if(arr[n-1].first - arr[0].first > 1){
			stp++;
			arr[0].first++;
			arr[n-1].first--;
			v.push_back(MP(arr[n-1].second , arr[0].second));
		}
	}
	sort(arr,arr+n);
	if(!flag)
	{
		cout<<arr[n-1].first - arr[0].first<<" "<<stp<<endl;
		for(int i = 0; i < v.size() ; i++)
			cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}