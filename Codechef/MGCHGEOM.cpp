/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 09 June 2016 (Thursday) 08:41
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
struct Point
{
    int x;
    int y;
};

struct cmp{
	bool operator()(const Point &a , const Point &b){
		return a.x == b.x ? a.y < b.y : a.x<b.x;
	}
};
Point p0;
 
// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
// A utility function to swap two points
int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
// A utility function to return square of distance between p1 and p2
int dist(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
 
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0)
        return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}
 
// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *) vp1;
    Point *p2 = (Point *) vp2;
 
    // Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (dist(p0, *p2) >= dist(p0, *p1)) ? -1 : 1;
 
    return (o == 2) ? -1 : 1;
}
 
// Prints convex hull of a set of n points.
void convexHull(Point points[], int n)
{
	// cout<<n<<endl;
    // Find the bottommost point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
 
        // Pick the bottom-most or chose the left most point in case of tie
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }
 
    // Place the bottom-most point at first position
    swap(points[0], points[min]);
 
    // Sort n-1 points with respect to the first point.  A point p1 comes
    // before p2 in sorted ouput if p2 has larger polar angle (in
    // counterclockwise direction) than p1
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);
 
    // Create an empty stack and push first three points to it.
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
 
    // Process remaining n-3 points
    for (int i = 3; i < n; i++)
    {
        // Keep removing top while the angle formed by points next-to-top,
        // top, and points[i] makes a non-left turn
        while (orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }
 
    // Now stack has the output points, print contents of stack
    vector<Point> v;
    while (!S.empty())
    {
        Point p = S.top();
        v.pb(p);
        // cout << "(" << p.x << ", " << p.y << ")" << endl;
        S.pop();
    }
    long long area = 0;
    int sz = v.size();
    for(int i = 0 ; i < sz ; i++){
    	// cout<<v[i].x << " " <<v[i].y<<endl;
    	Point p2 = v[(i+1)%sz];
    	area += v[i].x*p2.y - v[i].y*p2.x;
    }
    printf("%.1lf\n", abs(area)/2.0);
    // cout<<abs(area)/2.0<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		map<Point , int , cmp> ds;
		scanf("%d",&n);
		while(n--){
			char c;
			Point inp;
			scanf(" %c %d %d",&c,&inp.x,&inp.y);
			// cout<<inp.x<<" "<<inp.y<<endl;
			if(c == '+'){
				ds[inp] +=1;
				Point arr[1000009];
				int i=0;
				for(auto it:ds){
					// cout<<it.first.x<<" "<<it.first.y<<" "<<it.second<<endl;
					if(it.second > 0)
						arr[i++] = it.first;
				}
				if(i < 3){
					printf("0.0\n");
				} else
					convexHull(arr , i);
			} else if (c == '1'){
				ds[inp] -=1;
				Point arr[1000009];
				auto it = ds.find(inp);
				if(it != ds.end() && it->second <= 0)
					ds.erase(it);
				int i=0;
				for(auto it:ds){
					if(it.second > 0)
						arr[i++] = it.first;
				}
				if(i < 3){
					printf("0.0\n");
				} else
					convexHull(arr , i);
			}
		}
	}
	return 0;
}