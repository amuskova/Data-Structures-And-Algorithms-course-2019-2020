#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <climits>
using namespace std;

struct Pair
{
    int index;
    int distance;

    bool operator<(const Pair & rhs) const
    {
        return distance > rhs.distance;
    }
};

class Graph
{
private:
    vector<vector<Pair>> nodes;

public:
    Graph(int nodeCount = 0)
    {
        nodes.resize(nodeCount);
    }

    void connect(int from, int to, int distance)
    {
        Pair f;
        f.index=to;
        f.distance=distance;
        Pair t;
        t.index=from;
        t.distance=distance;
        nodes[from].push_back(f);
        nodes[to].push_back(t);
    }

    void findshortestpath(vector<int> discos,vector<int>& addition)
    {
        vector<int> parent(nodes.size(), -1);
        vector<int> distance(nodes.size(), INT_MAX);
        vector<bool> visited(nodes.size(), false);

        priority_queue<Pair> nextToProcess;
        for (int i = 0; i < discos.size(); i++)
        {
            Pair p;
            p.index=discos[i];
            p.distance=0;
            nextToProcess.push(p);
            distance[discos[i]]=0;
        }
        while (!nextToProcess.empty())
        {
            Pair currentPair = nextToProcess.top();
            nextToProcess.pop();
            int currentNode = currentPair.index;
            if (visited[currentNode])
            {
                continue;
            }
            visited[currentNode] = true;
            for (int i=0;i<nodes[currentNode].size();i++)
            {
                int neighbourNode = nodes[currentNode][i].index;
                int alternativeDistance = distance[currentNode] + nodes[currentNode][i].distance;
                if (alternativeDistance < distance[neighbourNode])
                {
                    distance[neighbourNode] = alternativeDistance;
                    parent[neighbourNode] = currentNode;
                    if (addition[neighbourNode]==0 || distance[neighbourNode] <= addition[neighbourNode])
                    {
                        addition[neighbourNode] = distance[neighbourNode];
                    }
                    nextToProcess.push({neighbourNode, alternativeDistance});
                }
            }
        }
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    Graph g(n);
    int a,b, weigh;
    for(int i = 0 ; i < m ; i++)
    {
        cin>>a>>b>>weigh;
        g.connect(a,b,weigh);
    }
    cin>>a;
    vector<int> discos;
    discos.reserve(a);
    for(int  i = 0 ; i < a ; i++)
    {
        cin>>b;
        discos.push_back(b);
    }
    vector<int> addition(n, 0);
    g.findshortestpath(discos,addition);
    queue<int> q;
    cin>>a;
    for(int  i = 0 ; i < a ; i++)
    {
        cin>>b;
        q.push(b);
    }
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        cout << addition[top] << endl;
    }
    return 0;
}

