class Solution {
public:
    int minOperations(vector<string>& logs) {
        int d = 0;
        
        for (auto& s : logs) 
            if (s=="./")
                continue;
            else if (s=="../")
                d = max(0, d-1);
            else
                ++d;
        return d;
    }
};