#include <iostream>
using namespace std;
class stack
{
public:
    int *arr;
    int size;
    int top;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout <<"Stack Overflow"<<endl;
        }
    }
        void pop()
        {
            if (top >= 0)
            {
                top--;
            }
            else
            {
                cout << "stack underflow" << endl;
            }
        }
        int peek()
        {
            if (top >= 0)
            {
                return arr[top];
               
            }
            else
            {
                cout << "stack is empty" << endl;
                return -1;
            }
        }
        bool isempty()
        {
            if (top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};
int main()
{
    stack s(4);
    s.push(4);
    s.push(9);
    s.push(41);
    cout << s.peek()<<endl;

    s.pop();
     cout << s.peek();

    return 0;
}