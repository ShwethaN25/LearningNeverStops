Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
 
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

----------------------------------------------------------------------
                       BRUTE FORCE APPROACH
----------------------------------------------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {}; 
    }
};

// Time complexity O(n^2)
// Space complexity O(1)



----------------------------------------------------------------------
                       BETTER APPROACH
----------------------------------------------------------------------

class Solution 
{
    public:
        vector<int> twoSum(vector<int> arr, int target) 
        {
            int n = arr.size();
            vector<pair<int, int>> numsWithIndex;
            for (int i = 0; i < n; i++) 
            {
                numsWithIndex.push_back({arr[i], i});
            }
            sort(numsWithIndex.begin(), numsWithIndex.end());

            int left = 0, right = n - 1;
            while (left < right) 
            {
                int sum = numsWithIndex[left].first + numsWithIndex[right].first;
                if (sum == target) 
                    // Return original indices
                    return {numsWithIndex[left].second, numsWithIndex[right].second};
                else if (sum < target) 
                    left++;
                else 
                    right--;                
            }
            return {}; 
        }
};

// Time complexity O(nlogn)
// Space complexity O(n)



----------------------------------------------------------------------
                       OPTIMAL APPROACH
----------------------------------------------------------------------
( using hashmap)

#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mp;   //<value, idx>
        
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];            
            if (mp.find(complement) != mp.end())
            {
                return {mp[complement], i};
            }            
            mp[nums[i]] = i;
        }        
        return {};
    }
};

// Time complexity O(n)
// Space complexity O(n)








