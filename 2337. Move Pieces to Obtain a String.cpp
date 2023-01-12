class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size(), i=0, j=0;
        while (true) {
            while (i<n && start[i]=='_') ++i;
            while (j<n && target[j]=='_') ++j;
            if (i==n && j==n) return true;
            if (i==n || j==n) return false;
            if (start[i] != target[j]) return false;
            if (start[i]=='L' && i<j || start[i]=='R' && i>j) return false;
            ++i, ++j;
        }
        return true;
    }
};