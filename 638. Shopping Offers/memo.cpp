// https://leetcode.com/problems/shopping-offers/description/
// DFS with memo

void operator += (vector<int>& a, const vector<int>& b) {
    for (int i=0; i<a.size(); ++i)
        a[i] += b[i];
}
    
void operator -= (vector<int>& a, const vector<int>& b) {
    for (int i=0; i<a.size(); ++i)
        a[i] -= b[i];
}

int operator * (const vector<int>& a, const vector<int>& b) {
    int ret = 0;
    for (int i=0; i<a.size(); ++i)
        ret += a[i] * b[i];
    return ret;
}

class Solution {
public:
    
    unordered_map<int, int> memo;
    
    bool can_buy(const vector<int>& needs, const vector<int>& offer) {
        for (int i=0; i<needs.size(); ++i)
            if (needs[i]<offer[i])
                return false;
        return true;
    }
    
    // encode vector to an base 7 integer, since each entry won't exceed 6
    int encode(const vector<int>& needs) {
        int ret = 0;
        for (auto x : needs)
            ret = ret*7 + x;
        return ret;
    }
    
    int dp(vector<int>& needs, const vector<int>& prices, const vector<vector<int>>& special) {
        int key = encode(needs);
        if (memo.find(key)!=memo.end()) return memo[key];
        
        // pruning: buy all the items separately first
        int& ans = memo[key];
        ans = needs * prices;
        
        for (auto & offer : special)
            if (can_buy(needs, offer) && offer.back()<ans) {
                needs -= offer;
                ans = min(ans, offer.back() + dp(needs, prices, special));
                needs += offer;
            }
        
        return ans;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dp(needs, price, special);
    }
};