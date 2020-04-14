#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    long N;
    cin>>N;
    vector<long> v;
    v.reserve(N);
    long a;
    for(long i = 0 ; i < N ; i ++)
    {
        cin>>a;
        v.push_back(a);
    }
    vector<long> help;
    long counter=1;
    long maxTrees=1;
    long savepos=0;
    long remember = 0;
    long currentpos = 0;
    help.push_back(v[v.size()-1]);
    for(long i = N-2 ; i>=0; i--)
    {
        if(v[i]<help[help.size()-1])
        {
            help.push_back(v[i]);
            counter++;
            if(maxTrees<=counter)
            {
                currentpos=i+1;
                maxTrees=counter;
                savepos=currentpos;
            }

        }
        else
        {
            if(maxTrees<=counter)
            {
                savepos=i+1;
                maxTrees=counter;

            }
            while(v[i]>=help[help.size()-1] && help.size()!=0)
            {
                help.pop_back();
                counter--;
            }
            remember++;
            help.push_back(v[i]);
            counter++;
        }
        if (i==0)
        {
            if(remember == 0)
            {
                savepos=0;
            }
            else
            {
                if (counter>=maxTrees)
                {
                    savepos=0;

                }
            }
        }
    }
    cout<<savepos;

    return 0;
}
