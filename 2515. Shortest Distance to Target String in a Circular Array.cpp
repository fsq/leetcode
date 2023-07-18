class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        for (int i=0; i<words.size(); ++i)
            if (words[i] == target)
                ans = min(ans, min(
                                abs(i - startIndex), 
                                min(abs(startIndex+(int)words.size()-i),
                                    abs(i+(int)words.size()-startIndex)))
                );
        return ans==INT_MAX ? -1 : ans;
    }
};