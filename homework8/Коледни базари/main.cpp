#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
vector<string> reversed;
class Graph
{
private:
    map<string,map<string,long>> g;
public:
    bool isNeigh(string first, string second)
    {
        if(g[first][second] == 1)
        {
            return true;
        }
        return false;
    }
    void connect(string first, string second)
    {
        g[first][second]=1;
    }
    void BFS(string first, string second)
    {
        queue<string> q;
        map<string, string> check;
        for(auto &x: g)
        {
            check[x.first]="-";
        }
        check[first]="";
        q.push(first);
        while(!q.empty())
        {
            string help=q.front();
            q.pop();
            if(help==second)
            {
                string c=help;
                while (c != first)
                {
                    reversed.push_back(c);
                    c = check[c];
                }
                reversed.push_back(c);
                return;
            }
            for( auto &x: g[help])
            {
                if( isNeigh(help , x.first)  && check[x.first] == "-" )
                {
                    q.push(x.first);
                    check[x.first] = help;
                }
            }
        }
    }
};
int main() {
    long n,m;
    cin>>n>>m;
    Graph g;
    map<string,string> help;
    string a,b;
    for(long i = 0 ; i < m ; i++)
    {
        cin>>a>>b;
        help.insert(make_pair(b,a));
        g.connect(a,b);
    }
    cin>>a;
    map<string,string>::iterator it;
    it=help.find(a);
    g.BFS(a,(*it).second);
    if(reversed.size()==0)
    {
        cout<<-1;
        return 0;
    }
    for(long i = reversed.size()-1 ; i >= 0 ; i--)
    {
        cout<<reversed[i]<<" ";
    }
    cout<<a;
    return 0;
}
