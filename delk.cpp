#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int d){
        data=d;
        next=nullptr;
    }
};
void insert(node* &head,int data){
    node* newnode=new node(data);
    if(head==nullptr){
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newnode;
}
void delKend(node* &head,int k){
    node* temp=head,*ktemp=head;
    int i=0;
    while(i<k){
        i++;
        ktemp=ktemp->next;
    }
    if(ktemp==nullptr){
        node* delh=head;
        head=head->next;
        delete(delh);
    }
    while(ktemp->next){
        temp=temp->next;
        ktemp=ktemp->next;
    }
    node* curr=temp->next;
    temp->next=temp->next->next;
    delete(curr);

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
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    print(head);
    delKend(head,3);
    print(head);
}