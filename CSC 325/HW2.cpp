// get mean

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void heapify(vector<int> &A,int i,int &counter)
	{
	int l,r,high,temp;
	l = (i*2)+1;//left child equal parent +1
	r = l++;//right child equal parent +2
	high = i;
	if ((l <= counter) && (A[l]>A[i]))
		{
		high = l;
		}
	if ((r <= counter) && (A[r]>A[high]))
		{
		high = r;
		}
	if (high != i)
        {
        temp = A[i];//if subarray out of order, swap
        A[i] = A[high];
        A[high] = temp;
        heapify(A,high,counter);
        }
	}

void heap_sort(vector<int> &A)
	{
    int temp;
	//convert to heap
	int counter = A.size()-1;
	for (int i=(A.size()/2)-1;i>=0;i--) // starting at the midpoint, heapify
		{
		heapify(A,i,counter);
		}
	//sort
	for (int i=(A.size()-1);i>0;i--)
		{
		//swap A[0] with A[i]
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		counter--;
		heapify(A,0,counter);
		}
	}

//takes the average of a vector's content
double get_mean(vector<int> A)
	{
	double m = 0;
	for (auto i=0;i<A.size();i++)
		{
		m+=A[i];
		}
	m/=A.size();
	return m;
	}

//takes sorted vector as input
int get_mode(vector<int> A)
	{
	int m = A.at(0);
	if (A.size() > 1)
        {
        int counter = 1;
        int max_count = 0;
        for (int i=1;i<A.size();i++)
            {
            if (A[i]!= A[i-1])//if the value goes up
                {
                if (counter > max_count)
                    {
                     max_count = counter;
                     m = A[i-1];
                    }
                counter = 0;
                }
            counter++;
            }
        if (counter > max_count)
            {
             m = A[A.size()-1];
            }
        }
	return m;
	}

//takes sorted vector as input
double get_median(vector<int> A)
	{
	double m;
	if (A.size() > 0)
		{
		if (A.size()%2)//if odd
			{
			m = A[(A.size()/2)];//divide by 2 and round down to the nearest int
			}
		else //if even
			{
			//take the average of the middle values (rounded down) and the next value
			m = (A[A.size()/2] + A[(A.size()/2)-1])/2.0;
			}
		}
	else {m=0;}
	return m;
	}

int main()
	{
	vector<int> A;
	int num;

	//get values from input
	while (cin >> num)
		{
		A.push_back(num);
		}

	heap_sort(A);

	/*//DEBUG
	cout << "...." << endl;
	for (int i=0;i<A.size();i++)
        {
	    cout << A[i] << endl;
	    }
    cout << "...." << endl;
	//*/

	cout << fixed;
	cout << "mean " << setprecision(3) << get_mean(A) << endl;
	cout << "median " << setprecision(3) << get_median(A) << endl;
	cout << "mode " << get_mode(A) << endl;

	return 0;
	}
