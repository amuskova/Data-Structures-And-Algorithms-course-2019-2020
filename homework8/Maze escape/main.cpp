#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int n,m;
    cin>>n>>m;
    char c;
    int matrix[n][m];
    pair<int,int> start;
    pair<int,int> end;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin>>c;
            if(c=='#')
            {
                matrix[i][j]=-3;
            }
            else if(c == '.')
            {
                matrix[i][j]=-1;
            }
            else if(c == 'S')
            {
                matrix[i][j]=0;
                start.first=i;
                start.second=j;
            }
            else
            {
                end.first=i;
                end.second=j;
                matrix[end.first][end.second]=-1;
            }
        }
    }

    queue<pair<int,int>>q;
    q.push(start);
    int k=0;
    pair<int,int> p;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        int x=p.first;
        int y=p.second;
        k = matrix[x][y];

        for(int i = x-1; i >= 0 ; i--)
        {
            if(matrix[i][y] == -3)
            {
                if (i != x-1)
                {
                    if (matrix[i+1][y] == -1 || matrix[i+1][y] > k+1)
                    {
                        q.push(make_pair(i+1,y));
                        matrix[i+1][y] = k+1;
                    }
                }
                break;
            }
        }

        for(int i = y+1; i < m ; i++)
        {
            if(matrix[x][i] == -3)
            {
                if (i != y+1)
                {
                    if (matrix[x][i-1] == -1 || matrix[x][i-1] > k+1)
                    {
                        q.push(make_pair(x,i-1));
                        matrix[x][i-1]=k+1;
                    }
                }
                break;
            }
        }

        for(int i = x+1; i < n ; i++)
        {
            if(matrix[i][y] == -3)
            {
                if (i != x+1)
                {
                    if (matrix[i-1][y] == -1 || matrix[i-1][y] > k+1)
                    {
                        q.push(make_pair(i-1,y));
                        matrix[i-1][y]=k+1;
                    }
                }
                break;
            }
        }

        for(int i = y-1; i >=0 ; i--)
        {
            if(matrix[x][i] == -3)
            {
                if (i != y-1)
                {
                    if (matrix[x][i+1] == -1 || matrix[x][i+1] > k+1)
                    {
                        q.push(make_pair(x,i+1));
                        matrix[x][i+1]=k+1;
                    }
                }
                break;
            }
        }

        if (matrix[x-1][y] == -1)
        {
            if (matrix[x-1][y] == -1 || (matrix[x-1][y] < k+1 && matrix[x-1][y] != -3))
            {
                matrix[x-1][y] = k+1;
            }
            q.push(make_pair(x-1, y));
        }

        if (matrix[x][y+1] == -1)
        {
            if (matrix[x][y+1] == -1 || (matrix[x][y+1] < k+1 && matrix[x][y+1] != -3))
            {
                matrix[x][y+1] = k+1;
            }
            q.push(make_pair(x, y+1));
        }

        if (matrix[x+1][y] == -1)
        {
            if (matrix[x+1][y] == -1 || (matrix[x+1][y] < k+1 && matrix[x+1][y] != -3))
            {
                matrix[x+1][y] = k+1;
            }
            q.push(make_pair(x+1, y));
        }

        if (matrix[x][y-1] == -1)
        {
            if (matrix[x][y-1] == -1 || (matrix[x][y-1] < k+1 && matrix[x][y-1] != -3))
            {
                matrix[x][y-1] = k+1;
            }
            q.push(make_pair(x, y-1));
        }

    }

    cout<<matrix[end.first][end.second];

    return 0;
}
