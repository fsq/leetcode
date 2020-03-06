/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root || root->val!=head->val) return false;
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head || !root) return false;
        if (dfs(head->next, root->left) || dfs(head->next, root->right))
            return true;
        
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};