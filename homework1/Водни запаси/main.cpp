#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    vector<int> g1;
    int min=arr[0];
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(arr[i]>=arr[j])
            {
                min=arr[j];
            }
            else if(arr[i]<arr[j])
            {
                min=arr[i];
            }
            if(j-i-1==0)
            {
               g1.push_back(min);
            }
            else
            {
                g1.push_back(min*(j-i));
            }
        }
    }
    int max=g1[0];
    int cap=g1.capacity();
    for(int i=0;i<cap;i++)
    {
        if(g1[i]>max)
        {
            max=g1[i];
        }
    }
    cout<<max;

    return 0;
}

