You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. 

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

----------------------------------------------------------------------
                       BRUTE FORCE APPROACH
----------------------------------------------------------------------

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        // Loop through all possible buy and sell days
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) 
        {
            for(int j = i + 1; j < prices.size(); j++) 
            {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};
// Time complexity O(n^2)
// Space complexity O(1)


----------------------------------------------------------------------
                       OPTIMAL APPROACH
----------------------------------------------------------------------
(greedy approach)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;

        for (int price : prices) {
            if (price < min_price) {
                min_price = price;
            } else {
                max_profit = max(max_profit, price - min_price);
            }
        }
        return max_profit;
    }
};

// Time complexity O(n)
// Space complexity O(1)

