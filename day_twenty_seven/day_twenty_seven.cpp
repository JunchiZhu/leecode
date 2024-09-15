//
// Created by 朱俊驰 on 9/15/24.
//

#include "../helper.h"
#include "../treenode.h"
void traversal(TreeNode* root, vector<int> &store){
    if(root== nullptr){
        return;
    }
    traversal(root->left, store);
    store.push_back(root->val);
    traversal(root->right, store);
}

int getMinimumDifference(TreeNode* root) {
    vector<int> store;
    traversal(root, store);
    int min_value = INT_MAX;
    for(int i=1;i<store.size();++i){
        int value = store[i]-store[i-1];
        if(min_value>value){
            min_value=value;
        }
    }
    return min_value;
}

int getMinimumDifferenc_3(TreeNode* root) {
    vector<int> store;
    stack<TreeNode*> my_stack;
    TreeNode* cur = root;

    while(cur!=nullptr || !my_stack.empty()){
        if(cur!=nullptr){
            my_stack.push(cur);
            cur= cur->left;
        }
        else{
            cur= my_stack.top();
            my_stack.pop();
            store.push_back(cur->val);
            cur=cur->right;
        }
    }

    int min_value = INT_MAX;
    for(int i=1;i<store.size();++i){
        int value = store[i]-store[i-1];
        if(min_value>value){
            min_value=value;
        }
    }
    return min_value;
}

int answer = INT_MAX;
TreeNode* previousNode = nullptr;

void traversal_2(TreeNode* root){
    if(root== nullptr){
        return;
    }
    traversal_2(root->left);
    if(previousNode != nullptr){
        answer = min(answer, root->val-previousNode->val);
    }
    previousNode = root;

    traversal_2(root->right);
}
int getMinimumDifference_2(TreeNode* root) {
    traversal_2(root);
    return answer;
}

vector<int> findMode(TreeNode* root) {
    int max_value=INT_MIN;
    TreeNode* cur = root;
    unordered_map<int, int> counter;
    stack<TreeNode*> my_stack;
    while(cur!=nullptr or !my_stack.empty()){
        if(cur!=nullptr){
            my_stack.push(cur);
            cur=cur->left;
        }
        else{
            cur=my_stack.top();
            my_stack.pop();
            counter[cur->val]+=1;
            max_value = max(max_value, counter[cur->val]);
            cur = cur->right;
        }
    }

    vector<int>answer;
    for(auto& pair:counter){
        if(pair.second==max_value){
            answer.push_back(pair.first);
        }
    }
    return answer;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root== nullptr){return nullptr;}
    if(root->val==p->val or root->val == q->val){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);
    if(left== nullptr and right== nullptr){
        return nullptr;
    }
    else if(left!= nullptr and right== nullptr){
        return left;
    }
    else if(left== nullptr and right!= nullptr){
        return right;
    }
    else{
        return root;
    }
}


int main(){
//    TreeNode* root= new TreeNode(0);
//    vector_printer(findMode(root));

    TreeNode* root = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(4);

    // Construct the tree
    root->left = node5;
    root->right = node1;
    node5->left = node6;
    node5->right = node2;
    node1->left = node0;
    node1->right = node8;
    node2->left = node7;
    node2->right = node4;
    TreeNode* p = root->left;  // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 4
    TreeNode* answer = lowestCommonAncestor(root, p, q);
    cout<<answer->val;
    return 0;
}