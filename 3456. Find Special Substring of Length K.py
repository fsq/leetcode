class Solution:
    def hasSpecialSubstring(self, s: str, k: int) -> bool:
        return any([len(list(it))==k for _, it in groupby(s)])
