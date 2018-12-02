class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& a) {
        sort(a.begin(), a.end(), greater<int>());
        list<int> ans;
        for (auto x : a) {
            if (ans.size()) {
                ans.push_front(ans.back());
                ans.pop_back();
            }
            ans.push_front(x);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};