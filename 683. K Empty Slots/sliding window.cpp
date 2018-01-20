class Solution {
public:
    
    // https://leetcode.com/problems/k-empty-slots/discuss/
    // O(n) sliding window solution
    // for each size k window, min element > max(days[l-1], days[r+1])
    
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        vector<int> days(n, 0);
        for (int i=0; i<n; ++i)
            days[flowers[i]-1] = i+1;
        
        // Q: min element in size k window
        deque<int> q;
        
        int ans = INT_MAX;

        for (int end=0; end<n; ++end) {
            while (!q.empty() && days[end]<q.back())
                q.pop_back();
            q.push_back(days[end]);
            
            if (end-k>=0 && q.front()==days[end-k])
                q.pop_front();
            
            if (end-k>=0 && end+1<n && q.front()>max(days[end-k], days[end+1]))
                ans = min(ans, max(days[end-k], days[end+1]));
        }
        return ans==INT_MAX ? -1 : ans;
    }
};