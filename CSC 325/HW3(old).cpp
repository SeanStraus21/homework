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
#include <math.h>

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
    };

class Node
    {
    public:
    //value points to a Point
    Point value;
    //next points to the next Node in the list
    Node* next = NULL;
    Node(Point p)
        {
        value = p;
        }
    };

class Linked_list
    {
    public:
    bool isempty;
    Node head = Node(Point());
    int length;
    Linked_list()
        {
            isempty = 1;
            length = 0;
        }
    void push(Point p)
        {
        //if empty, insert and set length to 1
        if (isempty)
            {
            head.value = p;
            length = 1;
            isempty = 0;
            }
        else
            {
            //crnt_node traverses the list
            Node* crnt_node = &head;
            for (int i=0;i<length-1;i++)
                {
                if (p.d <= crnt_node->next->value.d)
                    {
                    Node temp = Node(p);
                    temp.next = crnt_node->next;
                    //
                    crnt_node->next = &temp;
                    length++;
                    return;
                    }
                else
                    {
                    crnt_node = crnt_node -> next;
                    }
                }
            Node temp = Node(p);
            crnt_node->next = &temp;
            length++;
            }
        }
    Point get(int n)
        {
        //set crnt_node to point to head
        Node* crnt_node = &head;
        for (int i=0;i<n;i++)
            {
            crnt_node = crnt_node->next;
            }
        return crnt_node -> value;
        }
    };
//lump points together by relative distance from origin
int my_hash(int bucket_count, Point p)
    {
    //all distances lie between 0 and sqrt(2)
    //break up this range into n chunks
    double bucket_size = sqrt(2.0)/bucket_count ;
    //find out which chunk the point goes into
    return round(p.d / bucket_size);
    }
//bucket sort
void bucket_sort(vector<Point> P,vector<Linked_list>& buckets)
    {
    //for each Point p...
    for(int i=0;i<P.size();i++)
        {
        //use hash to find the right bucket
        int hash_ind = my_hash(P.size(),P[i]);
        //load the point into that bucket
        buckets[hash_ind].push(P[i]);
        }
    }

int main()
    {

    vector<Point> P;
    vector<Linked_list> buckets;
    double px,py;

	//get values from input
	while (cin >> px && cin >> py)
		{
        Point crnt_point = Point(px,py);
		P.push_back(crnt_point);
		}
    //fill buckets with empty linked lists
    for (int i=0;i<P.size();i++)
        {
        buckets.push_back(Linked_list());
        }

    //bucket_sort
    bucket_sort(P,buckets);

    //print distances
    for (int i=0;i<P.size();i++)
        {
        for(int j=0;j<buckets[i].length;j++)
            {
            cout << fixed << setprecision(6) << buckets[i].get(j).d << endl;
            }
        }

    //print points
    for (int i=0;i<P.size();i++)
        {
        for(int j=0;j<buckets[i].length;j++)
            {
            cout << buckets[i].get(j) << endl;
            }
        }

    }
