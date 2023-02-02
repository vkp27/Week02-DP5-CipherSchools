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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root == NULL){
        return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        vector<int> temp;
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode *tp = q.front();
            q.pop();
            if(tp->left){
                q.push(tp->left);
            }
            if(tp->right){
                q.push(tp->right);
            }
            temp.push_back(tp->val);
        }
        res.push_back(temp);
    }
    return res;
}

int main(){
    return 0;
}