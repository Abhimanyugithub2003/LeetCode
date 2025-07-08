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
bool detectcycle(node* head){
    if(head==nullptr){
        return false;
    }
    node* fast=head;
    node* slow=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<slow->data<<endl;
            return true;
        }
    }
    return false;
}
void deletecycle(node* &head){
    node* slow=head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(slow->next != fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=nullptr;
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
    insertatend(head,3);
    insertatend(head,4);
    insertatend(head,5);
    insertatend(head,6);
    insertatend(head,7);
    insertatend(head,8);
    head->next->next->next->next->next->next->next->next=head->next->next;
    cout<<detectcycle(head);
    cout<<"after deletion"<<endl;
    deletecycle(head);
    cout<<detectcycle(head);
    print(head);
}
