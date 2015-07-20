#include <bits/stdc++.h>
using namespace std;
struct cmp{
	bool compare(const int a , const int b){
		return a < b;
	}
};
template<class T , class compare>
class sparseTable{

private:
	vector<T> container;
	T **pre;
	compare c;
	int size;
public:
	void insert(T data){
		container.push_back(data);
	}

	void preCalculate(){

		size = container.size();

		int log_size = ceil(log(size));

		pre = new T*[size];
		for(int i = 0 ; i < size ; i++)
			pre[i] = new T[log_size];

		for(int i = 0 ; i < size ; i++)
			pre[i][0]  = i;

		for(int i = 1 ; (1<<i) <= size ; i++){

			for(int j = 0 ; j + (1<<i) -1 < size ; j++){

				if(c.compare(container[pre[j][i-1]] , container[pre[j + (1<<(i-1))][i-1]]))
					pre[j][i] = pre[j][i-1];
				else
					pre[j][i] = pre[j + (1<<(i-1))][i-1];
			}
		}
	}

	T rangeMin(int i , int j){
		int k=e-s;
	    k=31-__builtin_clz(k+1); // k = log(e-s+1)
	    if( container[pre[s][k]] <= container[pre[e-(1<<k)+1][k]] )
	        return container[pre[s][k]];
	    return container[pre[e-(1<<k)+1][k]];
	}
	

};
int main(){

	int n;
	cin>>n;
	sparseTable<int , cmp> arr;
	for(int i = 0 ; i < n ; i++)
	{
		int temp;
		cin>>temp;
		arr.insert(temp);
	}
	arr.preCalculate();
	int q;
	cin>>q;
	while(q--){
		int i , j;
		cin>>i>>j;
		cout<<arr.rangeMin(i , j)<<endl;
	}
	return 0; 
}