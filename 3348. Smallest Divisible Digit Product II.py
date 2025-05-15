class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        tt = t
        for div in [2, 3, 5, 7]:
            while tt % div == 0:
                tt /= div
        if tt > 1:
            return "-1"
        
        remain_div = [0] * (len(num) + 1)
        remain_div[0] = t
        for i in range(0, len(num)):
            if num[i] == '0':
                break
            remain_div[i+1] = remain_div[i] // gcd(remain_div[i], int(num[i]))
        if remain_div[-1] == 1:
            return num

        def find_suffix(div):
            ans = []
            for d in range(9, 1, -1):
                while div > 1 and div % d == 0:
                    ans.append(str(d))
                    div /= d
            return ''.join(reversed(ans))

        first_zero = num.find('0') % len(num)
        for i in reversed(range(0, first_zero+1)):
            suffix_len = len(num) - i - 1
            for dig in range(int(num[i])+1, 10):
                remain_divisor = remain_div[i] // gcd(remain_div[i], dig)
                suffix = find_suffix(remain_divisor)
                if len(suffix) <= suffix_len:
                    return num[:i] + str(dig) + "1"*(suffix_len-len(suffix)) + suffix
        
        min_ans = find_suffix(t)
        return "1" * max(0, len(num)+1-len(min_ans)) + min_ans