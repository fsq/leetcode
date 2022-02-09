class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        for (int i=0; i<s.size(); ++i) 
            if (s[i] == 'X') {
                ++ans;
                for (int j=i; j<i+3 && j<s.size(); ++j) s[j] = 'O';
            }
        return ans;
    }
};