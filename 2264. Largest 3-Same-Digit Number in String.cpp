class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        for (int i=0; i+3<=num.size();)
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                ans = max(ans, num.substr(i, 3));
                i += 3;
            } else 
                ++i;
        return ans;
    }
};