class Solution:
    def buttonWithLongestTime(self, events: List[List[int]]) -> int:
        ind, time = events[0]
        for i in range(1, len(events)):
            tn = events[i][1] - events[i-1][1]
            if tn > time or tn==time and events[i][0]<ind:
                ind, time = events[i][0], tn
        return ind
