#include <bits/stdc++.h>
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes:

    int minCost(int  arr[], int  n) {
    priority_queue<int ,vector<int >,greater<int >>pq(arr,arr+n);
       
        int  cost=0;
     while(pq.size()!=1){
        
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        
        cost+= a+b;
        pq.push(a+b);
        
       }
        return cost;
       
    }
};