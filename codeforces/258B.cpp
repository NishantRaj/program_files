#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n+9] , org[n+9];
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
		org[i] = arr[i];
	}
	sort(arr , arr + n );
	int i = 0 , j = n -1 ;
	while(arr[i] == org[i] && i<n)
		i++;
	while(arr[j] == org[j] && j>=0)
		j--;
	bool flag = 0 ;
	for(int k = i , l = j ; k <= j ; k++ , l--){
		if(arr[k] != org[l])
		{
			flag = 1;
			break;
		}
	}
	if(flag){
		cout<<"no\n";
	}
	else {
		cout<<"yes\n";
		if(j == -1 && i == n)
			cout<<1<<" "<<1<<endl;
		else
			cout<<i+1<<" "<<j+1<<endl;
	}
	return 0;
}