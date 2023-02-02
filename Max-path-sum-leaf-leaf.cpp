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

int pathFinder(TreeNode *root, int &mx_sum){
    if(!root){
        return 0;
    }

    int l_sum = max(0, pathFinder(root->left, mx_sum));
    int r_sum = max(0, pathFinder(root->right, mx_sum));

    mx_sum = max(mx_sum, (l_sum + r_sum + root->val));

    return (root->val + max(l_sum, r_sum));
}
int maxPathSum(TreeNode* root) {
    int mx_sum = INT_MIN;
    pathFinder(root,mx_sum);
    return mx_sum;
}

int main(){
    return 0;
}