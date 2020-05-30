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

node* arrange_LinkedList(node* head)
{
    //write your code here
    node *evenhead=NULL;
    node *oddhead=NULL;
    node *eventail=NULL;
    node *oddtail=NULL;
    node *temp=head;
    while(temp!=NULL){
        if(temp->data % 2 !=0){//it means the data is odd
            if(oddhead==NULL && oddtail==NULL){
                oddhead=oddtail=temp;
                temp=temp->next;
            }
            else{
                oddtail->next=temp;
                oddtail=oddtail->next;
                temp=temp->next;
            }
            
        }
        else{
            if(evenhead==NULL && eventail==NULL){
                evenhead=eventail=temp;
                temp=temp->next;
            }
            else{
                eventail->next=temp;
                eventail=eventail->next;
                temp=temp->next;
            }
        }
        
    }
    if(evenhead==NULL){
        oddtail->next=NULL;
        return oddhead;
    }
    else if(oddhead==NULL){
        eventail->next=NULL;
        return evenhead;
    }
    else{
        oddtail->next=evenhead;
        eventail->next=NULL;
        return oddhead;
    }
    
}
