#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
#include<bits/stdc++.h>
class allinone{
  	
    public:
    int minimum;
    int maximum;
    int height;// max height of the subtree
    bool isBST;
};
allinone helper(BinaryTreeNode<int> *root){
//this fn is used to return the min of the whole tree
    //max of the whole tree
    //maximum height of the tree
    //should also return that whether it is BST or not
    
    if(root == NULL){
        allinone obj;
        obj.maximum=INT_MIN;
        obj.minimum=INT_MAX;
        obj.height=0;
        obj.isBST=true;
        return obj;
    }
    if(root->left==NULL && root->right==NULL){
        allinone obj;
        obj.maximum=root->data;
        obj.minimum=root->data;
        obj.height=1;
        obj.isBST=true;
        return obj;
    }
    
    //we will go from bottom to top
    allinone left=helper(root->left);
    allinone right=helper(root->right);
    
    //now we will check the conditions
    
  	if(left.isBST==true && right.isBST==true && left.maximum < root->data && right.minimum >=root->data){
        allinone obj;
        obj.maximum=right.maximum;
        obj.minimum=left.minimum;
        obj.height=max(left.height,right.height)+1;
        obj.isBST=true;
        return obj;
    }
    //if this above condition doesnot execute it means that the 
    //whole tree including root is a BST
    allinone obj;
    obj.maximum=max(left.maximum,right.maximum);
    obj.minimum=min(left.minimum,right.minimum);
    obj.height=max(left.height,right.height);
    obj.isBST=false;
    
    
    
    return obj;
    

}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    
    allinone obj=helper(root);
    
    if(obj.isBST)
    return obj.height;
    
    else
        return max(largestBSTSubtree(root->left),largestBSTSubtree(root->right));
     

}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
