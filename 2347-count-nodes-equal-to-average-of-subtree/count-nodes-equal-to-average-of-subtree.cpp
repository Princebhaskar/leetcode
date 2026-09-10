/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, int& cnt , int &sum) {
        if (root == NULL)return;
        inorder(root->left, cnt,sum);
        cnt++;
        sum += root->val;
        inorder(root->right, cnt,sum);
    }
    int  solve(TreeNode* root ) {
        if (!root)return 0;
        int cnt = 0;
        int sum =0;
        inorder(root, cnt , sum);
        int ans =0;
        if(sum/cnt == root->val)ans +=1;
        ans += solve(root->left);
        ans += solve(root->right);
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        return solve(root);
     }
};