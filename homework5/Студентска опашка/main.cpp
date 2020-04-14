#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int minute=2;
struct Person
{
    string name;
    int groupNumber;
    int pos;
    Person()
    {
        name="";
        groupNumber=0;
        pos=0;
    }
    Person(string newname, int newGroupnumber, int newpos)
    {
        this->name=newname;
        this->groupNumber=newGroupnumber;
        this->pos=newpos;
    }
};

int main()
{
    int N, M;
    cin>>N>>M;
    vector<queue<Person> > v;
    queue<int> groups;
    Person p;
    v.resize(M+1);
    for(int i = 0 ; i < N ; i ++)
    {
        cin>>p.name>>p.groupNumber;
        p.pos=i;
        if(i==0)
        {
            v[p.groupNumber].push(p);
            groups.push(p.groupNumber);
        }
        else
        {
            if(v[p.groupNumber].empty())
            {
                groups.push(p.groupNumber);
            }

            v[p.groupNumber].push(p);
        }
        if(i %2 == 0 && i != 0)
        {
           cout<<v[groups.front()].front().name<<" "<<v[groups.front()].front().pos<<" "<<minute<<endl;
           v[groups.front()].pop();
           minute+=2;
           if(v[groups.front()].empty())
           {
               groups.pop();
           }
        }
    }
    while(!groups.empty())
    {
        cout<<v[groups.front()].front().name<<" "<<v[groups.front()].front().pos<<" "<<minute<<endl;
           minute+=2;
           v[groups.front()].pop();
           if(v[groups.front()].empty())
           {
               groups.pop();
           }
    }

    return 0;
}
