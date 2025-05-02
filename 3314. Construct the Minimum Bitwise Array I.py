class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for x in nums:
            if not (x & 1):
                ans.append(-1)
            else:
                s = format(x, 'b')
                i = s.rfind('0') + 1
                t = list(s)
                t[i] = '0'
                ans.append(int(''.join(t), 2))
        return ans
                
