class Solution {
public:
    int minOperations(int n) {
        vector<int> b;
        while (n) {
            b.push_back(n % 2);
            n /= 2;
        }
        int ans = 0;
        for (int i=0; i<b.size(); ) {
            if (b[i]==1) {
                if (i+1<b.size() && b[i+1]==1) {
                    while (i+1<b.size() && b[i+1]==1) ++i;
                    ++ans;
                    if (i+1<b.size()) 
                        b[i+1] = 1;
                    else 
                        ++ans;
                } else {
                    ++ans;
                }
            } 
            ++i;
        }
        return ans;
    }
};