//
// Created by 朱俊驰 on 9/12/24.
//

#include "../helper.h"
#include "../treenode.h"


void path_tracker(TreeNode* node, vector<int>&path_sum , vector<int>&path_store){
    path_store.push_back(node->val);
    if(node->left==nullptr and node->right==nullptr){
        int temp_sum=0;
        for(int i : path_store){
            temp_sum+=i;
        }
        path_sum.push_back(temp_sum);
        return;
    }

    if(node->left){
        path_tracker(node->left,path_sum, path_store);
        path_store.pop_back();
    }
    if(node->right){
        path_tracker(node->right,path_sum, path_store);
        path_store.pop_back();
    }
}

bool hasPathSum_test1(TreeNode* root, int targetSum) {
    if(root== nullptr){
        return false;
    }
    vector<int>path_sum;
    vector<int>path_store;
    path_tracker(root, path_sum, path_store);
    for(int element:path_sum){
        if(element==targetSum){return true;}
    }
    return false;
}

bool path_tracker_test2(TreeNode* root, int targetSum){
    if(root->left== nullptr and root->right== nullptr and targetSum==0){return true;}
    if(root->left== nullptr and root->right== nullptr){return false;}
    if(root->left){
        targetSum-=root->left->val;
        if(path_tracker_test2(root->left, targetSum)){return true;}
        targetSum+=root->left->val;
    }
    if(root->right){
        targetSum-=root->right->val;
        if(path_tracker_test2(root->right, targetSum)){return true;}
        targetSum+=root->right->val;
    }
    return false;
}

bool hasPathSum_test2(TreeNode* root, int targetSum) {
    if(root== nullptr){
        return false;
    }

    return path_tracker_test2(root, targetSum-root->val);
}

void traversal(TreeNode* root, int targetSum, vector<vector<int>>&store, vector<int>&each_path){
    each_path.push_back(root->val);
    if(root->right==nullptr and root->left==nullptr and targetSum==0){store.push_back(each_path);}
    if(root->right==nullptr and root->left==nullptr){return ;}
    if(root->left){
        traversal(root->left, targetSum-root->left->val, store, each_path);
        each_path.pop_back();
    }
    if(root->right){
        traversal(root->right, targetSum-root->right->val, store, each_path);
        each_path.pop_back();
    }
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>>store;
    vector<int>each_path;
    if(root==nullptr){return store;}
    traversal(root, targetSum-root->val,store,each_path);
    return store;
}

int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> my_queue;
    if(root){my_queue.push(root);}
    vector<int> store;
    int size_tracker=0;
    while(!my_queue.empty()){
        int size = my_queue.size();
        size_tracker = size;
        for(int i=0;i<size;++i){
            TreeNode* node = my_queue.front();
            my_queue.pop();
            store.push_back(node->val);
            if(node->left){my_queue.push(node->left);}
            if(node->right){my_queue.push(node->right);}
        }
    }
    return store.at(store.size()-size_tracker);
}

int getHeight(TreeNode* root) {
    if(root== nullptr){return 0;}
    int left = getHeight(root->left);
    if(left==-1){return -1;}
    int right = getHeight(root->right);
    if(right==-1){return -1;}
    if(abs(right-left)>1){
        return -1;
    } else{
        return max(right,left)+1;
    }
}

int maxDepth = INT_MIN;
void traversal(TreeNode* root, int depth, int &result){
    if(!root->right && !root->left){
        if(depth>maxDepth){
            maxDepth = depth;
            result=root->val;
        }
    }
    if(root->left){
        depth+=1;
        traversal(root->left, depth, result);
        depth-=1;
    }
    if(root->right){
        depth+=1;
        traversal(root->right, depth, result);
        depth-=1;
    }
}

int findBottomLeftValue_recursively(TreeNode* root) {
    int result;
    traversal(root,0, result);
    return result;
}

int getdepth(TreeNode* node) {
    if (node == NULL) return 0;
    int leftdepth = getdepth(node->left);       // 左
    int rightdepth = getdepth(node->right);     // 右
    int depth = 1 + max(leftdepth, rightdepth); // 中
    return depth;
}
int Depth(TreeNode* root) {
    return getdepth(root);
}

int result1;
int max_value = INT_MIN;
void GetDepth(TreeNode* root, int depth){
    if(root->left==nullptr and root->right==nullptr){
        if(depth>max_value){
            max_value = depth;
            result1 = root->val;
            return;
        }
    }
    if(root->left){
        depth+=1;
        GetDepth(root->left, depth);
        depth-=1;
    }
    if(root->right){
        depth+=1;
        GetDepth(root->right, depth);
        depth-=1;
    }

}
int findBottomLeftValue_2(TreeNode* root) {
    GetDepth(root, 0);
    return result1;
}
// 后序 左右中 9,15,7,20,3
// 中序 左中右 9,3,15,20,7
//

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.empty()){return nullptr;}
    else{
        int root_value = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(root_value);

        auto iter = find(inorder.begin(),inorder.end(),root_value);
        int index = distance(inorder.begin(), iter);

        vector<int> inorder_left = std::vector<int>(inorder.begin() , inorder.begin() + index);
        vector<int> inorder_right = std::vector<int>(inorder.begin() + index+1, inorder.end());

        postorder.resize(postorder.size()-1);
        vector<int> postorder_left = std::vector<int>(postorder.begin(), postorder.begin()+inorder_left.size());
        vector<int> postorder_right = std::vector<int>(postorder.begin()+inorder_left.size(), postorder.end());

        root->left = buildTree(inorder_left, postorder_left);
        root->right = buildTree(inorder_right, postorder_right);
        return root;
    }
}

TreeNode* buildTree_2(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty()){return nullptr;}
    int root_value = preorder[0];
    TreeNode* root = new TreeNode(root_value);

    auto iter = std::find(inorder.begin(), inorder.end(),root_value);
    int index = distance(inorder.begin(),iter);
    vector<int> inorder_left = std::vector<int>(inorder.begin(),inorder.begin()+index);
    vector<int> inorder_right = std::vector<int>(inorder.begin()+index+1,inorder.end());

    preorder.erase(preorder.begin());
    vector<int> preorder_left = std::vector<int>(preorder.begin(),preorder.begin()+inorder_left.size());
    vector<int> preorder_right = std::vector<int>(preorder.begin()+inorder_left.size(),preorder.end());

    root->left= buildTree_2(preorder_left, inorder_left);
    root->right= buildTree_2(preorder_right, inorder_right);

    return root;
}

int main(){
    TreeNode* left_tree = new TreeNode(3,  new TreeNode(4),  new TreeNode(5));
    TreeNode* right_tree = new TreeNode(2);
    TreeNode* root = new TreeNode(1, left_tree, right_tree);
    matrix_printer(levelOrder<int>(root));
    cout<<findBottomLeftValue_2(root)<<endl;

    vector<int>preorder = {3,9,20,15,7};
    vector<int>inorder = {9,3,15,20,7};
    vector<int>postorder = {9,15,7,20,3};

    TreeNode* root2 = buildTree(inorder, postorder);
    matrix_printer(levelOrder<int>(root2));
    cout<<endl;
    TreeNode* root3 = buildTree_2(preorder, inorder);
    matrix_printer(levelOrder<int>(root3));
}