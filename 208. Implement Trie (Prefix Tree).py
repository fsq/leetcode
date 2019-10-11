
class Node:
    def __init__(self):
        self.c = 0
        self.s = collections.defaultdict(Node)

class Trie:
    def __init__(self):
        self.root = Node()
        

    def insert(self, word: str) -> None:
        now = self.root
        for c in word:
            now = now.s[c]
        now.c += 1

    def search(self, word: str) -> bool:
        now = self.root
        for c in word:
            now = now.s.get(c)
            if not now:
                return False
        return now.c > 0
        

    def startsWith(self, prefix: str) -> bool:
        now = self.root
        for c in prefix:
            now = now.s.get(c)
            if not now:
                return False
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)