class RandomizedSet:

    def __init__(self):
        self.pos = dict()
        self.a = []

    def insert(self, val: int) -> bool:
        if val in self.pos:
            return False
        self.a.append(val)
        self.pos[val] = len(self.a) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.pos:
            return False
        i = self.pos[val]
        self.a[i] = self.a[-1]
        self.pos[self.a[-1]] = i
        self.a.pop()
        del self.pos[val]
        return True

    def getRandom(self) -> int:
        i = randint(0, len(self.a)-1)
        return self.a[i]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()