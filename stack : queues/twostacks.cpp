#include <iostream>
using namespace std;
class stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    stack(int s)
    {
        this->size = s;
        arr = new int[s];
        top1 = -1;
        top2 = s;
    }
    void push1(int element)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
        int pop1()
        {
            if (top1 >= 0)
            {
                top1--;
                int ans = arr[top1] ;
                return ans;
            }
            else
            {
                return -1;
            }
        }
        int pop2()
        {
            if (top2 < size)
            {
                top2++;
                int ans = arr[top2];
                return ans;
            }
            else
            {
                return -1;
            }
        }
        int peek()
        {
            if (top1 >= 0)
            {
                return arr[top1];
            }
            else if (top2 < size)
                return arr[top2];
        }

    
    bool isempty()
    {
        if (top1 == -1)
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
    s.push1(4);
    s.push2(9);
    s.push1(41);
    cout << s.peek() << endl;

    s.pop2();

    return 0;
}