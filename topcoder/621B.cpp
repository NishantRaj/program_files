#include <bits/stdc++.h>
using namespace std;
bool comapre(const int &a , const int &b)
class NumberChallenge
{
public:
	int MinNumber(int s[] , int len)
	{
		int arr[(1<<(len + 1) + 9];
		for(int i = 1 ; i <= (1<<(len+1)) ; i++)

		sort(v.begin() , v.end());
		for(int i = 0 ; i < v.size() ; i++)
			cout<<v[i]<<" ";
		cout<<endl;
		for(int i =1 ; i < v.size() ; i++)
		{
			if(v[i] - v[i-1] > 1)
				return v[i-1] + 1; 
		}
		return v[v.size() - 1] + 1;
	}
};
int main()
{
	int n ; 
	cin>>n;
	int arr[n+9];
	for(int i = 0 ; i  < n ; i++)
	{
		cin>>arr[i];
	}
	NumberChallenge res;
	cout<<res.MinNumber(arr , n)<<endl;
	return 0;
}