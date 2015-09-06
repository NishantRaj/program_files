#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
long long irand(long long min, long long max) {
    return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}
int main()
{
	cout<<100<<endl;
	for(int i = 0 ; i < 100 ; i++){
		cout<<1000<<" "<<100<<endl;
		for(int i = 0 ; i< 1000 ; i++)
			cout<<irand(1 , 1000000000)<<" ";
		cout<<endl;
		for(int i = 0 ;i < 100 ;i++){
			cout<<0<<" "<<999<<endl;
		}
	}
	return 0;
}