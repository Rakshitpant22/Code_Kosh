//! HEAPSORT  O(n Logn)
1st-> buildheap from array make maximum heap such that max element remains at top
class Solution
{
    public:
    void heapify(int arr[], int n, int i)  
    {
        int largest=i;
        int left= 2*i+1;
        int right=2*i+2;
        if(left<n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<n && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }

    public:
    void buildHeap(int arr[], int n)  //! O(n)->build heep takes  TC = O(n)
    { 
      for(int i=((n-1)-1)/2;i>=0;i--){
          heapify(arr,n,i);
      }
    }
//! swap the top from heap(maximum element) and swap it with last element now decreses size of array do same for remaining 
    public:
    void heapSort(int arr[], int n)
    {
       buildHeap(arr,n);
       for(int i=n-1;i>=1;i--){
           swap(arr[0],arr[i]);
           heapify(arr,i,0);
       }
    }
};