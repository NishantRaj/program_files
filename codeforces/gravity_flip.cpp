#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
#include <map>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+9];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}