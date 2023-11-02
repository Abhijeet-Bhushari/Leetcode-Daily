class Solution {
public:
    int cnt = 0;
public:
    pair<int, int> solve(TreeNode* &root){
        if(root == NULL){
            pair<int, int> p = {0, 0};
            return p;
        }
        pair<int, int> left = solve(root->left), right = solve(root->right);
        pair<int, int> p = {root->val + left.first + right.first, 1 + left.second + right.second};
        int avg = p.first/p.second;
        if(avg == root->val){
            cout<<root->val<<endl;
            cnt++;
        }
        return p;
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return cnt;
    }
};