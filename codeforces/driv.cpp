#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	string A;
	cin>>A;
	int ans = 0 , p = 1;
    for(int i = A.size() -1 , j=0 ; i>= 0 ; i-- , j++){
        ans += (A[i] - 64)*p;
        p *= 26;
    }
    cout<<ans<<endl;
	
	return 0;
}