class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int x=low; x<=high; ++x) {
            auto s = to_string(x);
            if (s.size() & 1) continue;
            if (accumulate(s.begin(), s.begin()+s.size()/2, 0) == 
                accumulate(s.begin()+s.size()/2, s.end(), 0))
                ++ans;
        }
        return ans;
    }
};