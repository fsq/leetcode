class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        bool sign = (num < 0);
        num = abs(num);
        string ans = to_string(num);
        sort(ans.begin(), ans.end());
        if (sign) {
            reverse(ans.begin(), ans.end());
            return - stoll(ans);
        } else {
            int i = ans.find_last_of('0');
            swap(ans[i+1], ans[0]);
            return stoll(ans);
        }
    }
};