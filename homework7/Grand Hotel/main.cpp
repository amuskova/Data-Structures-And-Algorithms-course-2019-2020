#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int counter=0;
int main()
{
    long n;
    cin>>n;
    vector<long> keyswehave;
    vector<long> rooms;
    long a;
    for(long i = 0 ; i < n-1 ; i++)
    {
        cin>>a;
        keyswehave.push_back(a);
    }
    for(long i = 0 ; i < n-1 ; i++)
    {
        cin>>a;
        rooms.push_back(a);
    }
    unordered_map<long,int> keysweneed;
    for(long i = 0 ; i < n - 1 ; i++)
    {
        unordered_map<long,int>::iterator search=keysweneed.find(keyswehave[i]);
        if(search != keysweneed.end())
        {
            search->second++;
        }
        else
        {
            keysweneed.insert(make_pair(keyswehave[i],1));
        }

        search = keysweneed.find(rooms[i]);
        if(search != keysweneed.end())
        {
            search->second--;
            if(search->second==0)
            {
                keysweneed.erase(search);
            }
        }
        else
        {
            counter++;
        }
    }
    cout<<counter;
    return 0;
}

