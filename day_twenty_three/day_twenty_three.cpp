//
// Created by 朱俊驰 on 9/11/24.
//

#include "../helper.h"
#include "../treenode.h"
//4213769
//4796231

// 1234679
// 9764321
TreeNode* invertTree(TreeNode* root) {
    stack<TreeNode*> my_stack;
    if(root){
        my_stack.push(root);
    }
    while(!my_stack.empty()){
        TreeNode* node = my_stack.top();
        my_stack.pop();
        swap(node->left,node->right);
        if(node->right){
            my_stack.push(node->right);
        }
        if(node->left){
            my_stack.push(node->left);
        }
    }
    return root;
}

vector<int> preorder_Traversal(TreeNode* root) {
    stack<TreeNode*> my_stack;
    vector<int> store;
    if(root){
        my_stack.push(root);
    }
    while(!my_stack.empty()){
        TreeNode* node = my_stack.top();
        my_stack.pop();
        store.push_back(node->val);
        if(node->right){
            my_stack.push(node->right);
        }
        if(node->left){
            my_stack.push(node->left);
        }
    }
    return store;
}
bool compare(TreeNode* left, TreeNode* right){
    if(left==nullptr and right != nullptr){return false;}
    else if(right==nullptr and left != nullptr){return false;}
    else if(left==nullptr and right == nullptr){return true;}
    else if(left->val != right->val){return false;}
    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);
    if(inside&&outside){return true;}
    return false;

}

bool isSymmetric(TreeNode* root) {
    if(root== nullptr){return true;}
    bool answer = compare(root->left,root->right);
    return answer;
}

bool isSymmetric_traversal(TreeNode* root) {
    if(root== nullptr){
        return true;
    }
    queue<TreeNode*> my_queue;
    if(root!= nullptr){
        my_queue.push(root->left);
        my_queue.push(root->right);
    }
    while (!my_queue.empty()){
        TreeNode* left = my_queue.front();
        my_queue.pop();
        TreeNode* right = my_queue.front();
        my_queue.pop();
        if(right and left){
            continue;
        }
        if(!right || !left || (right->val!=left->val)){
            return false;
        }
        TreeNode* out_left =left->left;
        TreeNode* out_right =right->right;
        TreeNode* in_left =left->right;
        TreeNode* in_right =right->left;
        my_queue.push(out_left);
        my_queue.push(out_right);
        my_queue.push(in_left);
        my_queue.push(in_right);

    }
    return true;
}

int getDepth(TreeNode* root){
    if(root== nullptr){return 0;}
    int left_depth = getDepth(root->left);
    int right_depth = getDepth(root->right);
//    if(root->left== nullptr and root->right!= nullptr){
//        right_depth+=1;
//    }
//    else if(root->right== nullptr and root->left!= nullptr){
//        left_depth+=1;
//    }
    return max(right_depth,left_depth)+1;
}

int getDepth_level_order(TreeNode* root){
    queue<TreeNode*> my_queue;
    if(root){my_queue.push(root);}
    int depth =0;
    while(!my_queue.empty()){
        int size=my_queue.size();
        for (int (i) = 0; (i) < size; ++(i)) {
            TreeNode* node = my_queue.front();
            my_queue.pop();
            if(node->left){my_queue.push(node->left);}
            if(node->right){my_queue.push(node->right);}
        }
        depth+=1;
    }
    return depth;
}
//
//int maxDepth_n_child(Node* root){
//    queue<Node*> my_queue;
//    if(root){my_queue.push(root);}
//    int counter=0;
//    while(!my_queue.empty()){
//        int size = my_queue.size();
//        for(int i=0;i<size;++i){
//            Node* node = my_queue.front();
//            my_queue.pop();
//            for(int j=0;j<node->children.size();++j){
//                if(node->children[j]!= nullptr){
//                    my_queue.push(node->children[j]);
//                }
//            }
//        }
//        counter+=1;
//    }
//    return counter;
//}
int getMinDepth(TreeNode* root){
    if(root== nullptr){return 0;}
    int left = getMinDepth(root->left);
    int right = getMinDepth(root->right);
    if(root->left==nullptr and root->right!= nullptr){
        right+=1;
    }
    if(root->right==nullptr and root->left!= nullptr){
        left+=1;
    }
    return min(right,left)+1;
}
int getMinDepth_levelOrder(TreeNode* root){
    queue<TreeNode*> my_queue;
    if(root){my_queue.push(root);}
    int depth=0;
    while (!my_queue.empty()){
        int size =my_queue.size();
        depth+=1;
        for(int i=0;i<size;++i){
            TreeNode* node = my_queue.front();
            my_queue.pop();
            if(node->left){my_queue.push(node->left);}
            if(node->right){my_queue.push(node->right);}
            if(node->left == nullptr and node->right== nullptr){return depth;}
        }
    }
    return depth;
}

// 56342
int main(){
    TreeNode* left_tree = new TreeNode(2);//, new TreeNode(1), new TreeNode(3)
    TreeNode* right_tree = new TreeNode(7, new TreeNode(6), new TreeNode(9));
    TreeNode* root = new TreeNode(4, left_tree, right_tree);
    cout<<getDepth(root)<<endl;
    cout<<getDepth_level_order(root)<<endl;
//    vector_printer(preorder_Traversal(root));
//    vector_printer(preorder_Traversal(invertTree(root)));

    return 0;
}
