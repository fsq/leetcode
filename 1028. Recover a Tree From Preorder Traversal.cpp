/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        vector<pair<int, int>> a;
        for (int j=0, i=0; i<s.size(); i = j) {
            for (j=i; j<s.size() && s[j]=='-'; ++j);
            int times = j - i, num = 0;
            for (; j<s.size() && isdigit(s[j]); ++j) 
                num = num*10 + (s[j] - '0');
            a.push_back({times, num});
        }
        
        stack<TreeNode*> stk;
        TreeNode* ans;
        for (auto& pr : a) {
            int dp = pr.first;
            TreeNode* x = new TreeNode(pr.second);
            if (stk.empty()) {
                stk.push(x);
                ans = x;
            } else {
                while (stk.size()-1 >= dp) stk.pop();
                if (stk.top()->left)
                    stk.top()->right = x;
                else
                    stk.top()->left = x;
                stk.push(x);
            }
        }
        return ans;
    }
};