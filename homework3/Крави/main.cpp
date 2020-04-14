#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long N, C;
void merge(vector<long> &v, long l, long mid , long r)
{
    long i , j , k;
    long n1=mid-l+1;
    long n2=r-mid;

    long* Left=new long[n1];
    long* Right=new long[n2];

    for(i=0;i<n1;i++)
    {
        Left[i]=v[l+i];
    }
    for(j=0;j<n2;j++)
    {
        Right[j]=v[mid+j+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(Left[i]<=Right[j])
        {
            v[k]=Left[i];
            i++;
        }
        else
        {
            v[k]=Right[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        v[k]=Left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        v[k]=Right[j];
        j++;
        k++;
    }
    delete[] Left;
    delete[] Right;
}
void mergeSort(vector<long> &v ,long l, long r)
{
    if(l<r)
    {
        long mid=l+(r-l)/2;
        mergeSort(v,l,mid);
        mergeSort(v,mid+1,r);

        merge(v,l,mid,r);
    }
}
long check(long n,vector<long> &hut)
{
    long cow=1;
    long position=hut[0];
    for (long i=1; i<N; i++)
    {
        if (hut[i]-position>=n)
        {
            position=hut[i];
            cow++;
            if (cow==C)
            {
                return 1;
            }
        }
    }
    return 0;
}

long binarySearch(vector<long> &huts)
{
    long l=0;
    long r=huts[N-1];
    long m=-1;
    while (r>l)
    {
        long mid=(l+r)/2;
        if (check(mid,huts)==1)
        {
            if (mid>m)
            {
                m=mid;
            }
            l=mid+1;
        }
        else
        {
            r=mid;
        }

    }
    return m;
}
int main()
{
    cin>> N >> C;
    vector<long> v;
    v.reserve(N);
    long a;
    for(long i = 0 ; i < N ; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    mergeSort(v,0,N-1);
    if(C==2)
    {
        cout<<v[N-1]-v[0];
        return 0;
    }
    cout<<binarySearch(v);
    return 0;
}

