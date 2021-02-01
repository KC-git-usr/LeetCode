def twoSum(nums, target):
    result = [0, 0]
    flag = False
    for i in range(0, len(nums)):
        for j in range(i, len(nums)):
            if nums[i]+nums[j] == target:
                result[0], result[1] = i, j
                flag = True
                break
    if flag == True:
        return result
    else:
        print("No match found")


print(twoSum([3,2,4], 6))