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

/***************************Preorder********************************/
vector<int> preorderTraversal(TreeNode* root) {
        
    stack <TreeNode *> st;
    vector<int> res;
    if(!root){
        return res;
    }
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        res.push_back(root->val);
        if(root->right != NULL){
            st.push(root->right);
        }
        if(root->left != NULL){
            st.push(root->left);
        }
    }
    return res;
}


/********************************Inorder*************************************/
vector<int> inorderTraversal(TreeNode* root) {
    TreeNode *curr = root;
    stack <TreeNode *> st;
    vector<int> res;
    while(true){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            if(st.empty()){
                break;
            }
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
    }
    return res;
}


/*************************************Postorder************************************/
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root){
        return res;
    }
    stack<TreeNode *> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != NULL){
            st1.push(root->left);
        }
        if(root->right != NULL){
            st1.push(root->right);
        }
    }
    while(!st2.empty()){
        res.push_back(st2.top()->val);
        st2.pop();
    }
    return res;
}

int main(){
    return 0;
}