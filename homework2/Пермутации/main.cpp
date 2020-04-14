#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(char a[] ,long long leftSide,long long middle ,long long rightSide)
{
    long long i , k , j;
    long long size1 = middle-leftSide+1;
    long long size2 = rightSide-middle;

    char Left[size1], Right[size2];

    for( i = 0 ; i < size1 ; i++)
    {
        Left[i]=a[leftSide + i];
    }
    for( j = 0 ; j < size2 ; j++)
    {
        Right[j]=a[middle+j+1];
    }
    i=0;
    j=0;
    k=leftSide;
    while(i < size1 && j < size2)
    {
        if(Left[i] <= Right[j])
        {
            a[k]=Left[i];
            i++;
        }
        else
        {
            a[k]=Right[j];
            j++;
        }
        k++;
    }
    while(i<size1)
    {
        a[k]=Left[i];
        k++;
        i++;
    }
    while(j<size2)
    {
        a[k]=Right[j];
        k++;
        j++;
    }
}
void mergeSort(char a[] , long long leftSide ,long long rightSide)
{
    if(leftSide<rightSide)
    {
        long long middle = leftSide + (rightSide-leftSide)/2;
        mergeSort(a,leftSide,middle);
        mergeSort(a,middle+1,rightSide);
        merge(a,leftSide,middle,rightSide);
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long N;
    cin>>N;
    if(N==0)
    {
        cout<<"yes";
        return 0;
    }
    char* Word1=new char[N];
    char* Word2=new char[N];
    for(long i = 0 ; i < N ; i++)
    {
        cin >> Word1[i];
    }
    for(long i = 0 ; i < N ; i++)
    {
        cin >> Word2[i];
    }
    if (N==1)
    {
        if (Word1[0] == Word2[0])
        {
            cout << "yes";
            return 0;
        }
        else
        {
            cout << "no";
            return 0;
        }
    }
    mergeSort(Word1, 0 , N-1);
    mergeSort(Word2 , 0 , N - 1);
    for(int i = 0 ; i < N ; i++)
    {
        if(Word1[i]!=Word2[i])
        {
          cout<<"no";
          delete[] Word1;
          delete[] Word2;
          return 0;
        }
    }
    cout<<"yes";
    delete[] Word1;
    delete[] Word2;
    return 0;
}
