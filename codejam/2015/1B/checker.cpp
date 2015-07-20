#include <bits/stdc++.h>
using namespace std;
int main(){
	fstream first , second;
	first.open("outputB.out");
	second.open("bout_large.txt");
	string one , two;
	if(first.is_open()){
		while(getline(first , one)){

			getline(second , two);
			if(one != two)
				cout<<" didn't qualify\n";
			//cout<<one<<"     "<<two<<endl; 
		}
	}
	else
		cout<<"fail\n";
	return 0;
}