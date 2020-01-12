class Solution {
public:
    vector<int> decompressRLElist(vector<int>& a) {
        vector<int> ans;
        for (int i=0; i<a.size(); i+=2) 
            ans.insert(ans.end(), a[i], a[i+1]);
        return ans;
    }
};