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
    
    // https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
    // O(h) space O(n) time solution
    // using stacks to traverse the tree
    
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        stack<TreeNode*> pre, post;
        
        for (auto p=root; p; p=p->left)  pre.push(p);
        for (auto p=root; p; p=p->right) post.push(p);
        
        while (true) {
            int x = pre.top()->val, y = post.top()->val;
            if (x==y) break;
            if (x+y==k) return true;
            if (x+y<k) {
                if (pre.top()->right) {
                    auto p = pre.top()->right;
                    pre.pop();
                    for (; p; p=p->left) pre.push(p);
                } else 
                    pre.pop();
            } else {
                if (post.top()->left) {
                    auto p = post.top()->left;
                    post.pop();
                    for (; p; p=p->right) post.push(p);
                } else 
                    post.pop();
            }
        }
        
        return false;
    }
};