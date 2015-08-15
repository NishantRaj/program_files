#include <bits/stdc++.h>
using namespace std;
long double sqrt_(long double x){
	long double low = 0.0 , high = x , mid , prev = 0.0;
	while(low < high){
		mid = (low + high)/2.0;
		if(mid*mid <= x){
			low = mid;
			if(prev - mid < 1e-11)
				return mid;
		}
		else
			high = mid;
	}
	return low;
}
int main(){
	long double x , y , va , vb , t ,x_ , y_ , d;
	cin>>x>>y>>va>>vb;
	t = (va*x + vb*y)/(va*va + vb*vb);
	x_ = x - va*t;
	y_ = y - vb*t;
	d = x_*x_ + y_*y_;
	d = sqrt(d);
	if(d == 0.0)
		cout<<fixed<<setprecision(1)<<0.0<<endl;
	else
		cout<<fixed<<setprecision(20)<<d<<endl;
	return 0;
}