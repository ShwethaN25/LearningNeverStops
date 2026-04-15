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

def containsDuplicate(nums):
    n = len(nums)
    for i in range(n):
        for j in range(i + 1, n):
            if nums[i] == nums[j]:
                return True
    return False
                

# Time complexity O(n^2)
# Space complexity O(1)



----------------------------------------------------------------------
                       BETTER APPROACH
----------------------------------------------------------------------
def containsDuplicate(nums):
    nums.sort()   

    for i in range(1, len(nums)):
        if nums[i] == nums[i - 1]:
            return True
    return False


# Time complexity O(nlogn)
# Space complexity O(n)



----------------------------------------------------------------------
                       OPTIMAL APPROACH
----------------------------------------------------------------------

# Earlier I wrote 

def containsDuplicate(nums):
    return len(nums) != len(set(nums))

# But with this approach there is no early Exit → Inefficient.
# Inserting all elements first, even if a duplicate appears early.
# Worst case:  Duplicate at index 1 -> still process entire array

# Below is the optimal approach

def containsDuplicate(nums):
    seen = set()
    for x in nums:
        if x in seen:
            return True
        seen.add(x)

    return False


# Time complexity O(n)
# Space complexity O(n)





