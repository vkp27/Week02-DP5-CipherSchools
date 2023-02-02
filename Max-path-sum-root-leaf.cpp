#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int fun(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int l = fun(root->left);
    int r = fun(root->right);
    return max(l,r)+root->val;
}
int maxPathSum(TreeNode* root)
{
    return fun(root);
}

int main(){
    return 0;
}