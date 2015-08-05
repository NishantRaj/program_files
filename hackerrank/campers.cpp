#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[2000009];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n , k;
    cin>>n>>k;
    for(int i = 0 ; i < k ; i++){
        int temp;
        cin>>temp;
        if(temp>=2){
            arr[temp] = arr[temp-1] = arr[temp+1] = 1;
        }else{
            arr[temp] = arr[temp+1] = 1;
        }
    }
    int count = k;
    for(int i =1 ; i<= n ; i++){
        if(!arr[i]){
            count++;
            arr[i] = arr[i+1] = arr[i-1] = 1;
        }
    }
    cout<<count<<endl;
    return 0;
}
