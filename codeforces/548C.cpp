#include <bits/stdc++.h>
using namespace std;
#define ll long long
void exgcd(ll a,ll b,ll &x,ll &y)
{
    if (b) {exgcd(b,a%b,y,x);y-=x*(a/b);}
    else x=1,y=0;
}
ll gcd(ll a , ll b){
	return b == 0 ? a : gcd(a%b);
} 
int main(){
	ll m , h1 , a1 , x1 , y1 , h2 , a2 , x2 , y2;
	cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;

	ll arr[100000] , arr1[100000];
	ll first = (x1*h1 + y1)%m;
	arr[0] = h1 , arr1[0] = h2;
	int i = 1;
	map<ll , int> m1 , m2;
	m1[arr[0]] = 0;
	while(arr[0] != first ){
		arr[i] = first;
		m1[arr[i]] = i;
		//cout<<first<<" ";
		first = (x1*arr[i] + y1)%m;
		i++;

	}
	cout<<endl;
	i = 1;
	first = (x2*h2 + y2)%m;
	m2[arr1[0]] = 0;
	while(arr1[0] != first){
		arr1[i] = first;
		m2[arr1[i]] = i;
		//cout<<first<<" ";
		first = (x2*arr1[i] + y2)%m;
		i++;
	}
	//cout<<endl;
	auto t1 = m1.find(a1);
	auto t2 = m2.find(a2);
	if(t1 != m1.end() && t2 != m2.end()){
		ll size1 = m1.size() , size2 = m2.size();
		ll time1 = t1->second , time2 = t2->second;
		if(time1 > time2){
			swap(time2 , time1);
			swap(size1 , size2);
		}
		ll x , y;
		exgcd(size1 , size2 , x, y);
		ll gcd_val = gcd(size1 , size2);
		ll a , b ,c , p , q , r , diff = time2 - time1 ;
		if(diff % gcd_val !=0){
			cout<<-1<<endl;
			return 0;
		}
		ll count = diff / gcd_val;
		a = size1 / gcd_val;
		b = size2 / gcd_val;
		c = 0;
		p = x*count , q = -1*y*count , r = gcd_val*count;

		ll temp1 = (time1 - size1 - time2 + size2);
		ll temp2 = (size2 - size1);
		//cout<<temp1<<" "<<temp2<<endl;
		if(time1 == time2){
			cout<<time2<<endl;
			return 0;
		}
		if(temp2 > 0 && temp1 >=0 && temp1 % temp2 == 0){
			cout<<temp1/temp2<<endl;
			return 0;
		}
		if(temp2 < 0 && temp1 <=0 && (-1*temp1) % (-1*temp2) == 0)
		{
			cout<<(-1*temp1)/(-1*temp2)<<endl;
			return 0;
		}
		cout<<-1<<endl;

	}
	else{
		cout<<-1<<endl;
	}
	return 0;

}