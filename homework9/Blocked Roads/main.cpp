#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    list<int> neigh;
    bool hasNeigh(int index)
    {
        for(auto i: neigh)
        {
            if(i == index)
            {
                return true;
            }
        }
        return false;
    }
    void addNeigh(int to)
    {
        neigh.push_back(to);
    }
};
class Graph
{
private:
    vector<Node> nodes;
    bool _isAvailable(int start, int to, vector<bool>& visited)
    {
        queue<int> nextToVisit;
        nextToVisit.push(start);
        visited[start]=true;
        int top;
        while(!nextToVisit.empty())
        {
            top=nextToVisit.front();
            nextToVisit.pop();
            for (auto neighbour : nodes[top].neigh)
            {
                if (!visited[neighbour])
                {
                    nextToVisit.push(neighbour);
                    visited[neighbour] = true;
                    if(neighbour == to)
                    {
                        return true;
                    }
                }
            }
            //return false;
        }
        return false;
    }
public:
    Graph(int num)
    {
        nodes.resize(num);
    }
    void connect(int from, int to)
    {
        nodes[from].addNeigh(to);
        nodes[to].addNeigh(from);
    }
    bool isAvailable(int start, int to)
    {
        vector<bool> visited;
        visited.resize(nodes.size(), false);
        return _isAvailable(start,to,visited);
    }
};
int main() {
    int n,m;
    cin>>n>>m;
    Graph g(n+1);
    int a,b;
    for(int i = 0 ; i < m ; i++)
    {
        cin>>a>>b;
        g.connect(a,b);
    }
    int q;
    cin>>q;
    int code;
    for(int i = 0 ; i < q; i++)
    {
        cin>>code>>a>>b;
        if(code == 1)
        {
            //isAvailable(a,b);
            if(g.isAvailable(a,b)==true)
            {
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        else
        {
            g.connect(a,b);
        }
    }
    return 0;
}
