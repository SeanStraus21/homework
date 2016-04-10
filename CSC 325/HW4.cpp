#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

vector<char> get_lcs(vector<char> A,vector<char> B)
    {
    int grid[A.size()+1][B.size()+1];
    vector<char> lcs;
    //search for longest path through the grid AxB
    for(int i=0;i<=A.size();i++)
        {
        for(int j=0;j<=B.size();j++)
            {
            if (i == 0 || j == 0)
                {
                grid[i][j] = 0;
                }

            else
                {
                if (A[i-1] == B[j-1])
                    {
                    //increment the value of the previous diagonal cell
                    grid[i][j] = grid[i-1][j-1]++;
                    }
                else
                    {
                    //store set current cell to the larger value
                    grid[i][j] = (grid[i-1][j] > grid[i][j-1])? grid[i-1][j] : grid[i][j-1];
                    }
                }
            }
        }
    int k = grid[A.size()][B.size()];
    int i = A.size();
    int j = B.size();
    //start at bottom corner and walk back through longest path and push to vector
    while (i > 0 && j > 0)
        {
        if (A[i-1] == B[j-1])
            {
            lcs.push_back(A[i-1]);
            i--;
            j--;
            k--;
            }
        else
            {
            if (grid[i-1][j] > grid[i][j-1])
                {
                i--;
                }
            else
                {
                j--;
                }
            }
        }
    return lcs;
    }

int main()
    {
    vector<char> A, B, C;
    string input;
    char token;

    while (true)
        {
        //get values from input
        cin >> input;
        for(int i=0;i<input.size();i++)
            {
            token = input[i];
            token = toupper(token);
            if (token == 'A' || token == 'T' || token == 'C' || token == 'G')
                {
                A.push_back(token);
                }
            }
        cin >> input;
        for(int i=0;i<input.size();i++)
            {
            token = input[i];
            token = toupper(token);
            if (token == 'A' || token == 'T' || token == 'C' || token == 'G')
                {
                B.push_back(token);
                }
            }
        //search for lowest common subsequence
        C = get_lcs(A,B);
        cout << C.size() << endl;
        for (int i=C.size()-1;i>=0;i--)
            {
            cout << C[i] << endl;
            }
        //clear vectors for the next iteration
        A.clear();
        B.clear();
        }
    }
