//!  Grumpy Bookstore Owner
// There is a bookstore owner that has a store open for n minutes. You are given an integer array customers of length n where customers[i] is the number of the customers that enter the store at the start of the ith minute and all those customers leave after the end of that minute.
// During certain minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.
// When the bookstore owner is grumpy, the customers entering during that minute are not satisfied. Otherwise, they are satisfied.
// The bookstore owner knows a secret technique to remain not grumpy for minutes consecutive minutes, but this technique can only be used once.
// Return the maximum number of customers that can be satisfied throughout the day.

// Example 1:
// Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
// Output: 16

// Explanation:
// The bookstore owner keeps themselves not grumpy for the last 3 minutes.
// The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.


 int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
 // We iterate through k size window --> in which we get max customers who were grumpy =maxi(us k size ki window me max customers bnalo jo pehle grumpy the)
 // After that we add all non grumpy + maxi

    long long cust=0,n=customers.size();
    for(int i=0;i<minutes;i++){
        if(grumpy[i])cust+=customers[i];
    }
    int maxi=cust,l=0,r=minutes;

    while(r<n){
        if(grumpy[r]) cust += customers[r];//right boundry
        if(grumpy[l]) cust -= customers[l];//left boundry
        maxi=max(maxi,(int)cust);
        l++;
        r++;
    }
    // now add those customers that are 
    cust=maxi;
    for(int i=0;i<customers.size();i++){
        if(!grumpy[i]){
         cust+=customers[i];
        }
    }
    return cust;
    }