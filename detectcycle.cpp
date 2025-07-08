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
node* middle(node* &head){
    node* slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
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
    insertatend(head,8);
    insertatend(head,4);
    print(head);
    // insertatend(head,5);
    // node* mid=middle(head);
    // cout<<mid->data;
    head->next->next->next->next->next=head->next;
    cout<<detectcycle(head);

}