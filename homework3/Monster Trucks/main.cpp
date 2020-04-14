#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<long> &dist, vector<long> &dop, long l, long mid, long r)
{
    long i, j , k;
    long n1=mid-l+1;
    long n2= r - mid;

    long* LeftDist=new long[n1];
    long* RightDist=new long[n2];

    long* LeftDop=new long[n1];
    long* RightDop=new long[n2];

    for(i=0;i<n1;i++)
    {
        LeftDist[i]=dist[l+i];
        LeftDop[i]= dop[l+i];
    }
    for(j=0;j<n2;j++)
    {
        RightDist[j]=dist[mid+j+1];
        RightDop[j] = dop[mid+j+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j < n2)
    {
        if(LeftDist[i]<=RightDist[j])
        {
            dist[k]=LeftDist[i];
            dop[k]=LeftDop[i];
            i++;
        }
        else
        {
            dist[k]=RightDist[j];
            dop[k]=RightDop[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        dist[k]=LeftDist[i];
        dop[k]=LeftDop[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        dist[k]=RightDist[j];
        dop[k]=RightDop[j];
        j++;
        k++;
    }
    delete[] LeftDist;
    delete[] RightDist;
    delete[] LeftDop;
    delete[] RightDop;
}
void mergeSort(vector<long> &dist,vector<long> &dop, long l,long r)
{
    if(l<r)
    {
        long mid=l+(r-l)/2;
        mergeSort(dist,dop,l,mid);
        mergeSort(dist,dop,mid+1,r);

        merge(dist,dop,l,mid,r);
    }
}
int main()
{
    long N;
    cin>>N;
    vector<long> sant;
    sant.reserve(N);
    vector<long> monsters;
    monsters.reserve(N);
    long a,b;//sum=0;
    for(long i = 0 ; i < N;i++)
    {
        cin>>a>>b;
        sant.push_back(a);
        monsters.push_back(b);
    }
    mergeSort(sant,monsters,0,N-1);
    long otg=0;
    long counter=0;
    for(long i= 0 ; i < N ; i++)
    {
        for(long j = 0 ; j < N ; j++)
        {
            if(i!=j)
            {
                counter+=abs(sant[i]-sant[j])*monsters[j];
            }
        }
        if(otg==0)
        {
           otg=counter;
           counter=0;
         }
         else
         {
            if(counter<=otg)
            {
               otg=counter;
               counter=0;
            }
          }
    }
    cout<<otg;

    return 0;
}
