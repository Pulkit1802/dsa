#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *insert_node(struct node *head, int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->next=head;
    if(!head) {
        head=temp;
        head->next=head;    
    }
    else {
        struct node *ptr = head;
        while(ptr->next!=head) ptr = ptr->next;
        ptr->next=temp;
    }
    return head;
}

void display(struct node *head) {
    struct node *ptr = head;
    while(ptr->next!=head) {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data;
}

int main(){
    int n,val;
    cin>>n;
    struct node *head=NULL;
    for(int i=0;i<n;i++){
        cin>>val;
        head=insert_node(head, val);
    }

    display(head);

    return 0;
}