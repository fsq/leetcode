class Solution {
public:
    string smallestSubsequence(string s, int k, char c, int repetition) {
        string ans;
        int n = s.size(), remain_c = count(s.begin(), s.end(), c), add_c = 0;
        for (int i=0; i<s.size(); ++i) {
            char x = s[i];
            while (!ans.empty() && 
                   ans.back()>x && ans.size()-1+s.size()-i>=k && 
                   (ans.back()!=c || add_c-1+remain_c>=repetition)) {
                        if (ans.back()==c) --add_c;
                        ans.pop_back();
                   }

            if (ans.size() < k) {
                if (x == c) {
                    ++add_c;
                    ans.push_back(x);
                } else if (add_c+k-ans.size()-1 >= repetition) {
                    ans.push_back(x);
                }
            }
            remain_c -= x==c;
        }
        return ans;
    }
};