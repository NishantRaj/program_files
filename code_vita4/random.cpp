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
		char a = (int)irand(65 , 90);
		char s = (int)irand(97 , 122);
		cout<<a<<s;
	}
	return 0;
}