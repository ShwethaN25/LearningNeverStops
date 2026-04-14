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
class Solution:
    def maxProfit(self, prices):
        maxProfit = 0

        # Loop through all possible buy and sell days
        for i in range(len(prices)):
            for j in range(i + 1, len(prices)):
                profit = prices[j] - prices[i]
                maxProfit = max(maxProfit, profit)
        return maxProfit
    
# Time complexity O(n^2)
# Space complexity O(1) 


----------------------------------------------------------------------
                       OPTIMAL APPROACH
----------------------------------------------------------------------
(greedy approach)

class Solution:
    def maxProfit(self, prices):
        min_price = float('inf')
        max_profit = 0

        for p in prices:
            min_price = min(min_price, p)
            max_profit = max(max_profit, p - min_price)

        return max_profit


# Time complexity O(n)
# Space complexity O(1)




