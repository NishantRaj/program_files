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
	cout<<20<<endl;
	for(int i = 0 ; i < 20 ; i++){
		cout<<10000<<endl;
		for(int j = 0 ; j < 10000 ; j++)
			cout<<irand(1 , 1000000000)<<" ";
		cout<<endl<<10000<<endl;
		for(int j = 0 ; j < 10000 ; j++){
			int x = irand(1 , 10000);
			int y = irand(x , 10000);
			cout<<x<<" "<<y<<endl;
		}
	}
	return 0;
}