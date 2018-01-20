class Solution {
public:
    
    // https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
    // O(n) greedy
    // for an integer x, appending it to the sequence ends with x-1 is more likely to success
    
    
    bool isPossible(vector<int>& nums) {
        vector<pair<int,int>> cnt;
        for (auto x : nums)
            if (cnt.empty() || x!=cnt.back().first)
                cnt.push_back({x, 1});
            else
                ++cnt.back().second;
        
        unordered_map<int, int> seq;
        for (int k=0; k<cnt.size(); ++k) {
            auto &pr = cnt[k];
            
            if (pr.second==0) continue;
            
            if (seq[pr.first-1]>pr.second) {
                seq[pr.first-1] -= pr.second;
                seq[pr.first]   += pr.second;
                pr.second        = 0;
            } else if (seq[pr.first-1]<=pr.second && seq[pr.first-1]>0) {
                pr.second       -= seq[pr.first-1];
                seq[pr.first]   += seq[pr.first-1];
                seq[pr.first-1] = 0;
            }

            if (pr.second>0)
                if (k+2<cnt.size() && 
                       cnt[k+1].first==pr.first+1 && cnt[k+1].second>=pr.second &&
                       cnt[k+2].first==pr.first+2 && cnt[k+2].second>=pr.second) {
                    seq[pr.first+2] += pr.second;
                    cnt[k+1].second -= pr.second;
                    cnt[k+2].second -= pr.second;
                } else
                 return false;
        }
        return true;
    }
};