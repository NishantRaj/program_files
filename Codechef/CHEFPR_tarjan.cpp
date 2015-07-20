#include <bits/stdc++.h>
using namespace std;
const int N = 10000009;
struct node
{
	int left, right, index;
	node(){
		left = right = -1;
		index = -1;
	}
};
node tree[N];
int build(vector <int> a)
{
	node root = node();
	stack <node> s;
	for (int i = 0; i<a.size(); i++){
		node last = node();
		while (!s.empty() && a[s.top().index] > a[i]){
			last = s.top();
			s.pop();
		}
		
		tree[i].index = i;
		tree[i].left = last.index;

		if (s.empty()) root = tree[i];
		else tree[s.top().index].right = tree[i].index;

		
		s.push(tree[i]);
	}
	return root.index;
}

int main()
{
	int n;
	cin >> n;
	vector <int> a;
	for (int i = 0; i<n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	int root = build(a);
	return 0;
}