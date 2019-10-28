class Solution:
    def numUniqueEmails(self, a: List[str]) -> int:
        st = set()
        
        for s in a:
            seg = s.split('@')
            name = seg[0].split('+')[0].replace('.','')
            st.add(name + '@' + seg[1])
        
        return len(st)