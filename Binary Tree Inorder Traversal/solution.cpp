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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> store;
        vector<int> res;
        TreeNode* cur = root;
        while(cur != NULL || !store.empty()){
            while(cur != NULL) {
                store.push(cur);
                cur = cur->left;
            }
            cur = store.top();
            store.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};