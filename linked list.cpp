#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        //we want pointer to the node to contain the adrress of second  node
        Node *next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

void print(Node *head){
    Node *temp = head;//temp points to the first node
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;//now temp points to the next node
    }
}
int main(){
    Node *n1 = new Node(10);
    //head pointer we will take to store the address of 1st node
    Node *head = n1;
    Node *n2 = new Node(20);
    n1->next = n2;//no they are connected
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *n5 = new Node(50);

    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    print(head);//here head is preserved if head got changed...it will not affect the main
    //head
    
}