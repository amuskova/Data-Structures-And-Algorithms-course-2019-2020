#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Coordinates
{
    long x;
    long y;
    float dist;
    Coordinates()
    {
        x=0;
        y=0;
        dist=0;
    }
    Coordinates(long newx, long newy, float newdistance)
    {
        x=newx;
        y=newy;
        dist=newdistance;
    }
    Coordinates &operator=(Coordinates &rhs)
    {
        if(this != &rhs)
        {
            this->x=rhs.x;
            this->y=rhs.y;
            this->dist=rhs.dist;
        }
        return *this;
    }

};
void swap(Coordinates &a, Coordinates &b)
{
    Coordinates tmp=a;
    a=b;
    b=tmp;
}
class minHeap
{
    private:
    vector<Coordinates> v;
    long getLeftChild(long pos)
    {
        return (2*pos + 1);
    }
    long getRightChild(long pos)
    {
        return (2*pos + 2);
    }
    long getParent(int pos)
    {
        return (pos-1)/2;
    }
    void siftUp(long pos)
    {
        if(pos <v.size() && v[getParent(pos)].dist > v[pos].dist)
        {
            swap(v[pos], v[getParent(pos)]);
            siftUp(getParent(pos));
        }
    }
    bool hasLeftChild(long pos)
    {
        if(getLeftChild(pos)<v.size())
        {
            return true;
        }
        return false;
    }
    bool hasRightChild(long pos)
    {
        if(getRightChild(pos)< v.size())
        {
            return true;
        }
        return false;
    }
    void siftDown(long pos)
    {
        long left=getLeftChild(pos);
        long right=getRightChild(pos);
        long smallest=pos;
        if(left< v.size() && v[left].dist < v[pos].dist)
        {
            smallest=left;
        }
        if(right<v.size() && v[right].dist < v[smallest].dist)
        {
            smallest=right;
        }
        if(smallest != pos)
        {
            swap(v[pos],v[smallest]);
            siftDown(smallest);
        }
    }
public:
    bool isEmpty()
    {
        if(v.size() == 0)
        {
            return true;
        }
        return false;
    }
    void add(Coordinates &num)
    {
        v.push_back(num);
        if(v.size() != 0)
        {
            siftUp(v.size()-1);
        }
    }
    Coordinates& getPeek()
    {
        return v[0];
    }
    void pop()
    {
        if(isEmpty()==true)
        {
            return;
        }
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        siftDown(0);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long N,K;
    cin>>N>>K;
    vector<Coordinates> v;
    vector<Coordinates> answer;
    answer.reserve(K);
    v.reserve(N);
    Coordinates cord;
    minHeap heap;
    long a=0,b=0;
    for(long i = 0 ; i< N ; i++)
    {
        cin>>cord.x>>cord.y;
        cord.dist=sqrt(cord.x*cord.x + cord.y*cord.y);
        heap.add(cord);
    }
    answer[0]=heap.getPeek();
    heap.pop();
    for(long i = 1 ; i < K  ; i++)
    {
       answer[i]=heap.getPeek();
       heap.pop();
       if(answer[i-1].dist == answer[i].dist && answer[i-1].x > answer[i].x)
        {
            swap(answer[i-1] , answer[i]);
        }
        else if(answer[i-1].dist == answer[i].dist && answer[i-1].x == answer[i].x && answer[i-1].y > answer[i].y)
        {
            swap(answer[i-1] , answer[i]);
        }
        cout<<answer[i-1].x<<" "<<answer[i-1].y<<endl;
    }
    cout<<answer[K-1].x<<" "<<answer[K-1].y;

    return 0;
}
