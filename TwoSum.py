'''
Problem:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
'''


def b_twoSum(nums, target):
    '''
    brute force method
    '''
    for i in range(0, len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i]+nums[j] == target:
                return ([i, j])


def h_twoSum(nums, target):
    '''
    single pass hash map
    '''
    h = {}
    for i, num in enumerate(nums):
        n = target - num
        if n not in h:
            h[num] = i
        else:
            return [h[n], i]

print(h_twoSum([1,2,4], 3))