class Solution {
public:
    
    // https://leetcode.com/problems/k-empty-slots/description/
    // bucket O(n) time O(n/k) space
    // divide into size (k+1) buckets
    // insert and check the max/min elements in the left/right bucket
    
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        ++k;
        vector<pair<int,int>> slots(n/k+1, {INT_MAX, INT_MIN});
        
        for (int i=0; i<n; ++i) {
            int x = flowers[i]-1;
            int ind = x / k;

            if (slots[ind].first>x && ind>0 && slots[ind-1].second==x-k || 
                slots[ind].second<x && ind+1<slots.size() && slots[ind+1].first==x+k)
                return i+1;
            
            slots[ind].first = min(slots[ind].first, x);
            slots[ind].second = max(slots[ind].second, x);
        }
        
        return -1;
    }
};