from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum = nums[0]
        cursum = 0
        for num in nums:
            cursum = max(num, cursum + num)
            maxsum = max(maxsum, cursum)

        return maxsum
