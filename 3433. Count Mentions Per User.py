class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        status = {x:True for x in range(numberOfUsers)}
        mention = [0] * numberOfUsers
        login = []
        events.sort(key=lambda e: (int(e[1]), 0 if e[0]=='OFFLINE' else 1))
        mention_all = 0
        for event_name, ts, val in events:
            while len(login) and login[0][0]<=int(ts):
                status[login[0][1]] = True
                heappop(login)
            if event_name == "MESSAGE":
                if val == "ALL":
                    mention_all += 1
                elif val == "HERE":
                    for u, st in status.items():
                        if st:
                            mention[u] += 1
                else:
                    for u in val.split(' '):
                        mention[int(u[2:])] += 1
            else:
                status[int(val)] = False
                heappush(login, (int(ts)+60, int(val)))
        
        return [x+mention_all for x in mention]
