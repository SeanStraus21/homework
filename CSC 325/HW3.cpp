/*
we are given n points in the unit circle, p[i] = (x[i],y[i])
such that 0<x[i]^2+y[i]^2<= 1 for all i = 1,2,...,n. Suppose that the points are
uniformly distributed; that is, the probability of finding a point in any region of
the circle is proportional to the area of that region. Design and algorithm with an
average-case running time of bigtheta(n) to sort the n points by their
distance d[i] = sqrt(x[i]^2+y[i]^2) from the origin.
(Hint: Design the bucket sizes in bucket_sort to reflect the uniform
 distribution of the points in the unit circle)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Point
    {
    public:
        double x;
        double y;
        double d;
    Point(double a=0,double b=0)
        {
        x = a;
        y = b;
        d = sqrt(pow(a,2.0)+pow(b,2.0));
        }
    friend ostream& operator<<(ostream& output, const Point& p)
        {
        output << fixed << showpos << setprecision(6) << p.x << ' ' << p.y;
        return output;
        }
    bool operator<(const Point other) const
        {
        return (d<other.d);
        }
    };

//lump points together by relative distance from origin
int my_hash(int n, Point p)
    {
    //find out which chunk the point goes into
    int hash_ind = round(n*pow(p.d,2));
    //this function works for n points of d<1
    //since points are allowed to have d<= 1, we actually have n+1 cases to handle
    //we can handle the special case of d = 1 and still do it in constant time
    if (p.d = 1) {hash_ind = n-1;}
    return hash_ind;
    }
//bucket sort
void bucket_sort(vector<Point> P,vector<vector<Point>>& buckets)
    {
    //for each Point p...
    for(int i=0;i<P.size();i++)
        {
        //use hash to find the right bucket
        int hash_ind = my_hash(P.size(),P[i]);
        hash_ind = 0;
        //load the point into that bucket
        buckets[hash_ind].push_back(P[i]);
        }
    }

int main()
    {
    vector<Point> P;
    vector<vector<Point>> buckets;
    double px,py;

	//get values from input
	while (cin >> px && cin >> py)
		{
        Point crnt_point = Point(px,py);
		P.push_back(crnt_point);
		}
    //fill buckets with empty lists
    for (int i=0;i<P.size();i++)
        {
        vector<Point> temp;
        buckets.push_back(temp);
        }

    //set bucket sizes
    vector<double> bucket_sizes;
    for (int i=0;i<P.size();i++)
        {
        bucket_sizes.push_back(sqrt(i+1.0)/sqrt(P.size()));
        }

    //bucket_sort
    bucket_sort(P,buckets);

    //print distances
    for (int i=0;i<bucket_sizes.size();i++)
        {
        cout << fixed << setprecision(6) << bucket_sizes[i] << endl;
        }
    //print points
    for (int i=0;i<P.size();i++)
        {
        sort(buckets[i].begin(),buckets[i].end());
        for(int j=0;j<buckets[i].size();j++)
            {
            cout << buckets[i][j] << endl;
            }
        }
    }
