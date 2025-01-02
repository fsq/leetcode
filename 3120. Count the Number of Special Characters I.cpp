class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        for (int i=0; i<26; ++i)
            if (count(s.begin(),s.end(),i+'a') && count(s.begin(),s.end(),i+'A'))
                ++ans;
        return ans;
    }
};