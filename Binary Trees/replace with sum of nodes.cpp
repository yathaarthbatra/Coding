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
//this fn will replace the nodes also and then it will return the sum also
int sumreplace(BinaryTreeNode<int> *root,int sum){
    
    if(root == NULL)
        return 0;
    
    int right=sumreplace(root->right,sum);
    
    if(right==0){
        root->data=root->data+sum;
    }
    else{
    root->data=root->data + right;
    }
    
    int left=sumreplace(root->left,root->data);
    if(left==0)
        return root->data;
    else
        return left;
     
    
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    
    int sum=sumreplace(root,0);
    
    

}
