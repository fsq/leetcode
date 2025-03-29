class Solution:
    def minDamage(self, power: int, damage: List[int], health: List[int]) -> int:
        a = sorted(range(len(damage)), key = lambda i: ceil(health[i]/power)/damage[i])
        ans = 0
        t = 0
        for i in a:
            tt = ceil(health[i] / power)
            t += tt
            ans += t * damage[i]
        return ans
