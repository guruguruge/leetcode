from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        left_idx = 0
        right_idx = len(height) - 1
        left_max = 0
        right_max = 0
        result = 0
        while left_idx <= right_idx:
            water = 0
            if height[left_idx] <= height[right_idx]:
                if left_max <= height[left_idx]:
                    left_max = height[left_idx]
                else:
                    water = left_max - height[left_idx]
                left_idx += 1
            else:
                if right_max <= height[right_idx]:
                    right_max = height[right_idx]
                else:
                    water = right_max - height[right_idx]
                right_idx -= 1
            
            if(water > 0):
                result += water

        return result


# print(Solution([0,1,0,2,1,0,1,3,2,1,2,1]))
