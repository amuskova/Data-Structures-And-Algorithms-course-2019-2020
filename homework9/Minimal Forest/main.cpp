#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;
class DisjoinSet
{
private:
    unordered_map<int,int> parent;
    int currentLastTree = 0;
public:
    void add(int child)
    {
        parent[child] = currentLastTree;
        currentLastTree++;
    }
    int find(int child)
    {
        if(parent[child] == child)
        {
            return child;
        }
        int root = find(parent[child]);
        parent[child] = root;
        return root;
    }
    void unite(int a, int b)
    {
        int aRoot = find(a);
        int bRoot = find(b);
        parent[aRoot] = bRoot;
    }
    void initialize(int nodeCount)
    {
        for(int i = 0 ; i < nodeCount; i++)
        {
            add(i);
        }
    }
};
struct Pair
{
    int index;
    int weight;
};
struct Node
{
    list<Pair> neigh;
    bool hasNeigh(int index)
    {
        for(auto n: neigh)
        {
            if(n.index == index)
            {
                return true;
            }
        }
        return false;
    }
    void addNeigh(int index, int weigh)
    {
        neigh.push_back(Pair{index,weigh});
    }
};
struct Edge
{
    int from;
    int to;
    int weight;
    bool operator<(const Edge& rhs) const
    {
        return weight<rhs.weight;
    }
};
class Graph
{
private:
    vector<Node> nodes;
public:
    Graph(int c)
    {
        nodes.resize(c);
    }
    void connect(int from, int to, int weight)
    {
        nodes[from].addNeigh(to,weight);
        nodes[to].addNeigh(from, weight);
    }
    vector<Edge> getAllEdges()
    {
        vector<Edge> edges;
        for(int from=0;from<nodes.size(); from++)
        {
            for(auto neighbour: nodes[from].neigh)
            {
                int to=neighbour.index;
                int weight= neighbour.weight;
                if(from<to)
                {
                    edges.push_back(Edge{from,to,weight});
                }
            }
        }
        return edges;
    }
    int kruskal()
    {
        vector<Edge> allEdges= getAllEdges();
        sort(allEdges.begin(), allEdges.end());
        int sum=0;
        list<Edge> tree;
        DisjoinSet components;
        components.initialize(nodes.size());
        for(Edge edge : allEdges)
        {
            if(components.find(edge.from) != components.find(edge.to))
            {
                tree.push_back(edge);
                sum+=edge.weight;
                components.unite(edge.from,edge.to);
            }
        }
        return sum;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    Graph g(n);
    int a,b,c;
    for(int i = 0 ; i < m ; i++)
    {
        cin>>a>>b>>c;
        g.connect(a,b,c);
    }
    cout<<g.kruskal();
    return 0;
}
