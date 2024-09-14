#include <iostream>
using namespace std;
int partition(int arr[], int s, int e)
{
   
    int pivot = arr[s];  
    int cnt = 0;   
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }
    int pivotindex = s + cnt;
    swap(arr[pivotindex], arr[s]);

    int i = s ; int j = e;
    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotindex;
}
void quicksort(int arr[], int s, int e)
{
    if (s >= e) // base conditon
        return;
    int p = partition(arr, s, e);

    quicksort(arr, s, p - 1);

    quicksort(arr, p + 1, e);
}
int main()
{
    int arr[5] = {56,32,22,12,5};
    int n = 5;
    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}


/*
! In quick sort we make a pivot(reference value around which sorting implements)
 Example:
 array =[3,1,4,5,2]
 ^ take a pivot , count=  count all elements <a , send pivot = start+count
 then implement code as if a is pivot then in array[<a,a,a>] order must be there.
 

 & NOTE:
 < Quick sort is prefered over merge sort for sorting arrays bcs merge sort requires an extra array for merging ,that's not
   in case of quick sort.
 < Merge sort is prefered in case of linked lists bcs LL nodes are not adjacent in the memory so merging technique can be 
   implemented easilyf or the case of linked lists.  
*/

