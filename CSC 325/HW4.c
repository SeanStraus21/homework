#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctype>

using namespace std;

vector<char> get_lcs(A,B)
    {
    vector<char> lcs;

    return lcs;
    }

int main()
    {
    vector<char> A, B, C;
    char crnt_char;
    bool continue = true;

    while (continue)
        {
        //get values from input
        while (cin >> crnt_char)
            {
            crnt_char = toupper(crnt_char);
            if (crnt_char == A || crnt_char == T || crnt_char == C || crnt_char == G)
                {
                A.pushback(crnt_char);
                }
            }
        while (cin >> crnt_char)
            {
            crnt_char = toupper(crnt_char);
            if (crnt_char == A || crnt_char == T || crnt_char == C || crnt_char == G)
                {
                B.pushback(crnt_char);
                }
            }

        C = get_lcs(A,B);
        cout << C.size() << endl;
        cout << C << endl;
        A.clear()
        B.clear()
        }
    }
