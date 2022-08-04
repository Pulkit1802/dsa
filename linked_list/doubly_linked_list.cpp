#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *insert_node(struct node *head, int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->next=NULL;
    temp->prev=NULL;
    if(!head) head=temp;
    else {
        struct node *ptr = head;
        while(ptr->next) ptr = ptr->next;
        ptr->next=temp;
        temp->prev=ptr;
    }
    return head;
}


struct node *delete_node(struct node *head, int val) {
    if(head->data==val) head=head->next;
    else {
        struct node *ptr = head;
        while(ptr->next){
            if(ptr->next->data==val){
                struct node *temp=ptr->next;
                ptr->next=ptr->next->next;
                free(temp);
                break;
            }
            ptr=ptr->next;
        }
    }
    return head;
}

void display(struct node *head) {
    struct node *ptr = head;
    while(ptr->next) {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data<<endl;
    while (ptr)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
    
    
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