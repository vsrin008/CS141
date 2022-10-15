#include <iostream>
using namespace std;
int cnt = 0;

void merge(int *array, int left, int m, int right)
{
    int i, j, k, nl, nr;
    nl = m - left + 1;
    nr = right - m;
    int lhs[nl], rhs[nr];
    for (i = 0; i < nl; i++)
    {
        lhs[i] = array[left + i];
    }
    for (j = 0; j < nr; j++)
    {
        rhs[j] = array[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < nl && j < nr)
    {
        if (lhs[i] >= rhs[j])
        {
            array[k] = lhs[i];
            i++;
        }
        else
        {
            array[k] = rhs[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    { 
        array[k] = lhs[i];
        i++;
        k++;
    }
    while (j < nr)
    { 
        array[k] = rhs[j];
        j++;
        k++;
    }
    cnt = array[left] - array[right] + cnt;
}

void mergeSort(int *array, int begin, int end)
{
    if (begin >= end) {
        return;
    }
        int mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    
}
int main()
{
    int n;
    cin >> n;
    int arr[n]; 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1); 
    cout << cnt << endl;
}