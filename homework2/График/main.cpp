#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void merge(vector<int> &begined, vector<int> &ended, long lef,long mid,long righ)
{
    long i , j , k;
    long n1=mid-lef+1;
    long n2=righ-mid;

    int* LeftEnded=new int[n1];
    int* RightEnded=new int[n2];

    int* LeftBegined=new int[n1];
    int* RightBegined=new int[n2];

    for(i=0;i<n1;i++)
    {
        LeftEnded[i]=ended[i+lef];
        LeftBegined[i]=begined[i+lef];
    }
    for(j=0;j<n2;j++)
    {
        RightEnded[j]=ended[j+mid+1];
        RightBegined[j]=begined[j+mid+1];
    }
    i=0;j=0;k=lef;
    while(i<n1 && j <n2)
    {
        if(LeftEnded[i]<=RightEnded[j])
        {
            begined[k]=LeftBegined[i];
            ended[k]=LeftEnded[i];
            i++;
        }
        else
        {
            begined[k]=RightBegined[j];
            ended[k]=RightEnded[j];
            j++;

        }
        k++;
    }
    while(i<n1)
    {
        begined[k]=LeftBegined[i];
        ended[k]=LeftEnded[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        begined[k]=RightBegined[j];
        ended[k]=RightEnded[j];
        k++;
        j++;
    }
    delete[] LeftBegined;
    delete[] LeftEnded;
    delete[] RightBegined;
    delete[] RightEnded;
}
void mergeSort(vector<int> &begined, vector<int> &ended, long lef, long righ)
{
    if(lef<righ)
    {
        long mid=lef+(righ-lef)/2;
        mergeSort(begined,ended,lef,mid);
        mergeSort(begined,ended,mid+1,righ);

        merge(begined,ended,lef,mid,righ);
    }
}
int main()
{
    long N;
    cin>>N;
    if(N==0)
    {
        cout<<0;
        return 0;
    }
    vector<int> begined;
    vector<int> ended;
    long a;
    long b;
    for(long i = 0 ; i < N; i++)
    {
        cin>>a;
        cin>>b;
        begined.push_back(a);
        ended.push_back(a+b);
    }
    long counter=1;
    int pass=0;
    mergeSort(begined, ended, 0, N-1);
    for(long i = 0;i<N;i++)
    {
        for(long j = 1;j<N;j++)
        {
            if(begined[i]==begined[j])
            {
                if(ended[i]<ended[j] && begined[j]>=ended[i])
                {
                    counter++;
                    i+=pass+1;
                    pass=0;
                }
                else
                {
                    pass++;
                }

            }
            else
            {
                if(begined[i]<begined[j] && ended[i]<=begined[j])
                {
                    counter++;
                    i+=pass+1;
                    pass=0;
                }
                else
                {
                    pass++;
                }
            }
        }
        break;
    }
    cout<<counter;
    return 0;
}
