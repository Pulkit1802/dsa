#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *insert_node(struct node *head, int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->next=NULL;
    if(!head) head=temp;
    else {
        struct node *ptr = head;
        while(ptr->next) ptr = ptr->next;
        ptr->next=temp;
    }
    return head;
}

void display(struct node *head) {
    if(!head) return;
    cout<<head->data<<" ";
    display(head->next);
}

void display_reversed(struct node *head) {
    if(!head) return;
    display_reversed(head->next);
    cout<<head->data<<" ";
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
    cout<<endl;
    display_reversed(head);
    return 0;
}