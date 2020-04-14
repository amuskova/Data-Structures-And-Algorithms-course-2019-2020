
#include <iostream>
#include <vector>
#include <algorithm>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
long long helper = 0;
void merge(int arr[], long l, long m, long r)
{
    long i, j, k;
    long n1 = m - l + 1;
    long n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (size_t i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (size_t j = 0; j < n2; j++)
    {
        R[j] = arr[m + j + 1];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            helper+=n1-i;
        }
        k++;
    }
    if (i < n1)
    {
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;

    }
    delete[] L;
    delete[] R;
}
void mergeSort(int arr[], long l, long r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    long n;
    cin >> n;
    int* arr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);
    cout << helper;
    delete[] arr;
    return 0;
}
