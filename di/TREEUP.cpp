#include <bits/stdc++.h>
using namespace std;
int tree[100000];
int val[100000];
void add(int x , int val){
	tree[x] += val;
	val[x] += val;
}
void addup(int x , int val){
	int temp = x;
	while(tree[x]!= 0)
	{
		tree[x] += val;
		x = tree[x];
	}
}