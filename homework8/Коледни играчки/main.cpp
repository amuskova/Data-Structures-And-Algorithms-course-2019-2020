#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Graph
{
private:
    map<long,map<long,long>> matrix;
    void DFS(long v,vector<bool> &visited,long &visit)
    {
        visited[v]=true;
        visit++;
        for(auto p : matrix[v])
        {
            if(!visited[p.first])
            {
                DFS(p.first,visited,visit);
            }
        }
    }
public:
    void connect(long v, long w)
    {
        matrix[v][w]=1;
        matrix[w][v]=1;
    }
    long countCol(long V,const set<long> input)
    {
        vector<bool> visited;
        visited.resize(V+1,false);
        long counter=0;
        long visit=0;
        set<long>::iterator i;
        for(i = input.begin() ; i != input.end() ; i++)
        {
            if(visited[*i]==false)
            {
                DFS(*i,visited,visit);
                counter++;
            }
        }
        counter = counter+V-visit;
        return counter;
    }
};

int main() {
   long n,m;
    cin>>n>>m;
    Graph g;
    long a,b;
    vector<bool> see;
    see.resize(n+1, false);
    set<long> input;
    for(long i = 0 ; i < m ; i ++)
    {
        cin>>a>>b;
        g.connect(a,b);
        input.insert(a);
        input.insert(b);
    }
    cout<<g.countCol(n,input);

    return 0;
}
