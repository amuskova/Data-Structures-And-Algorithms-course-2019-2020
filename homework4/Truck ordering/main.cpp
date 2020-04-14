#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T != 0)
    {
        long minn=1;
        vector<long> str;
        str.push_back(0);
        long h=0;
        long N;
        cin>>N;
        long p=N;
        vector<long> v;
        v.reserve(N);
        long a;
        for(long i = 0 ; i < N ; i++)
        {
            cin>>a;
            v.push_back(a);
        }
        for(int i = 0 ; i < p; i++)
        {
            if(v[h]==minn && h<N)
            {
                h++;
                minn++;
            }
            else if(str.back()==minn)
            {
                str.pop_back();
                minn++;
            }
            else if(h<N)
            {
                p++;
                str.push_back(v[h]);
                h++;
            }
        }
        if(str.size()==1)
        {

            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
        h=0;
        T--;
    }
    return 0;
}

