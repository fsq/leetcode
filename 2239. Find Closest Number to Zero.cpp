class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end(), [](int x, int y) {
            return abs(x)<abs(y) || abs(x)==abs(y) && x > y; 
        });
    }
};