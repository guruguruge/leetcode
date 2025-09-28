from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        prev_nums = {}
        for num in nums:
            if num in prev_nums:
                return True
            else:
                prev_nums[num] = True

        return False
