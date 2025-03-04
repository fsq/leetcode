class Solution {
public:
    vector<int> maxUpgrades(vector<int>& count, vector<int>& upgrade, vector<int>& sell, vector<int>& money) {
        // money + sell * (count - x) >= upgrade * x
        // x <=  (money+sell*count) / (upgrade+sell)
        vector<int> ans;
        for (int i=0; i<count.size(); ++i)
            ans.push_back(min<long long>(count[i],
                            (money[i]+(long long)sell[i]*count[i]) / (upgrade[i]+sell[i])));
        return ans;
    }
};