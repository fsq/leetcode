class Solution {
public:
    int minDeletion(vector<int>& a) {
        int ans = 0;
        for (int i=0,j=1; i<a.size(); ) {
            while (j<a.size() && a[i]==a[j]) ++j;
            if (j==a.size()) {
                ans += j - i;
                break;
            }
            ans += j - i - 1;
            i = j + 1; 
            j = i + 1;
        }
        return ans;
    }
};