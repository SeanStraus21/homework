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
#include <list>

using namespace std;

class Node
    {
    public:
    short type = 0;
    string value;
    Node(string x = "")
        {
        value = x;
        }
    };

class Adjacency_list
  {
  public:
  short type = 0;
  vector<Node*> value;
  Adjacency_list(vector<Node*> x=NULL)
    {
    value = x;
    }
  int size()
    {
    return value.size();
    }
  void push_back(Node* x)
    {
    value.push_back(x);
    }
  Node* operator [] (int x)
    {
    return value[x];
    }
  };

int main()
    {

    unordered_map<string,Adjacency_list> graph;
    string a, b, root_str;
    vector<string>C,D;

	//get values from input
	cin >> a;
	cin >> b;
  root_str = a;
	graph[a].push_back(new Node(b));
	graph[a].type = 1;
	graph[b].push_back(new Node(a));
	graph[b][0]->type = 1;
  Node* root_node = graph[b][0];

	while (cin >> a && cin >> b)
		{
        graph[a].push_back(new Node(b));
        graph[b].push_back(new Node(a));
		}
    //DEBUG
    /*
    for ( auto it = graph.begin(); it != graph.end(); ++it )
        {
        cout << " " << it->first << ":";
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
    //traverse the stuff with breadth first search
    Node* crnt_node;
    list<Node*> node_queue;
    node_queue.push_back(root_node);
    while(!node_queue.empty())
        {
        // Dequeue a node
        crnt_node = node_queue.front();
        node_queue.pop_front();

        // Get all adjacent vertices of the dequeued node
        // for each node in the row, check type
        // if type = 0, its type becomes 2 or 1, whichever the crnt_node.type isn't,
              //and put it in the queue
        // if type == crnt_node.type, just give up. break the loop, print "IMPOSSIBLE"
        // else, skip it.
        for(int i = 0; i < graph[crnt_node->value].size(); ++i)
          {
          if(graph[crnt_node->value][i]->type == 0)
            {
            graph[crnt_node->value][i]->type = ((crnt_node->type+1)%2)+1;
            node_queue.push_back(graph[crnt_node->value][i]);
            }
          }
        }
    //sort the stuff
    //print the stuff
    return 0;
    };
