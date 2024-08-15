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
int maxi=0;
int bfs(TreeNode* root,int &n)
{
    if(root==nullptr)return 0;
    int l=bfs(root->left,n);
    int r=bfs(root->right,n);
n=max(n,l+r);
return 1+max(l,r);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int n=0;
bfs(root,n);
return n;
    }
};