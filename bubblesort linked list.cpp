//head is the head of the linked list
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
    node *temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
   
    for(int i=0;i<count-1;i++){
         node *current=head;
   		 node *prev=NULL;
    	 node *next=current->next;
        while(current->next!=NULL){
            
            if(current->data > next->data){
                if(prev==NULL){
                current->next=next->next;
                next->next=current;
                head=next;
                prev=next;
                next=current->next;
            }
            else{
                prev->next=next;
                current->next=next->next;
                next->next=current;
                prev=next;
                next=current->next;
            }
          }
          else{
              prev=current;
              current=current->next;
              next=current->next;
              
          }
        }
    }
    return head;
}
