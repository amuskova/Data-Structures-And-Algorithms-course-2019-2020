#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
 vector<int> g1;
    int T;
    cin>>T;
    int a;
    int capacity=T*2;
    for(int i = 0; i < capacity; i++)
    {
        cin>>a;
        g1.push_back(a);
    }
    while(capacity>=1){
       if(g1[1] <= 1 && g1[0] != 0)
        {
            cout<<"no"<<endl;
        }
        else if(g1[0] > 0 && g1[1] == 0)
        {
            cout<<"no"<<endl;
        }
        else if(g1[1] == 1 && g1[0] == 0)
        {
            cout<<"yes"<<endl;
        }
        else if(g1[0] % 2 == 0 && g1[1] % 2 != 0 )
        {
                if(g1[0] < g1[1] && g1[1] != g1[0]+1)
                {
                    cout<<"no"<<endl;
                }
                else
                {
                    cout<<"yes"<<endl;
                }
        }
        else if(g1[0] % 2 != 0 && g1[1] % 2 != 0)
        {
            cout<<"no"<<endl;
        }
        else if(g1[0] % 2== 0 && g1[1] % 2 == 0)
        {
            cout<<"no"<<endl;
        }
        else if(g1[0]% 2 !=0 && g1[1] % 2 ==0)
        {
            if(g1[0] < g1[1] && g1[1] != g1[0]+1)
            {
                cout<<"no"<<endl;
            }
            else
            {
                cout<<"yes"<<endl;
            }
        }
        else if(g1[0]==g1[1])
        {
            cout<<"no"<<endl;
        }
        else if (g1[0] <= g1[1] && g1[0]!= g1[1]+1 && g1[1] != g1[0]+1)
        {
            cout<<"no"<<endl;
        }

        g1.erase(g1.begin());
        g1.erase(g1.begin());
        capacity-=2;
    }
    return 0;
}

