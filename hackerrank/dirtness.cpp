#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        int arr[n+9];
        for(int i = 1 , j = n , k = 1; i <= n ;j--, i+=2 , k++){
            arr[i] = k;
            arr[i+1] = j;
        }
        if(n&1){
            arr[n] = n/2+1;
        }
        /*for(int i=1 ; i<= n ; i++)
            cout<<arr[i]<<" ";
        cout<<endl;*/
        if(m%n == 0){
            cout<<arr[n]<<" "<<m/n-1<<endl;
        } else{
            if(n&1){
                if(m <= n){
                    cout<<arr[m]<<" "<<0<<endl;
                } else{
                    if((m/n)%2==1){
                        if(m&1)
                            cout<<arr[m%n - 1]<<" "<<m/n<<endl;
                        else
                            cout<<arr[m%n + 1]<<" "<<m/n<<endl;
                    } else{
                        cout<<arr[m%n]<<" "<<m/n<<endl;
                    }
                }
            } else{
                cout<<arr[m%n]<<" "<<m/n<<endl;
            }
        }
    }
    return 0;
}
