//
// Created by 朱俊驰 on 8/2/24.
//
#include <iostream>
#include <stack>
#include <queue>
#include "../treenode.h"
using namespace std;



void traversal_1(TreeNode* root, vector<int> &store){
    if(root == nullptr){
        return;
    }
    store.push_back(root->val);
    traversal_1(root->left, store);
    traversal_1(root->right, store);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> store;
    traversal_1(root, store);
    return store;
}

void traversal_2(TreeNode* root, vector<int> &store){
    if(root == nullptr){
        return;
    }
    traversal_2(root->left, store);
    traversal_2(root->right, store);
    store.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> store;
    traversal_2(root, store);
    return store;
}

void traversal_3(TreeNode* root, vector<int> &store){
    if(root == nullptr){
        return;
    }
    traversal_3(root->left, store);
    store.push_back(root->val);
    traversal_3(root->right, store);

}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> store;
    traversal_3(root, store);
    return store;
}

vector<int> preorderTraversal_version_two(TreeNode* root) {
    vector<int> store;
    stack<TreeNode*> traversal;
    if(root == nullptr){
        return store;
    }
    traversal.push(root);

    while (!traversal.empty()){
        TreeNode* temp = traversal.top();
        traversal.pop();

        store.push_back(temp->val);
        if(temp->right != nullptr){
            traversal.push(temp->right);
        }
        if(temp->left != nullptr){
            traversal.push(temp->left);
        }
    }

    return store;
}

vector<int> postorderTraversal_version_two(TreeNode* root) {
    vector<int> store;
    stack<TreeNode*> traversal;
    if(root == nullptr){
        return store;
    }
    traversal.push(root);

    while (!traversal.empty()){
        TreeNode* temp = traversal.top();
        traversal.pop();

        store.push_back(temp->val);

        if(temp->left != nullptr){
            traversal.push(temp->left);
        }
        if(temp->right != nullptr){
            traversal.push(temp->right);
        }

    }
    reverse(store.begin(), store.end());

    return store;
}

vector<int> inorderTraversal_version_two(TreeNode* root) {
    stack<TreeNode*> traversal;
     vector<int> store;
     TreeNode* cur = root;
     while(cur!= nullptr or !traversal.empty()){
         if(cur!= nullptr){
             traversal.push(cur);
             cur = cur->left;
         } else{
             cur = traversal.top();
             store.push_back(cur->val);
             traversal.pop();
             cur = cur->right;
         }
     }
    return store;


}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> store;
    queue<TreeNode*> traversal;
    if(root!= nullptr){
        traversal.push(root);
    }

    while(!traversal.empty()){
        int size = traversal.size();
        vector<int> temp;
        for(int i=0;i<size;++i){
            TreeNode* node = traversal.front();
            traversal.pop();
            temp.push_back(node->val);

            if(node->left != nullptr){
                traversal.push(node->left);
            }
            if(node->right != nullptr){
                traversal.push(node->right);
            }
        }
        store.push_back(temp);
    }

    return store;
}


int main(){
    TreeNode* root1 = nullptr;
    vector<int> result1 = preorderTraversal(root1);
    cout << "Test Case 1: ";
    for (int val : result1) cout << val << " ";
    cout << endl;

    // Test Case 2
    TreeNode* root2 = new TreeNode(1);
    vector<int> result2 = preorderTraversal(root2);
    cout << "Test Case 2: ";
    for (int val : result2) cout << val << " ";
    cout << endl;

    // Test Case 3
    TreeNode* root3 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)), nullptr);
    vector<int> result3 = inorderTraversal(root3);
    cout << "Test Case 3: ";
    for (int val : result3) cout << val << " ";
    cout << endl;

    // Test Case 4
    TreeNode* root4 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    vector<int> result4 = preorderTraversal(root4);
    cout << "Test Case 4: ";
    for (int val : result4) cout << val << " ";
    cout << endl;

    // Test Case 5
    TreeNode* root5 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    vector<int> result5 = preorderTraversal(root5);
    cout << "Test Case 5: ";
    for (int val : result5) cout << val << " ";
    cout << endl;

    // Test Case 6
    TreeNode* root6 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    vector<int> result6 = inorderTraversal_version_two(root6);
    cout << "Test Case 6: ";
    for (int val : result6) cout << val << " ";
    cout << endl;
    return 0;
}