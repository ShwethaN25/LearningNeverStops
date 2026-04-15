Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.

----------------------------------------------------------------------
                       BRUTE FORCE APPROACH
----------------------------------------------------------------------

bool containsDuplicate(vector<int>& nums) 
{
    int n = nums.size();
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}
// Time complexity O(n^2)
// Space complexity O(1)



----------------------------------------------------------------------
                       BETTER APPROACH
----------------------------------------------------------------------

bool containsDuplicate(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) 
    {
        if (nums[i] == nums[i - 1])
            return true;
    }
    return false;
}
// Time complexity O(nlogn)
// Space complexity O(1)



----------------------------------------------------------------------
                       OPTIMAL APPROACH
----------------------------------------------------------------------

//Earlier I wrote 
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    return nums.size() != s.size();
}

// But with this approach there is no early Exit → Inefficient.
// Inserting all elements first, even if a duplicate appears early.
// Worst case: Duplicate at index 1 -> still process entire array

// Below is the optimal approach
bool containsDuplicate(vector<int>& nums) 
{
    unordered_set<int> s;

    for (int x : nums) 
    {
        if (s.find(x) != s.end())
            return true;
        s.insert(x);
    }
    return false;
}

// Time complexity O(n)
// Space complexity O(n)








