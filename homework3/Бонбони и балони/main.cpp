#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

long n,m;

long balloonsNeeded(vector<long>& a, vector<long> &b, long candies)
{
     long c= 0 ;
     for(long i = 0 ; i < a.size() ; i++)
     {
         if(b[i]==0)
         {
             continue;
         }
         c+=max(a[i]-candies/b[i], 0l);
     }
     return c;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin>>n>>m;
    vector<long>a;
    vector<long>b;
    long r;
    a.reserve(n);
    b.reserve(n);

    long q;
    for(long i = 0 ; i < n ; i++)
    {
        cin>>q;
        a.push_back(q);

    }
    for(long i = 0 ; i < n ; i++)
    {
        cin>>q;
        b.push_back(q);
        r=(max(r,a[i]*b[i]));
    }

    long l=0;
    long mid;
    while(l<r)
    {
        long mid=l+(r-l)/2;
        long balloons=balloonsNeeded(a,b,mid);
        if(balloons<=m)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<l<<endl;
    return 0;
}
