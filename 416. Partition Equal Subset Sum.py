class Solution:
    def canPartition(self, a: List[int]) -> bool:
        st = {0}
        for x in a:
          st.update({x+v for v in st})
        return sum(a)/2. in st