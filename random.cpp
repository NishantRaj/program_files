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
	for(int i = 0 ; i < 500000 ; i++){
		cout<<irand(65 , 90)<<irand(97 , 122);
	}
	return 0;
}