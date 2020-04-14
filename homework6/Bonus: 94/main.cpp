#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <bits/stdc++.h>

using namespace std;
struct Bus
{
    int start;
    int end;
    Bus()
    {
        start=end=0;
    }
    Bus(int newstart, int newend)
    {
        this->start=newstart;
        this->end=newend;
    }
    Bus& operator=(Bus& rhs)
    {
        if(this!= &rhs)
        {
            this->start=rhs.start;
            this->end=rhs.end;
        }
        return *this;
    }
};


void merge(vector<int> &v, int l, int mid, int r)
{
    int n1=mid-l+1;
    int n2=r-mid;

    int* Left = new int[n1];
    int* Right = new int[n2];

    for(int i = 0 ; i < n1; i++)
    {
        Left[i] = v[i+l];
    }
    for(int i = 0 ; i < n2 ; i++)
    {
        Right[i] = v[i+mid+1];
    }
    int i = 0;
    int j = 0;
    int k=l;
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
void mergeSort(vector<int> &v , int l, int r)
{
    if(l<r)
    {
        int mid=l + (r-l)/2;
        mergeSort(v,l,mid);
        mergeSort(v, mid+1,r);

        merge(v,l,mid,r);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    vector<int> v;
    v.reserve(n);
    int a=0;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    multimap<int, int> stations;
    int b;

    for(int i = 0 ; i < k ; i++)
    {
        cin>>a>>b;
        stations.insert(make_pair(a-b,b+a));
    }
    mergeSort(v,0,n-1);
    int answer=0;
    bool check=false;
    int stationsleft=k;
    multimap<int,int>::iterator index;
    int remember=0;
    multimap<int,int>::iterator j=stations.begin();
    for(int i = 0 ; i < n ; i++)
    {
        check=false;
        if(stationsleft==0)
        {
            break;
        }
        if(v[i]<stations.begin()->first)
        {
            continue;
        }
        for(j = stations.begin() ; j != stations.end() ; j++)
        {
            if(v[i]<j->first)
            {
                break;
            }
            if(v[i]>=j->first && v[i]<=j->second)
            {
                if(check==false || j->second < remember)
                {
                    check = true;
                    index = j;
                    remember = j->second;
                }
            }
        }
        if (check == true)
        {
            stations.erase(index);
            answer++;
            stationsleft--;
        }
    }

    cout << answer;



    return 0;
}

