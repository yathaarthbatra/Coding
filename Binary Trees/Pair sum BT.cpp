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
    	if(left) {
     		delete left;
    	}
	if(right) {
     		delete right;
    	}
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
#include<bits/stdc++.h>
//here is the main function
void helper(BinaryTreeNode<int> *root,int sum,unordered_map<int,int> &hash ){
    //this fn will print the pair sum of the binary tree
    if(root==NULL)
        return;
    
    if(hash[sum - root->data] !=0){
        cout<<min(root->data,sum-root->data)<<" "<<max(root->data,sum-root->data)<<endl;
    }
    else{
        hash[root->data]++;
    }
    helper(root->left,sum,hash);
    helper(root->right,sum,hash);
    
    
    
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	unordered_map<int,int> hash;
    helper(root,sum,hash);
    
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}
