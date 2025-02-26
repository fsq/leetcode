class HitCounter:

    def __init__(self):
        self.q = deque()
        self.tot = 0

    def hit(self, timestamp: int) -> None:
        if len(self.q) and self.q[-1][0]==timestamp:
            self.q[-1][1] += 1
        else:
            self.q.append([timestamp, 1])
        self.tot += 1

    def getHits(self, timestamp: int) -> int:
        while len(self.q) and self.q[0][0]<=timestamp-300:
            self.tot -= self.q.popleft()[1]
        return self.tot
        


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)