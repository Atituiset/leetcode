from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = dict()
        for idx, e in enumerate(nums):
            if target - e in hash:
                return [idx, hash[target - e]]
            hash[e] = idx
        
if __name__ == '__main__':
    print(Solution().twoSum([2, 7, 11, 15], 9)) # [0, 1]