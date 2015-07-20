#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    int arr[n+9];
    int ma = INT_MIN;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      ma = max(ma,arr[i]);
    }
    int min_diff=0;
    for(int i=0;i<n;i++){
      min_diff += ma - arr[i];
    }
    if((m - min_diff)%n == 0)
      cout<<"Yes\n";
    else
      cout<<"No\n";
   }
  return 0;
}
