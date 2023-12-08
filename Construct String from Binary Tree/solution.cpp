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
    void preorder(TreeNode* root, string &ans){
        if(root == NULL){
          ans += "()";
          return;
        }
        ans += '(';
        ans += (to_string(root->val));
        preorder(root->left, ans);
        preorder(root->right, ans);
        ans += ')';
        return;
    }
    string tree2str(TreeNode* root) {
        string ans = "";
        preorder(root, ans);
        char pre;
        for(int i=ans.size()-1; i>=1; i--){
          if(pre == ')' && ans[i-1]=='(' && ans[i]==')'){
            ans = ans.erase(i-1, 2);
          }
          else pre = ans[i];
        }
        ans = ans.substr(1, ans.size()-2);
        return ans;    
    }
};