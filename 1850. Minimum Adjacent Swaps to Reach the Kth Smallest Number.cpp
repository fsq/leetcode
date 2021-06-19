class Solution {
public:
    
    int getMinSwaps(string num, int k) {
        string tar = num;
        for (int i=0; i<k; ++i) next_permutation(tar.begin(), tar.end());
        
        int ans = 0;
        for (int i=0, j=0; i<tar.size(); ++i)
            if (tar[i] == num[j]) {
                ++j;
            } else {
                int k=j+1;
                while (num[k] != tar[i]) ++k;
                num.erase(num.begin() + k);
                ans += k - j;
            }
        return ans;
    }
};