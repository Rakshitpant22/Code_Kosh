#include<iostream>
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubblesort(int arr[],int n)
{
  for (int i  = 0; i < n-1; i++)
  {
    for (int j = i+1; j < n; j++)
    while( arr[j]< arr[i])
    {
      swap(&arr[i],&arr[j]);
    }
  }
}

  void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
  int arr[]={1,7,6,10,9,14};
  int  n = sizeof(arr)/sizeof(arr[0]);
  printArray(arr,n);
  bubblesort(arr,n);
  printArray(arr,n);

  return 0;
}