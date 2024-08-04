//
// Created by 朱俊驰 on 8/3/24.
//
#include <iostream>
#include <stack>
#include <queue>
#include "../treenode.h"
using namespace std;


TreeNode* invertTree(TreeNode* root) {
    stack<TreeNode*> my_stack;
    if(root != nullptr){
        my_stack.push(root);
    }

    while(!my_stack.empty()){
        TreeNode* node = my_stack.top();
        my_stack.pop();

        swap(node->left,node->right);

        if(node->left!=nullptr){
            my_stack.push(node->left);
        }
        if(node->right!=nullptr){
            my_stack.push(node->right);
        }
    }

    return root;
}

//bool isSymmetric(TreeNode* root) {
//
//}


void traversal(TreeNode* root, vector<int> store){
    if(root== nullptr){
        return;
    }
    traversal(root->left, store);
    traversal(root->right, store);
    store.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> store;
    traversal(root, store);
    return store;
}

// preorder mid left right
// inorder  left mid right
// postorder left right mid
vector<int> postorderTraversal_version_two(TreeNode* root) {
    stack<TreeNode*> my_stack;
    vector<int> my_store;
    if(root == nullptr){
        return my_store;
    }
    my_stack.push(root);

    while(!my_stack.empty()){
        TreeNode* node = my_stack.top();
        my_stack.pop();

        my_store.push_back(node->val);

        if(node->left != nullptr){
            my_stack.push(node->left);
        }
        if(node->right != nullptr){
            my_stack.push(node->right);
        }

    }
    reverse(my_store.begin(), my_store.end());
    return my_store;
}


// recursive version
bool compare(TreeNode* left, TreeNode* right){
    if(left == nullptr and right != nullptr){
        return false;
    }
    else if(left != nullptr and right == nullptr){
        return false;
    }
    else if(left == nullptr and right == nullptr){
        return true;
    }
    else if(left->val != right->val){
        return false;
    }

    bool outside_branch = compare(left->left, right->right);
    bool inside_branch = compare(left->right, right->left);
    if(!outside_branch || !inside_branch){
        return false;
    }
    return true;
}

bool isSymmetric_recursive_version(TreeNode* root) {
    if(root== nullptr){
        return false;
    }
    return compare(root->left, root->right);
}

// queue version
bool isSymmetric_queue_version(TreeNode* root) {
    if(root== nullptr){
        return false;
    }
    queue<TreeNode *>my_queue;
    my_queue.push(root->left);
    my_queue.push(root->right);

    while(!my_queue.empty()){
        TreeNode* left_node = my_queue.front();
        my_queue.pop();
        TreeNode* right_node = my_queue.front();
        my_queue.pop();

        if(left_node== nullptr && right_node!= nullptr){
            return false;
        }
        else if(left_node!= nullptr && right_node== nullptr){
            return false;
        }
        else if(left_node == nullptr && right_node == nullptr){
            continue;
        }
        else if(left_node->val != right_node->val ){
            return false;
        }
        my_queue.push(left_node->left);
        my_queue.push(right_node->right);
        my_queue.push(left_node->right);
        my_queue.push(right_node->left);
    }
    return true;
}


// stack version
bool isSymmetric_stack_version(TreeNode* root) {
    if(root== nullptr){
        return false;
    }
    stack<TreeNode *>my_stack;
    my_stack.push(root->left);
    my_stack.push(root->right);

    while(!my_stack.empty()){
        TreeNode* left_node = my_stack.top();
        my_stack.pop();
        TreeNode* right_node = my_stack.top();
        my_stack.pop();

        if(left_node== nullptr && right_node!= nullptr){
            return false;
        }
        else if(left_node!= nullptr && right_node== nullptr){
            return false;
        }
        else if(left_node == nullptr && right_node == nullptr){
            continue;
        }
        else if(left_node->val != right_node->val ){
            return false;
        }
        my_stack.push(left_node->left);
        my_stack.push(right_node->right);
        my_stack.push(left_node->right);
        my_stack.push(right_node->left);
    }
    return true;
}

int maxDepth(TreeNode* root) {
    if(root== nullptr){return 0;}
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    int answer=max(left, right)+1;
    return answer;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, nullptr, new TreeNode(3));
    root->right = new TreeNode(2, nullptr, new TreeNode(3));

    // Test the maxDepth function
    int depth = maxDepth(root);
    cout << "The maximum depth of the tree is: " << depth << endl;

    // Clean up memory
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}