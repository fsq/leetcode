class Solution:
    def tripletCount(self, a: List[int], b: List[int], c: List[int]) -> int:
        def cnt(a):
            o = len([x for x in a if x.bit_count() & 1])
            return o, len(a)-o

        oa, ea = cnt(a)
        ob, eb = cnt(b)
        oc, ec = cnt(c)
        return ea*(ob*oc + eb*ec) + oa*(ob*ec + eb*oc)