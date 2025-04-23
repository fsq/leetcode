class Solution:
    def reportSpam(self, message: List[str], bannedWords: List[str]) -> bool:
        s = set(bannedWords)
        return len(list(filter(lambda w: w in s, message))) >= 2