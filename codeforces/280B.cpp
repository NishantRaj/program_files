#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n , l ;
	cin>>n>>l;
	int arr[n+9];
	for(int i = 0 ; i  < n ; i++)
		cin>>arr[i];
	sort(arr , arr+n);
	double ma1 = arr[0] - 0;
	double ma2=l - arr[n-1];
	double ma = -1;
	for(int i = 1 ; i< n ; i++)
	{
		double diff = arr[i] - arr[i-1];
		ma = max(ma , diff);
	}
	double res = max(ma1 ,max( ma/2.0  , ma2));
	printf("%0.9lf\n",res);
	/*if(ma1 > ma/2.0 && ma1 > ma2){
		printf("%0.9lf\n",ma1);
	}
	else if(ma2 > ma1 && ma2 > ma/2.0){
		printf("%0.9lf\n" , ma2);
	}
	else if(ma/2.0 > ma1 && ma/2.0 > ma2)
		printf("%0.9lf\n",ma1/2.0 );*/
	return 0;
}