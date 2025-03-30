class Solution:
    def maxArea(self, height: int, pos: List[int], dir: str) -> int:
        q = []     # heap queue
        u = d = 0  # track number of up/down pistons
        for i in range(len(pos)):
            # for each piston store [next_flip_timestamp, current_direction]
            if dir[i] == 'D':
                q.append([pos[i], 'D'])
                d += 1
            else:
                q.append([height-pos[i], 'U'])
                u += 1
        ans = cur_h = sum(pos)
        heapify(q)
        time = 0
        # simulate piston movements, up to 2*height seconds
        # after which movement repeats itself
        # e.g. [0] 'U'
        while time <= 2 * height:
            next_flip_time, dr = heappop(q)
            
            # seconds to the next flip
            gap = next_flip_time - time
            time = next_flip_time

            # update height by u/d
            cur_h += u*gap - d*gap
            ans = max(ans, cur_h)

            if dr == 'U':
                dr = 'D'
                u -= 1
                d += 1
            else:
                dr = 'U'
                u += 1
                d -= 1
            heappush(q, [next_flip_time + height, dr])
        return ans
