//! in this we use technique of merging two sorted arrays and forming a new complete sorted array.
#include <iostream>
using namespace std;
void merge(int *arr, int s, int e)
{
  int mid = (s + e) / 2;

  //^ defining the lengths of the 2 new array to be formed
  int len1 = mid - s + 1;
  int len2 = e - mid;

  //^ defining the new arrays. Named as (fist and second)
  int *first = new int[len1];
  int *second = new int[len2];

  int k = s; //^ k is the index of the main arr

  //^ copying the elements to new arrays
  for (int i = 0; i < len1; i++)
  {
    first[i] = arr[k++];
  }
    k = mid + 1; // second array starts from mid+1

  for (int i = 0; i < len2; i++)
  {
    second[i] = arr[k++];
  }
  int index1 = 0; int index2 = 0;
  k = s;

  while (index1 < len1 && index2 < len2)
  {
    if (first[index1] < second[index2])
    {
      arr[k++] = first[index1++];
    }
    else
    {
      arr[k++] = second[index2++];
    }
  }
  while (index1 < len1)
  {
    arr[k++] = first[index1++];
  }
  while (index2 < len2)
  {
    arr[k++] = second[index2++];
  }

}

void mergesort(int *arr, int s, int e)
{
  if (s >= e)
  {
    return;
  }
  int mid = (s + e) / 2;
  mergesort(arr, s, mid);
  mergesort(arr, mid + 1, e);

  merge(arr, s, e);
}
int main()
{
  int arr[] = {1, 13, 5, 6, 12, 19, 3};
  int n = 7;
  mergesort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  
  return 0;
}