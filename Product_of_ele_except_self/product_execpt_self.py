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

def productExceptSelf(nums):
    n = len(nums)
    answer = []

    for i in range(n):
        prod = 1
        for j in range(n):
            if i != j:
                prod *= nums[j]
        answer.append(prod)

    return answer
                

# Time complexity O(n^2)
# Space complexity O(1)



----------------------------------------------------------------------
                       BETTER APPROACH
----------------------------------------------------------------------

def productExceptSelf(nums):
    n = len(nums)
    prefix = [1] * n
    suffix = [1] * n
    answer = [1] * n

    # prefix
    for i in range(1, n):
        prefix[i] = prefix[i - 1] * nums[i - 1]

    # suffix
    for i in range(n - 2, -1, -1):
        suffix[i] = suffix[i + 1] * nums[i + 1]

    # result
    for i in range(n):
        answer[i] = prefix[i] * suffix[i]

    return answer


# Time complexity O(n)
# Space complexity O(n)



----------------------------------------------------------------------
                       OPTIMAL APPROACH
----------------------------------------------------------------------

def productExceptSelf(nums):
    n = len(nums)
    answer = [1] * n

    # Step 1: prefix products
    prefix = 1
    for i in range(n):
        answer[i] = prefix
        prefix *= nums[i]

    # Step 2: suffix products
    suffix = 1
    for i in range(n - 1, -1, -1):
        answer[i] *= suffix
        suffix *= nums[i]

    return answer


# Time complexity O(n)
# Space complexity O(1)





