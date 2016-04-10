//check for bipartiteness while setting bool color
/*
root.color = 0
for for i in graph.height
	for i in crnt-node.children
*/
//if bipartite == true,
//search through and output all black
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Node
    {
    public:
    unsigned int type = 0;
    string value;
    Node(string x = "")
        {
        value = x;
        }
    };

int main()
    {

    unordered_map<Node,vector<Node>> graph;
    string a, b, root_str;

	//get values from input
	cin >> a;
	cin >> b;
  root_str = a;
  graph[a].push_back(Node(b));
  graph[b].push_back(Node(a));
	while (cin >> a && cin >> b)
		{
        graph[a].push_back(Node(b));
        graph[b].push_back(Node(a));
		}
    //DEBUG
    /*
    for ( auto it = graph.begin(); it != graph.end(); ++it )
        {
        cout << " " << it->first.value << ":";
        for(int j=0;j<it->second.size();j++)
            {
            if (it->second[j].value == "")
                {
                cout << "I'm null!";
                }
            cout << it->second[j].value;
            }
        cout << endl;
        }
    */
    //DEBUG
    //traverse the stuff
    crnt_vertice = graph[root];
    for (int i=0;i<crnt_vertice.size();i++)
        {
        //breadth first search
        //change types
        //check if bipartite == false else break
        //
        }
    //sort the stuff
    //print the stuff
    return 0;
    }
