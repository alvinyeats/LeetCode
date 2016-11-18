class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = []
        for idx, num in enumerate(nums):
            if (target-num) in nums and nums.index(target-num)!=idx:
                result.append(idx)
                result.append(nums.index(target-num))
                break
        return result