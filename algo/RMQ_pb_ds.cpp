#include <cstdio>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
template<typename node_const_iterator, typename node_iterator, typename cmp_fn,
	   typename _Alloc>
struct tree_max
{
    typedef int metadata_type;
 
    tree_max(){}
 
    inline void operator() (node_iterator it, node_const_iterator null) const
    {
        int mx = (*it)->second;
        if (it.get_l_child() != null)
            mx = max(mx, it.get_l_child().get_metadata());
        if (it.get_r_child() != null)
            mx = max(mx, it.get_r_child().get_metadata());
        (int&)(it.get_metadata()) = mx;
    }
};
 
typedef tree<int, int, less<int>, splay_tree_tag, tree_max> Tree;
 
Tree A; 
 
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        A.insert(make_pair(i, t));
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        char t;
        int x, y;
        scanf(" %c %d %d", &t, &x, &y);
        if (t == 'u')
        {
            A.erase(x);
            A.insert(make_pair(x, y));
        }
        else
        {
            Tree B, C;
            A.split(y, C);
            A.split(x - 1, B);
            printf("%d ", B.node_begin().get_metadata());
            A.join(B);
            A.join(C);
        }
    }
}