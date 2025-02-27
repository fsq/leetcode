class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        e = defaultdict(list)
        ind = defaultdict(int)
        for x, p in prerequisites:
            e[p].append(x)
            ind[x] += 1
        ans = []
        q = deque([i for i in range(numCourses) if ind[i]==0])
        while len(q) > 0:
            x = q.popleft()
            ans.append(x)
            for y in e[x]:
                ind[y] -= 1
                if ind[y] == 0:
                    q.append(y)
        return ans if len(ans)==numCourses else []

