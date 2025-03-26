class Solution:
    def phonePrefix(self, a: List[str]) -> bool:
        for i in range(len(a)):
            for j in range(len(a)):
                if i != j and a[i].startswith(a[j]):
                    return False
        return True