#include<iostream>
using namespace std;
struct node{
    node* next;
    int data;
    node(int d){
        data=d;
        next=nullptr;
    }
};

void insertatend(node* &head,int data){
    node* newnode=new node(data);
    if(head==nullptr){
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
}
void alternate(node* &head){
    node* temp=head;
    while( temp!=nullptr && temp->next!=nullptr){
        node* alt=temp->next;
        temp->next=temp->next->next;
        free(alt);
        temp=temp->next;
    }
}
void duplicate(node* &head){
    node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        if(temp->data==temp->next->data){
            node* dupl=temp->next;
            temp->next=temp->next->next;
            free(dupl);
        }else if(temp->data!=temp->next->data){
            temp=temp->next;
        }
    }
}
void duplicate2(node* &head){
    node* temp=head;
    while(temp){
        while(temp->next && temp->data==temp->next->data){
            node* dupl=temp->next;
            temp->next=temp->next->next;
            free(dupl);
        }
        temp=temp->next;
    }
}
void reverse(node* &head){
    node* curr=head;
    node* prev=nullptr;
    while(curr){
        node* nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    head=prev;
}
void print(node* head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
int main(){
    node* head=nullptr;
    insertatend(head,1);
    insertatend(head,2);
    insertatend(head,2);
    insertatend(head,3);
    insertatend(head,3);
    print(head);
    // alternate(head);
    // print(head);
    // duplicate2(head);
    reverse(head);
    print(head);

}
