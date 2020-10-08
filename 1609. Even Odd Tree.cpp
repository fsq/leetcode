/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> last;
    
    bool isEvenOddTree(TreeNode* root, int d=0) {
        if (!root) return true;
        int x = root->val;
        if (!  (((d&1) && !(x&1)) || (!(d&1) && (x&1))))
            return false;
        if (last.size()==d) {
            last.push_back(root->val);
        } else {
            if (! ( ((d&1) && x<last[d]) || (!(d&1) && x>last[d]) ))
                return false;
            last[d] = x;
        }
        return isEvenOddTree(root->left, d+1) && isEvenOddTree(root->right, d+1);
    }
};