#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(22);
    s.push(2);
    s.pop();
    cout<<s.top();
  return 0;
}