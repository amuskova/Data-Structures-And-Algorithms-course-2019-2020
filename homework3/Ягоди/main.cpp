#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int bs_upper_bound(vector<long int> &a, long n, long x)
{
    long l = 0;
    long h = n;
    while (l < h)
    {
      long mid = (l + h) / 2;
      if (x >= a[mid])
      {
         l = mid + 1;
      }
      else
      {
         h = mid;
      }
    }
    return l;
}
int bs_lower_bound(vector<long int> &a, long n, long x)
 {
    long l = 0;
    long h = n;
    while (l < h)
    {
      long mid = (l + h) / 2;
      if (x <= a[mid])
      {
        h = mid;
      }
      else
      {
        l = mid + 1;
      }
    }
    return l;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long n;
    cin>>n;
    long sum=0;
    vector<long> cups;
    cups.reserve(n);
    vector<long> v;
    v.reserve(n);
    long a;
    for(long i = 0 ; i < n ; ++i)
    {
        cin>>a;
        cups.push_back(a);
        v.push_back(a+sum);
        sum+=cups[i];
    }
    long m;
    cin>>m;
    vector<long> amount;
    amount.reserve(m);
    for(long i = 0 ; i < m ; ++i)
    {
        cin>>a;
        amount.push_back(a);
        if(amount[i]>sum)
        {
            cout<<0;
            return 0;
        }
    }


    for(long i = 0 ; i < m ; i++)
    {
        cout<<bs_lower_bound(v,n,amount[i]) + 1<<endl;
    }
    return 0;
}

