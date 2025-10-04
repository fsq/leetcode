class Solution:
    def subsequencesWithMiddleMode(self, a: List[int]) -> int:
        n = len(a)
        c = defaultdict(int)
        tot = Counter(a)
        for i in range(2):
            c[a[i]] += 1
        cr = defaultdict(int)
        crc = 0 # Sum of cr[i]*(cr[i]-1)//2
        for i in reversed(range(3, n)):
            x = a[i]
            crc += cr[x]
            cr[x] += 1
        clc = 0 # Sum of c[i]*(c[i]-1)//2
        for k, v in c.items():
            clc += comb(v, 2)

        ans = 0
        M = int(1e9 + 7)
        for i in range(2, n-2):
            x = a[i]
            nr = n-i-1
            lx = c[x]
            rx = tot[x] - lx - 1
            # 3
            ans3 = lx * (i-lx) * rx * (nr-rx)
            if lx >= 2:
                ans3 += comb(lx, 2) * comb(nr-rx, 2)
            if rx >= 2:
                ans3 += comb(rx, 2) * comb(i-lx, 2)

            ans = (ans + ans3) % M
            # 4
            # left 2
            ans4 = 0
            if lx >= 2:
                ans4 += comb(lx, 2) * rx * (nr-rx)
            # right 2
            if rx >= 2:
                ans4 += comb(rx, 2) * lx * (i-lx)
            ans = (ans + ans4) % M
            # 5
            if lx>=2 and rx>=2:
                ans5 = comb(lx, 2) * comb(rx, 2)
                ans = (ans + ans5) % M
            # 2
            # take x, k from left
            ans_l = 0
            for k in c.keys():
                if k != x:
                    # take x, k from left
                    ans_l += lx * c[k] * \
                    (comb(nr-cr[x]-cr[k], 2) - (crc - comb(cr[x], 2) - comb(cr[k], 2)))
                    ans_l %= M
            # take x, k from right
            ans_r = 0
            for k in cr.keys():
                if k != x:
                    clx = c[x]
                    clk = c[k]
                    ans_r += rx * cr[k] * \
                    (comb(i-clx-clk, 2) - (clc - comb(clx, 2) - comb(clk, 2)))

            ans = (ans + ans_l + ans_r) % M

            # update clc
            clc += c[x]
            c[x] += 1
            clc %= M
            # update crc
            x = a[i+1]
            cr[x] -= 1
            crc -= cr[x]
            crc %= M
        
        return ans
