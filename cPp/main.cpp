//
//  main.cpp
//  cPp
//
//  Created by Snow.Y.Wu on 1/13/18.
//  Copyright © 2018 rbbtsn0w. All rights reserved.
//

#include <iostream>


class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
    ~ TreeNode() {
        
    }
};



class Solution {
public:
    void inverBinaryTree(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        this->inverBinaryTree(root->left);
        this->inverBinaryTree(root->right);
    }
    ~ Solution() {
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    TreeNode *root = new TreeNode(1);//指针类型的类实例,结构指针
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    
    TreeNode instanceRoot = TreeNode(1);//实例化对象的指向,结构变量
    instanceRoot.left = new TreeNode(2);
    instanceRoot.right = new TreeNode(3);
    instanceRoot.right->left = new TreeNode(4);
    
    
    Solution *solution = new Solution();
    solution->inverBinaryTree(root);
    
    solution->inverBinaryTree(&instanceRoot);
    
    
    std::cout << "inverBinaryTree end \n";
    //指针接口的函数需要调用delete 来释放，实力化对象自动释放
    delete root;
    delete solution;
    
    std::cout << "delete end \n";
    
    
    return 0;
}
