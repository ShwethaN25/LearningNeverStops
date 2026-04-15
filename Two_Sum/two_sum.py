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


def twoSum(self, nums: List[int], target: int) -> List[int]:
    for i in range(0,len(nums)-1):
        for j in range((i+1), len(nums)):
            if nums[i]+nums[j]==target:
                return [i,j]
                

# Time complexity O(n^2)
# Space complexity O(1)



----------------------------------------------------------------------
                       BETTER APPROACH
----------------------------------------------------------------------
def two_sum_indices(self, arr, target):
        nums_with_index = [(num, idx) for idx, num in enumerate(arr)]
        
        # Sort the list by values
        nums_with_index.sort(key=lambda x: x[0])

        left, right = 0, len(arr) - 1
        
        while left < right:
            current_sum = nums_with_index[left][0] + nums_with_index[right][0]
            if current_sum == target:
                # Return original indices of found elements
                return [nums_with_index[left][1], nums_with_index[right][1]]
            elif current_sum < target:
                # Move left pointer right to increase sum
                left += 1
            else:
                # Move right pointer left to decrease sum
                right -= 1
    
        return [-1, -1]


# Time complexity O(nlogn)
# Space complexity O(n)



----------------------------------------------------------------------
                       OPTIMAL APPROACH
----------------------------------------------------------------------
( using hashmap)

def twoSum(self, nums: List[int], target: int) -> List[int]:
    seen = {}  # value -> index
    
    for i, num in enumerate(nums):
        complement = target - num
        
        if complement in seen:
            return [seen[complement], i]
        
        seen[num] = i


# Time complexity O(n)
# Space complexity O(n)





