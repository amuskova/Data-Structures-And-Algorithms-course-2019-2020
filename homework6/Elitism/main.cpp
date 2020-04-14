#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=a;
}
class maxHeap
{
private:
    vector<double> v;
    int getLeftChild(int pos)
    {
        return pos*2 +1;
    }
    int getRightChild(int pos)
    {
        return 2*pos+2;
    }
    int getParent(int pos)
    {
        return (pos-1)/2;
    }
    void siftUp(int pos)
    {
        int parent=getParent(pos);
        while(v[pos]>v[parent])
        {
            swap(v[pos],v[parent]);
            if(parent<=0)
            {
                return;
            }
            parent=getParent(parent);
            pos=getParent(pos);
        }
    }
    bool hasRightChild(int pos)
    {
        if(getRightChild(pos)<v.size())
        {
           return true;
        }
        return false;
    }
    bool hasLeftChild(int pos)
    {
        if(getLeftChild(pos)<v.size())
        {
           return true;
        }
        return false;
    }
    void siftDown(int pos)
    {
        if(hasRightChild(pos) && (v[pos]<v[getLeftChild(pos)] || v[pos]<v[getRightChild(pos)]))
        {
            int help=-1;
            if(v[getLeftChild(pos)] < v[getRightChild(pos)])
            {
                help = getRightChild(pos);
            }
            else
            {
                help=getLeftChild(pos);
            }
            swap(v[pos],v[help]);
            siftDown(help);
        }
        else if (hasLeftChild(pos) && v[pos] < v[getLeftChild(pos)])
        {
            swap(v[pos], v[getLeftChild(pos)]);
            siftDown(getLeftChild(pos));
        }
    }
public:
    int sizeMaxi()
    {
        return v.size();
    }
    bool isEmptyMax()
    {
        if(v.size()==0)
        {
            return true;
        }
        return false;
    }
    void addMax(double number)
    {
        v.push_back(number);
        if(v.size() != 0)
        {
            siftUp(v.size() - 1);
        }
    }
    int peekMax()
    {
        return v[0];
    }
    void popMax()
    {
        if(isEmptyMax())
        {
            return;
        }
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        siftDown(0);
    }
};

class minHeap
{
private:
    vector<double> v;
    int getLeftChild(int pos)
    {
        return pos*2 +1;
    }
    int getRightChild(int pos)
    {
        return 2*pos+2;
    }
    int getParent(int pos)
    {
        return (pos-1)/2;
    }
    void siftUp(int pos)
    {
        if(pos && v[getParent(pos)] > v[pos])
        {
            swap(v[pos],v[getParent(pos)]);
            siftUp(getParent(pos));
        }
    }
    bool hasRightChild(int pos)
    {
        if(getRightChild(pos)<v.size())
        {
           return true;
        }
        return false;
    }
    bool hasLeftChild(int pos)
    {
        if(getLeftChild(pos)<v.size())
        {
           return true;
        }
        return false;
    }
    void siftDown(int pos)
    {
        int left=getLeftChild(pos);
        int right = getRightChild(pos);
        int smallest=pos;
        if(left<v.size() && v[left]< v[pos])
        {
            smallest=left;
        }
        if(right<v.size() && v[right]<v[smallest])
        {
            smallest=right;
        }
        if(smallest != pos)
        {
            swap(v[pos], v[smallest]);
            siftDown(smallest);
        }
    }
public:
    int sizeMini()
    {
        return v.size();
    }
    bool isEmptyMin()
    {
        if(v.size()==0)
        {
            return true;
        }
        return false;
    }
    void addMin(double number)
    {
        v.push_back(number);
        if(v.size() != 0)
        {
            siftUp(v.size() - 1);
        }
    }
    int peekMin()
    {
        return v[0];
    }
    void popMin()
    {
        if(isEmptyMin())
        {
            return;
        }
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        siftDown(0);
    }
};

void helpWithMedians(vector<double> &v, int N)
{
    maxHeap maxi;
    minHeap mini;
    double med=v[0];
    maxi.addMax(med);
    printf("%.1f \n", med);
    for(int i = 1 ; i < N ; i++)
    {
        double x=v[i];
        if(maxi.sizeMaxi() > mini.sizeMini())
        {
            if (x < med)
            {
                mini.addMin(maxi.peekMax());
                maxi.popMax();
                maxi.addMax(x);
            }
            else
                mini.addMin(x);

            med = (maxi.peekMax() + mini.peekMin())/2.0;
        }
        else if (maxi.sizeMaxi()==mini.sizeMini())
        {
            if (x < med)
            {
                maxi.addMax(x);
                med = (double)maxi.peekMax();
            }
            else
            {
                mini.addMin(x);
                med = (double)mini.peekMin();
            }
        }
        else
        {
            if (x > med)
            {
                maxi.addMax(mini.peekMin());
                mini.popMin();
                mini.addMin(x);
            }
            else
                maxi.addMax(x);

            med = (maxi.peekMax() + mini.peekMin())/2.0;
        }
        printf("%.1f \n", med);
    }
}
int main() {
    int N;
    cin>>N;
    vector<double> v;
    v.reserve(N);
    double a;

    for(int  i = 0 ; i < N ; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    helpWithMedians(v,N);
    return 0;
}
