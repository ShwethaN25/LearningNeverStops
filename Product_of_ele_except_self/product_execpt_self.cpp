Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

----------------------------------------------------------------------
                       BRUTE FORCE APPROACH
----------------------------------------------------------------------


vector<int> productExceptSelf(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> answer;

    for (int i = 0; i < n; i++) 
    {
        int prod = 1;
        for (int j = 0; j < n; j++) 
        {
            if (i != j) 
            {
                prod *= nums[j];
            }
        }
        answer.push_back(prod);
    }
    return answer;
}

// Time complexity O(n^2)
// Space complexity O(1)



----------------------------------------------------------------------
                       BETTER APPROACH
----------------------------------------------------------------------

vector<int> productExceptSelf(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    vector<int> answer(n, 1);

    // prefix
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // suffix
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // result
    for (int i = 0; i < n; i++) {
        answer[i] = prefix[i] * suffix[i];
    }

    return answer;
}

// Time complexity O(n)
// Space complexity O(n)



----------------------------------------------------------------------
                       OPTIMAL APPROACH
----------------------------------------------------------------------
( using hashmap)

#include <unordered_map>

vector<int> productExceptSelf(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> answer(n, 1);

    int prefix = 1;
    // prefix pass
    for (int i = 0; i < n; i++) 
    {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    // suffix pass
    for (int i = n - 1; i >= 0; i--) 
    {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}

// Time complexity O(n)
// Space complexity O(1)(excluding output)








