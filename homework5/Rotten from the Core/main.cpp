#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main() {

   int N, M , T;
   cin>>N>>M>>T;
   int matrix[N][M];
   for(int i = 0 ; i < N ; i++)
   {
       for(int j = 0 ; j < M ; j++)
       {
           matrix[i][j]=-1;
       }
   }
   int n, m;
   list <pair<int,int> > l;
   int sum=N*M;
   while(cin>>n>>m)
   {
        l.push_back(make_pair(n,m));
        sum--;
        matrix[n-1][m-1]=0;
   }
   int k=0;
   pair<int,int> p;
   while(!l.empty())
   {
       p=l.front();
       int y=p.first-1;
       int x=p.second-1;
       if(k != matrix[y][x])
       {
           k++;
       }
       if(matrix[y][x] != T)
       {
           if(matrix[y][x-1] == -1 && y>=0 && y<N && x-1>=0 && x-1<M)
           {
               l.push_back(make_pair(y+1,x));
               sum--;
               matrix[y][x-1]=k+1;
           }
           if(matrix[y][x+1] == -1 && y>=0 && y<N && x+1>=0 && x+1<M)
           {
               l.push_back(make_pair(y+1,x+2));
               sum--;
               matrix[y][x+1]=k+1;
           }
           if(matrix[y-1][x] == -1 && y-1>=0 && y-1<N && x>=0 && x<M)
           {
               l.push_back(make_pair(y,x+1));
               sum--;
               matrix[y-1][x]=k+1;
           }
           if(matrix[y+1][x] == -1 && y+1>=0 && y+1<N && x>=0 && x<M)
           {
               l.push_back(make_pair(y+2,x+1));
               sum--;
               matrix[y+1][x]=k+1;
           }

       }
       l.pop_front();
   }

    cout<<sum;

    return 0;
}
