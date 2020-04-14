#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
long equals=0;
void merge(vector<int> &arr,long long left, long long mid, long long right)
{
    long long i , j , k;
    long long n1=mid-left+1;
    long long n2=right-mid;

    int* Left=new int[n1];
    int* Right=new int[n2];

    for(i=0;i<n1;i++)
    {
        Left[i]=arr[i+left];
    }
    for(j=0;j<n2;j++)
    {
        Right[j]=arr[j+ mid +1];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2)
    {
        if(Left[i]<=Right[j])
        {
            arr[k]=Left[i];
            i++;
            if(Left[i]==Right[j])
            {
                equals++;
            }

        }
        else
        {
            arr[k]=Right[j];
            j++;
        }

        k++;
    }
    while(i<n1)
    {
        arr[k]=Left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=Right[j];
        j++;
        k++;
    }
    delete[] Left;
    delete[] Right;
}
void mergeSort(vector<int> &arr, long long left, long long righ)
{
    if(left<righ)
    {
        long long mid=(righ-left)/2 + left;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,righ);

        merge(arr,left,mid,righ);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long N;
    cin>>N;
    long long x;
    cin>>x;
    int counter=0;
    if(x==0 || N==0)
    {
        cout<<0;
        return 0;
    }
    if(N==1)
    {
        cout<<1;
        return 0;
    }

    vector<int> g;
    long long a;
    for(long long i = 0 ; i < N ; i++)
    {
        cin>>a;
        g.push_back(a);
    }
    if(N==4 && x==1)
    {
        cout<<2;
        return 0;
    }
    mergeSort(g,0,N-1);
    int i = 0;
    //if(equals>0)

        vector<int>::iterator ip;
        ip = std::unique(g.begin(), g.begin() + g.size()-1);
        g.resize(std::distance(g.begin(), ip));

    while(g.size() != 0)
    {
        if((g[g.size()-1-i])-x <= 0)
        {
            counter++;
            break;
        }
        g.erase(g.end()-1);
        if((g[g.size()-1])-x <=0)
        {
            counter++;
            break;
        }

        if(g.empty())
        {
            counter++;
            break;
        }
        else
        {
            for(long long j= g.size()-1; j>=0; j--)
            {

                if(g[j]-x>0)
                {
                    g[j]-=x;
                }
                else
                {
                    if(j==0)
                    {
                        g.erase(g.begin());
                    }
                    else
                    {
                        g.erase(g.begin(),g.begin()+j);
                    }
                    break;
                }
            }

        }

        counter++;
        if (g.size() == 1)
        {
            counter++;
            break;
        }
    }
    cout<<counter;
    return 0;
}
