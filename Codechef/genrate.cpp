/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 05 June 2016 (Sunday) 10:11
===================================================*/
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
long long irand(long long min, long long max) {
    return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}
using namespace std;
int main(){
	cout<<100000<<endl;
	for(int i = 0 ; i < 100000 ; i++)
		cout<<irand(1 , 1000000000)<<" ";
	cout<<endl;
	return 0;
}