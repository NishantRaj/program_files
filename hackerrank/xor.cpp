#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int count;
	Node *lChild,*rChild;
	Node()
	{
		count=0;
		lChild=rChild=NULL;
	}
};
class hold{
	int zero , one;
	hold(){
		zero = 0 , one = 0;
	}
};
inline void read(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();}
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;}
    if(neg)
        x = -x;
}
Node *addBit(Node *root,int n,int i)
{
	if(i==-1 ){
		root->count++;
		return root;
	}
	int x= (n>>i) & 1;
 
	if(x)
	{
		if(root->rChild == NULL)
			root->rChild = new Node();
		root->rChild = addBit(root->rChild,n,i-1);
	}
	else
	{
		if(root->lChild == NULL)
			root->lChild = new Node();
		root->lChild = addBit(root->lChild,n,i-1);
	}
	return root;
}
void del(Node *root , int n){
	for(int i = 16 ; i>=0 ; i--){
		int bit = (n>>i)&1;
		//cout<<i<<endl;
		if(bit){
			root = root->rChild;
		} else
			root = root->lChild;
		if(i == 0)
			root->count--;
	}
}
int query(Node *root,int n,int i)
{
	if(i==-1 && root != NULL)
		return root->count;
	if(root == NULL)
		return 0;
	bool bit=(n>>i) & 1;
	if(bit)
		return root->count + query(root->lChild,n,i-1) + query(root->rChild,n,i-1);
	else
		return root->count + query(root->lChild,n,i-1);
}
void print(Node *root){
	if(root == NULL)
		return ;
	cout<<root->count<<endl;
	print(root->lChild);
	print(root->rChild);
}
int main()
{
	int q;
	read(q);
	Node *root = new Node();
	Node *save = root;
	while(q--){
		//string s;
		char s[10];
		int n;
		scanf("%s %d" , s , &n);
		if(s[0] == 'a'){
			addBit(root , n , 16);
			//print(root);
		} else if(s == 'd'){
			del(root , n);
			//print(root);
		} else if(s == 'c'){
			cout<<query(root , n , 16)<<endl;
			//print(root);
		}
	}
	return 0;
} 