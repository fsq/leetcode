class Solution:
    def kthSmallestPath(self, dest: List[int], k: int) -> str:
        def calc(h: int, v: int, k: int)->str:
            if h==0 and v==0:
                return ""
            elif h==0:
                return "V" * v
            elif v==0:
                return "H" * h
            else:
                t = math.comb(h+v-1, h-1)
                if k < t:
                    return "H" + calc(h-1, v, k)
                else:
                    return "V" + calc(h, v-1, k-t);
                
        return calc(dest[1], dest[0], k-1)