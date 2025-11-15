class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.task = dict()
        self.q = []
        for user_id, task_id, priority in tasks:
            self.task[task_id] = [priority, user_id]
            heappush(self.q, (-priority, -task_id))

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.task[taskId] = [priority, userId]
        heappush(self.q, (-priority, -taskId))

    def edit(self, taskId: int, newPriority: int) -> None:
        self.task[taskId][0] = newPriority
        heappush(self.q, (-newPriority, -taskId))

    def rmv(self, taskId: int) -> None:
        del self.task[taskId]

    def execTop(self) -> int:
        while len(self.q):
            p, tid = heappop(self.q)
            p = -p
            tid = -tid
            if tid in self.task and self.task[tid][0] == p:
                ret = self.task[tid][1]
                self.rmv(tid)
                return ret
        return -1
                


# Your TaskManager object will be instantiated and called as such:
# obj = TaskManager(tasks)
# obj.add(userId,taskId,priority)
# obj.edit(taskId,newPriority)
# obj.rmv(taskId)
# param_4 = obj.execTop()
