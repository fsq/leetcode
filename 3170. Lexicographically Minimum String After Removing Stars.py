class Solution:
    def clearStars(self, ss: str) -> str:
        s = list(ss)
        pos = defaultdict(list)
        for i, c in enumerate(s):
            if c == '*':
                for key in string.ascii_lowercase:
                    if pos[key]:
                        s[pos[key][-1]] = ''
                        pos[key].pop()
                        break
                s[i] = ''
            else:
                pos[c].append(i)
        return ''.join(s)