//! function to insert top element x at the bottom of the stack
void insertatbottom(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
   
   int num= s.top(); 
    s.pop(); 

    insertatbottom(s,x);  // recursive call
    s.push(num);
}
//! main function  (to reverse stack usng recursion)
void reverseStack(stack<int> &stack) {
    if(stack.empty())
    {
     return;
    }
    int num= stack.top(); 
    stack.pop();

    reverseStack(stack);
    insertatbottom(stack,num);
    
}