class Solution {
public: 
    int findGCD(vector<int>& a) {
        return __gcd(*max_element(a.begin(), a.end()),
                     *min_element(a.begin(), a.end()));
    }
};