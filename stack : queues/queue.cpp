#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int Front; int rear;
     int size;
public:
  Queue() { 
      size=10000;
      arr = new int[size]; 
      Front =0;
      rear=0;
}

bool isEmpty(){
    if(Front==rear){
        return true;
    }
    else{
        return false;
    }
}
  

void enqueue(int data) 
{
  if (rear == size)
  {
     
  }
  else{
      arr[rear]=data;
      rear++;
  }

    }

    int dequeue() 
    {
    int ans=arr[Front];
    if(Front==rear)
    {
        return -1;
    }
    else{
        arr[Front]=-1;
        Front++;
        if(Front==rear){
          Front=0;
          rear=0;
        }
        return ans;
     }
    }

    int front() 
    {
       if(Front == rear){
           return -1;
       }
       else{
           return arr[Front];
       }
    }
};
int main()
{

  return 0;
}
// time complexity is o(1) for all the operations;