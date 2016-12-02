#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:

    int value;
    vector <Node*> adjacencyList;
    bool visited;

    Node(int val)
    {
        this->value=val;
        this->visited=false;
    }

    void addEdge(Node* x)
    {
        this->adjacencyList.push_back(x);
        x->adjacencyList.push_back(this);
    }

    ~Node ()
    {
        cout<<endl;
        cout<<"Destroyed the node: "<<this->value;
    }
};

class Graph
{
public:

    vector <Node*> theList; // a vector of "Node" pointers

    Graph()
    {
        int a[10], theSize; // local method variables
        cout<<"Please insert the number of nodes: "<<endl;
        cin>>theSize;
        if(theSize>10)
        {
            cout<<"The number of nodes is too high!"<<endl;
            delete(this);
        }
        else
        {
            for(int i=0;i<theSize;i++)
            {
                cout<<"Insert node no. "<<i+1<<": ";
                cin>>a[i];
                this->theList.push_back(new Node (a[i]));
            }
        }
    }

    void addNode(Node* n)
    {
        this->theList.push_back(n);
    }

    void resetVisitedNodes()
    {
        //this function is used to reset the visited variable from each node
        // in order to do both traversals in the same run

        for (int i=0;i<this->theList.size();i++)
            this->theList[i]->visited = false;
    }

    void display_graph()
    {
        for(int i=0;i<this->theList.size();i++)
        {
            cout<<theList[i]->value<<": the nodes connected to the node "<<theList[i]->value<<" are: ";
            for(int j=0;j<theList[i]->adjacencyList.size();j++)     //prints the adjacency list of every node
                cout<<theList[i]->adjacencyList[j]->value<<" ";
            cout<<endl;
        }
        cout<<endl;
    }

    ~Graph()
    {
        cout<<"The list is destroyed ... "<<endl;
    }
};

//the function below is related to Week 7 Task 2
void DFS(Node* head, ofstream& file)
{
    file<<"The result after DFS: "<<endl;

    stack <Node*> trav;
    trav.push(head);

    while(!trav.empty())
    {
        Node* n = trav.top();
        trav.pop();
        if(n->visited==false)
        {
            file<<"Visited node: "<<n->value<<endl;
            cout<<"Value of n is: "<<n->value<<endl;
            n->visited = true;
            for(int i=0;i<n->adjacencyList.size();i++)
                if(!n->adjacencyList[i]->visited)
                    trav.push(n->adjacencyList[i]);
        }
    }
    cout<<endl;
    file<<endl;
}

//the function below is related to Week 7 Task 2
void BFS(Node* head, ofstream& file)
{
    file<<"The result after BFS: "<<endl;

    queue <Node*> trav;
    trav.push(head);

    while(!trav.empty())
    {
        Node* n = trav.front();
        trav.pop();
        if (n->visited==false)
        {
            file<<"Visited node: "<<n->value<<endl;
            cout<<"Value of n is: "<<n->value<<endl;
            n->visited = true;
            for(int i=0;i<n->adjacencyList.size();i++)
                trav.push(n->adjacencyList[i]);
        }
    }
    cout<<endl;
    file<<endl;
}

int main()
{
    Graph* G = new Graph();

    if(G!=NULL)
    {
        ofstream file ("traverse.txt", ios::app);
        G->theList[0]->addEdge(G->theList[1]); // connecting the first node with the second node
        G->theList[0]->addEdge(G->theList[2]); // connecting the first node with the third node
        G->theList[0]->addEdge(G->theList[3]); // connecting the first node with the forth node
        G->theList[1]->addEdge(G->theList[4]); // connecting the second node with the fifth node
        G->theList[2]->addEdge(G->theList[4]); // connecting the third node with the fifth node
        G->addNode(new Node(10)); // adding an extra node
        G->display_graph();
        DFS(G->theList[1], file); // DFS traversal from the second node
        G->resetVisitedNodes();
        BFS(G->theList[3], file); // BFS traversal from the forth node
        file.close();
        delete(G);
    }
    return 0;
}
