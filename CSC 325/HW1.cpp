// CSC 325 - Spring 2015 - Homework 1

// Complete this program where indicated so that it solves Problem 2-4
// on page 41. Do not modify any of the other code. The program reads
// zero or more integers from standard input into a vector, then
// counts the number of inversions using a modified mergesort. So the
// vector is sorted at the end, but we really care about the number of
// inversions. Your program must run in worst-case time O(n log n).
//
// If you test your program by entering numbers from the keyboard (the
// default standard input), remember that <Ctrl-Z><Enter> signals EOF
// from the keyboard on Windows and <Ctrl-D> signals EOF from the
// keyboard on Mac and Linux. Or create files of numbers and use the
// redirection operators. See the links on my web page for a reminder
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using count_t = uint64_t;

vector<int> A;					// the ints read from standard input
vector<int> B;					// temporary vector used for merging

count_t mergeAndCount(vector<int>&A,vector<int>&B,int p,int q,int r)
    {
        //merge subarrays into array A
		//p = start of subarray (0)
		//q = midpoint of subarray
		//r = end of subarray (A.size-1)
		count_t b = 0;
		int j = p;
		int k = q+1;
        for (int i=p;i<r;i++)
        {
            if (B[j] <= B[k])
            {
                A[i] = B[j];
                j++;
                if (j > q) //if the left half is used up
                {
                    for(;k<=r;k++)
                    {
                        i++;
                        A[i]=B[k];
                    }
                    break;
                }
            }
            else            //j<k; if B[j] > B[k], inversion ++
            {
                A[i] = B[k];
                k++;
                if (k > r) //if the right half is used up...
                {
                    for(;j<=q;j++)//???
                    {
                        i++;
                        b++;
                        A[i]=B[j];
                    }
                    break;
                }
                else
                {
                    b+=(q+1-j);//+ the remaining slots in the array (q-j)
                }
            }
        }
        return b;
    }

count_t mergesortAndCountInversions(int p, int r) {
	// note: r is an inclusive upper bound

	if (p >= r)
		// subarray has length at most 1: already sorted, no inversions
		return 0;
	else {
		int q = (p + r)/2;
		auto a = mergesortAndCountInversions(p, q);
		auto c = mergesortAndCountInversions(q + 1, r);
		count_t b = 0;  // inversions *between* the two sorted halves

		// copy the subarray from A into B
		copy(begin(A) + p, begin(A) + r + 1, begin(B) + p);

		// Merge the two halves from B back into A, also counting the
		// inversions *between* the two halves, where one element is
		// in the left half and the other is in the right half. (The
		// inversions within each half have already been counted via
		// the recursive calls.) You must count the inversions between
		// the halves in linear time, i.e., O(r - p + 1). You can
		// exploit the fact that the two halves are sorted.

		// YOUR CODE HERE!

    b = mergeAndCount(A,B,p,q,r);

    //DEBUG
    /*
    cout << "...." << endl;
    for (int i = 0; i<A.size(); i++)
        {
          cout << A[i] << endl;
        }
    cout << "inversions: " << a+b+c << endl;
    cout << "...." << endl;
    */
    return a + b + c;
	}
}


int main () {
	int number;

	while (cin >> number) {
		A.push_back(number);
	}

	// B is a copy of A; all that really matters is that it's the same size
	B = A;

	// this will print 0 until you get it working
	cout << mergesortAndCountInversions(0, A.size() - 1) << endl;

	for (int i = 1; i < A.size(); ++i) {
		if (A[i - 1] > A[i]) {
			cout << "Array is NOT sorted!" << endl;
			break;
		}
	}
}
