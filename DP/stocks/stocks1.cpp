Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       int mini= prices[0];
        int profit=0;

        for(int i=0;i<n;i++){
            int cost = prices[i]-mini;
            profit= max(cost,profit);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};