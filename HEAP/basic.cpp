HEAP -> binary tree can be represented as array 
//! Implement min heap and following functions-> {Inert,hepify,delete,getmin,extractmin,buildheep};
// i then left=2*i+1 right=2*i+2, and parent= (i-1/2);

void heapifyup(int arr,int i){
 while(i!=0 && arr[(i-1)/2]>arr[i]){
    swap(arr[i],arr[(i-1)/2]);
    i=(i-1)/2; 
 }
}

void heapify(int arr,int i){    //^O(logn)
 int smallest=i;
 int left = 2*i + 1;
 int right= 2*i + 2;

 if(left<n && arr[left]<smallest){
    smallest=left;
 }
 if(right<n && arr[right]<smallest){
    smallest=right;
 }
 if(smallest!=i){
  swap(nums[smallest],nums[i]);
  heapify(arr,smallest);
 }
}

void buildheap(vector<int>&arr,int n){
    for(int i=((n-1)-1)/2;i>=1;i--){
        heapify(arr,i);
    }
}

void insert(int x,vector<int>&arr){
    arr.push_back(x);
    heapifyup(arr.size()-1);
}

//!  Remove min element from the heap and return it; 
//since 1st element would be deleted and largest /last element of array will be swapped with index 0 then
int extractmin(){                 //^ O(logn)
    if(arr.size()==0)return 1e9;
    if(arr.size==1){
        int x=arr[0];
        arr.pop_back();
        return x;
    }
    int min_element=arr[0];
    swap(arr[0],arr[n-1]);
    arr.pop_back();
    heapify(arr,0);
    return min_element;
}

//! Decrease key-> change value of index to another 
void decrease(int i,int x){
 arr[i]=x;
 heapifyup(i);
}

//! delete a particular key  
//go to the index to be changed make to -1e9 then do exractmin 

void deletekey(int i,vector<int>&arr){  //^ O(logn)
    arr[i]=-1e9;
    heapifyup(i);
    extractmin();
}


