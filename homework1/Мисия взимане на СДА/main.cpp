#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int M;
    int N;
    cin>>M>>N;
    int a;
    vector<int> g1;
    for(int i=0; i<N;i++)
    {
        cin>>a;
        g1.push_back(a);
    }
    int help=0;
    int howweneed=0;
    int howwehave=0;
    for (int i = 0; i < N; i++)
    {
        if(g1[i]<M)
        {
            help=i;
            howweneed = M-g1[i];
            break;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(g1[i]>M)
        {
            if(g1[i]-M<howweneed)
            {
                g1[help]+=g1[i]-M;
                g1[i]-=M;
            }
            else
                {
                    while(g1[help]!=M)
                    {
                        g1[help]++;
                        g1[i]--;
                    }
                }
        }
    }
    if(g1[help]<M)
    {
        cout<<"no";
    }
    else
    {
        cout<<"yes";
    }
    return 0;
}
