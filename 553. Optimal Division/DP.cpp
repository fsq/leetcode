class Solution {
public:
    
    // https://leetcode.com/problems/optimal-division/description/
    // O(n^3) DP with memo
    // consider how last element in [i,j] is grouped
    // max[i,j] = max[i,k]/min[k+1,j]
    // min[i,j] = min[i,k]/max[k+1,j]
    
    vector<vector<int>> ft, gt;
    vector<vector<double>> f, g;
    
    double dp(const vector<int>& a, int i, int j, bool is_get_max) {
        if ( is_get_max && ft[i][j]!=-1) return f[i][j];
        if (!is_get_max && gt[i][j]!=-1) return g[i][j];
        
        if (i==j) {
            f[i][j] = g[i][j] = a[i];
            ft[i][j] = gt[i][j] = i;
        } else if (is_get_max)
            for (int k=i; k+1<=j; ++k) {
                auto div = dp(a, i, k, true)/dp(a, k+1, j, false);
                if (div>f[i][j]) {
                    f[i][j] = div;
                    ft[i][j] = k;
                }
            }
        else 
            for (int k=i; k+1<=j; ++k) {
                auto div = dp(a, i, k, false)/dp(a, k+1, j, true);
                if (div<g[i][j]) {
                    g[i][j] = div;
                    gt[i][j] = k;
                }
            }
        
        return is_get_max ? f[i][j] : g[i][j];
    }
    
    string build(const vector<int>& a, int i, int j, bool is_max) {
        if (i==j)
            return to_string(a[i]);
        if (is_max) {
            auto k = ft[i][j];
            if (k==j-1)
                return build(a, i, k, true) + "/" + build(a, k+1, j, false);
            else 
                return build(a, i, k, true) + "/(" + build(a, k+1, j, false) + ")";
                
        } else {
            auto k = gt[i][j];
            if (k==j-1)
                return build(a, i, k, false) + "/" + build(a, k+1, j, true);
            else
                return build(a, i, k, false) + "/(" + build(a, k+1, j, true) + ")";
                
        }
    }
    
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();

        f =  vector<vector<double>>(n+1, vector<double>(n+1, 0));
        g = vector<vector<double>>(n+1, vector<double>(n+1, INT_MAX));
        ft = gt = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        
        dp(nums, 0, n-1, true);
        
        string ans = build(nums, 0, n-1, true);
        
        return ans;
    }   
};