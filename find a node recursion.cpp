/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

int indexOfNRecursive(Node *head, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    //base condition
    if(head==NULL){
        return -1;
    }
    if(head->next==NULL){
        if(head->data==n)
            return 0;
        else
            return -1;
    }
    if(head->data==n)
        return 0;
  
    
    int index=indexOfNRecursive(head->next,n);
    if(index==-1){//element is not present in the list
        if(head->data==n)
            return 0;
        else
            return -1;
    }
    else
        return index+1;
    
}


