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
    vector<int> getAllElements(TreeNode* a, TreeNode* b) {
        stack<TreeNode*> sa, sb;
        vector<int> ans;
        if (a) sa.push(a);
        if (b) sb.push(b);
        while (!sa.empty() && sa.top()->left) sa.push(sa.top()->left);
        while (!sb.empty() && sb.top()->left) sb.push(sb.top()->left);
        while (!sa.empty() || !sb.empty()) {
            auto& stk = sa.empty() || (!sb.empty() && sa.top()->val > sb.top()->val) ? sb : sa;
            ans.push_back(stk.top()->val);
            auto t = stk.top();
            stk.pop();
            if (t->right) {
                stk.push(t->right);
                while (stk.top()->left) stk.push(stk.top()->left);
            }
        }
        return ans;
    }
};