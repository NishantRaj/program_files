#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d ",&t);
	for(int test = 1 ; test <= t ; test++){
		int n;
		double v,x;
		cin>>n>>v>>x;
		double v1 , v2 , x1 ,x2;
		double ti1=99999999.0 , ti2=99999999.0 , ti3=99999999.0;
		if(n==2){
			cin>>v1>>x1>>v2>>x2;
			double ti = v/(v1+v2);
			double temp = ti*(v1*x1 + v2*x2);
			if (temp == (x*v))
			{
				ti1 = ti;
			}
			if(x == x1){
				ti = v/v1;
				ti2 = ti;
			}
			if(x == x2)
			{
				ti = v/v2;
				ti3 = ti;
			}
			if(ti1 == 99999999.0 && ti2 == 99999999.0 && ti3 == 99999999.0){
				printf("Case #%d: IMPOSSIBLE\n",test);
			}
			else{
				printf("Case #%d: %0.9lf\n",test,min(ti1 , min(ti2 , ti3)));
			}
		}
		else if(n==1){
			cin>>v1>>x1;
			if(x1 == x){
				double ti = v/v1;
				printf("Case #%d: %0.9lf\n",test,ti);
			}
			else
				printf("Case #%d: IMPOSSIBLE\n",test);
		}
	}
	return 0;
}